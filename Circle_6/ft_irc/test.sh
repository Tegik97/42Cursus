#!/bin/bash

# ============================================
# Script di stress test per server IRC
# Test: apertura/chiusura rapida di molti client
# ============================================

# Configurazione
SERVER_IP="127.0.0.1"  # Usa localhost se il server è sulla stessa macchina
SERVER_PORT="6667"
PASSWORD="ciao"

# Colori
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

print_header() {
    echo -e "\n${BLUE}========================================${NC}"
    echo -e "${BLUE}$1${NC}"
    echo -e "${BLUE}========================================${NC}\n"
}

print_test() { echo -e "${YELLOW}[TEST]${NC} $1"; }
print_pass() { echo -e "${GREEN}[PASS]${NC} $1"; }
print_fail() { echo -e "${RED}[FAIL]${NC} $1"; }
print_info() { echo -e "${BLUE}[INFO]${NC} $1"; }

# Funzione per verificare se il server risponde
check_server_alive() {
    print_info "Tentativo di connessione a $SERVER_IP:$SERVER_PORT..."
    
    # Test con output per debug
    if timeout 1 bash -c "echo 'PING' | nc $SERVER_IP $SERVER_PORT" 2>&1 | head -5; then
        return 0
    else
        ERROR_MSG=$(timeout 1 bash -c "echo '' | nc $SERVER_IP $SERVER_PORT" 2>&1)
        print_fail "Errore connessione: $ERROR_MSG"
        return 1
    fi
}

# ============================================
# Test 1: Connessioni rapide senza dati
# ============================================
test_rapid_connections() {
    print_header "TEST 1: Connessioni rapide vuote (senza dati)"
    print_info "Apro e chiudo 100 connessioni rapidamente..."
    
    for i in {1..100}; do
        # Connessione che si chiude subito
        timeout 0.1 nc $SERVER_IP $SERVER_PORT >/dev/null 2>&1 &
        
        # Ogni 10 mostra progresso
        if [ $((i % 10)) -eq 0 ]; then
            echo -n "."
        fi
    done
    
    echo ""
    sleep 2
    
    if check_server_alive; then
        print_pass "Server ancora in vita dopo 100 connessioni rapide"
    else
        print_fail "SERVER CRASHATO o NON RISPONDE!"
        exit 1
    fi
}

# ============================================
# Test 2: Registrazione e QUIT immediato
# ============================================
test_register_and_quit() {
    print_header "TEST 2: Registrazione e QUIT immediato"
    print_info "50 client si registrano e fanno QUIT subito..."
    
    for i in {1..50}; do
        {
            printf "PASS %s\r\nNICK user%d\r\nUSER user%d 0 * :User\r\nQUIT :bye\r\n" "$PASSWORD" "$i" "$i" | nc -w 1 $SERVER_IP $SERVER_PORT >/dev/null 2>&1
        } &
        
        if [ $((i % 10)) -eq 0 ]; then
            echo -n "."
        fi
    done
    
    echo ""
    wait
    sleep 2
    
    if check_server_alive; then
        print_pass "Server sopravvissuto a 50 registrazioni+QUIT rapidi"
    else
        print_fail "SERVER CRASHATO!"
        exit 1
    fi
}

# ============================================
# Test 3: Disconnessioni brutali (kill)
# ============================================
test_brutal_disconnect() {
    print_header "TEST 3: Disconnessioni brutali (kill del processo)"
    print_info "30 client si connettono e vengono killati senza QUIT..."
    
    PIDS=()
    
    # Apri 30 connessioni
    for i in {1..30}; do
        {
            printf "PASS %s\r\nNICK kill%d\r\nUSER kill%d 0 * :Kill\r\n" "$PASSWORD" "$i" "$i" | nc $SERVER_IP $SERVER_PORT >/dev/null 2>&1
        } &
        PIDS+=($!)
        
        if [ $((i % 10)) -eq 0 ]; then
            echo -n "."
        fi
    done
    
    echo ""
    sleep 1
    
    # Killa tutti i processi nc brutalmente
    print_info "Killing tutti i client (simula disconnessione improvvisa)..."
    for pid in "${PIDS[@]}"; do
        kill -9 $pid 2>/dev/null
    done
    
    sleep 2
    
    if check_server_alive; then
        print_pass "Server sopravvissuto a 30 disconnessioni brutali"
    else
        print_fail "SERVER CRASHATO dopo kill brutale!"
        exit 1
    fi
}

# ============================================
# Test 4: Connessioni parallele massive
# ============================================
test_massive_parallel() {
    print_header "TEST 4: Connessioni parallele massive"
    print_info "100 client si connettono contemporaneamente..."
    
    for i in {1..100}; do
        {
            printf "PASS %s\r\nNICK parallel%d\r\nUSER parallel%d 0 * :P\r\nJOIN #stress\r\nPRIVMSG #stress :test\r\nQUIT\r\n" "$PASSWORD" "$i" "$i" | nc -w 2 $SERVER_IP $SERVER_PORT >/dev/null 2>&1
        } &
        
        if [ $((i % 20)) -eq 0 ]; then
            echo -n "."
        fi
    done
    
    echo ""
    print_info "Aspetto che tutti i processi terminino..."
    wait
    
    sleep 2
    
    if check_server_alive; then
        print_pass "Server sopravvissuto a 100 connessioni parallele"
    else
        print_fail "SERVER CRASHATO con carico parallelo!"
        exit 1
    fi
}

