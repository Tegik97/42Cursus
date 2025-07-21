#include <iostream>
#include "Point.hpp"

int main(void)
{
    std::cout << "=== Test BSP (Binary Space Partitioning) ===" << std::endl;
    
    // Definisco un triangolo: A(0,0), B(4,0), C(2,3)
    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(2.0f, 3.0f);
    
    std::cout << "\nTriangolo: A(0,0), B(4,0), C(2,3)" << std::endl;
    
    // Test 1: Punto chiaramente interno
    Point inside(2.0f, 1.0f);
    std::cout << "Punto (2,1) interno: " << (bsp(a, b, c, inside) ? "TRUE" : "FALSE") << std::endl;
    
    // Test 2: Punto chiaramente esterno
    Point outside(5.0f, 5.0f);
    std::cout << "Punto (5,5) esterno: " << (bsp(a, b, c, outside) ? "TRUE" : "FALSE") << std::endl;
    
    // Test 3: Punto su un vertice (dovrebbe essere FALSE)
    Point vertex(0.0f, 0.0f);
    std::cout << "Punto (0,0) vertice: " << (bsp(a, b, c, vertex) ? "TRUE" : "FALSE") << std::endl;
    
    // Test 4: Punto su un lato (dovrebbe essere FALSE)
    Point onEdge(2.0f, 0.0f);
    std::cout << "Punto (2,0) sul lato: " << (bsp(a, b, c, onEdge) ? "TRUE" : "FALSE") << std::endl;
    
    // Test 5: Altri punti interni
    Point inside2(1.5f, 0.5f);
    std::cout << "Punto (1.5,0.5) interno: " << (bsp(a, b, c, inside2) ? "TRUE" : "FALSE") << std::endl;
    
    Point inside3(2.5f, 1.5f);
    std::cout << "Punto (2.5,1.5) interno: " << (bsp(a, b, c, inside3) ? "TRUE" : "FALSE") << std::endl;
    
    // Test 6: Altri punti esterni
    Point outside2(-1.0f, 1.0f);
    std::cout << "Punto (-1,1) esterno: " << (bsp(a, b, c, outside2) ? "TRUE" : "FALSE") << std::endl;
    
    Point outside3(2.0f, 4.0f);
    std::cout << "Punto (2,4) esterno: " << (bsp(a, b, c, outside3) ? "TRUE" : "FALSE") << std::endl;
    
    std::cout << "\n=== Test con triangolo degenere ===" << std::endl;
    
    // Test 7: Triangolo degenere (tutti i punti su una linea)
    Point d1(0.0f, 0.0f);
    Point d2(2.0f, 0.0f);
    Point d3(4.0f, 0.0f);
    Point testPoint(1.0f, 1.0f);
    
    std::cout << "Triangolo degenere con punto (1,1): " << (bsp(d1, d2, d3, testPoint) ? "TRUE" : "FALSE") << std::endl;
    
    return 0;
}