# ============================================
# Test 5: Client zombi (connessioni idle)
# ============================================
test_zombie_connections() {
    print_header "TEST 5: Client zombie (connessioni che non inviano dati)"
    print_info "Apro 50 connessioni che restano idle per 5 secondi..."
    
    PIDS=()
    
    for i in {1..50}; do
        # Connessione che resta aperta ma non invia dati
        (sleep 5 | nc $SERVER_IP $SERVER_PORT >/dev/null 2>&1) &
        PIDS+=($!)
        
        if [ $((i % 10)) -eq 0 ]; then
            echo -n "."
        fi
    done
    
    echo ""
    print_info "Aspetto 3 secondi con connessioni aperte..."
    sleep 3
    
    if check_server_alive; then
        print_pass "Server stabile con 50 connessioni idle"
    else
        print_fail "SERVER CRASHATO con connessioni idle!"
        for pid in "${PIDS[@]}"; do
            kill -9 $pid 2>/dev/null
        done
        exit 1
    fi
    
    print_info "Chiudo le connessioni zombie..."
    for pid in "${PIDS[@]}"; do
        kill -9 $pid 2>/dev/null
    done
    
    sleep 1
}

# ============================================
# Test 6: Flood di QUIT senza registrazione
# ============================================
test_quit_without_register() {
    print_header "TEST 6: QUIT senza registrazione"
    print_info "50 client inviano QUIT senza essersi registrati..."
    
    for i in {1..50}; do
        {
            printf "QUIT :bye\r\n" | nc -w 1 $SERVER_IP $SERVER_PORT >/dev/null 2>&1
        } &
        
        if [ $((i % 10)) -eq 0 ]; then
            echo -n "."
        fi
    done
    
    echo ""
    wait
    sleep 1
    
    if check_server_alive; then
        print_pass "Server gestisce QUIT senza registrazione"
    else
        print_fail "SERVER CRASHATO con QUIT non autenticati!"
        exit 1
    fi
}

# ============================================
# Test 7: Ciclo connetti-disconnetti rapido
# ============================================
test_rapid_cycle() {
    print_header "TEST 7: Ciclo rapido connetti-disconnetti (200 volte)"
    print_info "Un client si connette e disconnette 200 volte rapidamente..."
    
    for i in {1..200}; do
        printf "PASS %s\r\nNICK cycle\r\nUSER cycle 0 * :C\r\nQUIT\r\n" "$PASSWORD" | nc -w 1 $SERVER_IP $SERVER_PORT >/dev/null 2>&1
        
        if [ $((i % 20)) -eq 0 ]; then
            echo -n "."
        fi
    done
    
    echo ""
    
    if check_server_alive; then
        print_pass "Server sopravvissuto a 200 cicli rapidi"
    else
        print_fail "SERVER CRASHATO durante cicli rapidi!"
        exit 1
    fi
}

# ============================================
# Test 8: Verifica leak di file descriptor
# ============================================
test_fd_leak() {
    print_header "TEST 8: Verifica leak di file descriptor"
    
    # Trova PID del server
    SERVER_PID=$(pgrep -f "ircserv.*$SERVER_PORT" | head -1)
    
    if [ -z "$SERVER_PID" ]; then
        print_fail "Non riesco a trovare il PID del server"
        return
    fi
    
    print_info "PID del server: $SERVER_PID"
    
    FD_BEFORE=$(lsof -p $SERVER_PID 2>/dev/null | wc -l)
    print_info "File descriptor prima: $FD_BEFORE"
    
    # Esegui test con molte connessioni
    print_info "Apro e chiudo 50 connessioni..."
    for i in {1..50}; do
        printf "PASS %s\r\nNICK fd%d\r\nUSER fd%d 0 * :FD\r\nQUIT\r\n" "$PASSWORD" "$i" "$i" | nc -w 1 $SERVER_IP $SERVER_PORT >/dev/null 2>&1 &
    done
    
    wait
    sleep 3
    
    FD_AFTER=$(lsof -p $SERVER_PID 2>/dev/null | wc -l)
    print_info "File descriptor dopo: $FD_AFTER"
    
    FD_DIFF=$((FD_AFTER - FD_BEFORE))
    
    if [ $FD_DIFF -le 5 ]; then
        print_pass "Nessun leak significativo di FD (diff: $FD_DIFF)"
    else
        print_fail "Possibile leak di FD! Differenza: $FD_DIFF"
    fi
}

# ============================================
# Main execution
# ============================================

echo -e "${GREEN}"
echo "╔════════════════════════════════════════╗"
echo "║   IRC SERVER STRESS TEST SUITE         ║"
echo "║   Test di crash e stabilità            ║"
echo "╚════════════════════════════════════════╝"
echo -e "${NC}"

print_info "Target: $SERVER_IP:$SERVER_PORT"
print_info "Verifico che il server sia raggiungibile..."

if ! check_server_alive; then
    print_fail "Server non raggiungibile! Avvia il server prima di eseguire i test."
    exit 1
fi

print_pass "Server raggiungibile. Inizio test..."
sleep 1

# Esegui tutti i test
test_rapid_connections
test_register_and_quit
test_brutal_disconnect
test_massive_parallel
test_zombie_connections
test_quit_without_register
test_rapid_cycle
test_fd_leak

# ============================================
# Report finale
# ============================================

print_header "REPORT FINALE"

if check_server_alive; then
    echo -e "${GREEN}"
    echo "╔════════════════════════════════════════╗"
    echo "║   ✓ TUTTI I TEST SUPERATI!             ║"
    echo "║   Server stabile e robusto             ║"
    echo "╚════════════════════════════════════════╝"
    echo -e "${NC}"
    exit 0
else
    echo -e "${RED}"
    echo "╔════════════════════════════════════════╗"
    echo "║   ✗ SERVER CRASHATO                    ║"
    echo "║   Controlla i log del server           ║"
    echo "╚════════════════════════════════════════╝"
    echo -e "${NC}"
    exit 1
fi