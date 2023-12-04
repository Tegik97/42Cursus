/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menny <menny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:04:37 by mchiaram          #+#    #+#             */
/*   Updated: 2023/10/24 12:32:16 by menny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void del(void *content)
{
    free(content);
}

void *transform(void *content)
{
    int *number = (int *)content;
    int *result = (int *)malloc(sizeof(int));
    if (result)
        *result = (*number) * 2;
    return result;
}

int main()
{
    // Creazione di una lista di esempio
    t_list *list = NULL;
    for (int i = 1; i <= 5; i++)
    {
        int *number = (int *)malloc(sizeof(int));
        *number = i;
        t_list *new_node = ft_lstnew(number);
        if (new_node)
        {
            new_node->next = list;
            list = new_node;
        }
        else
        {
            // Gestione degli errori di allocazione di memoria
            ft_lstclear(&list, &del);
            printf("Errore durante l'allocazione della memoria.\n");
            return 1;
        }
    }

    // Chiamata a ft_lstmap per applicare la funzione di trasformazione
    t_list *new_list = ft_lstmap(list, &transform, &del);

    // Stampa la lista risultante
    printf("Lista originale:\n");
    t_list *current = list;
    while (current)
    {
        int *number = (int *)current->content;
        printf("%d ", *number);
        current = current->next;
    }
    printf("\n");

    printf("Lista risultante:\n");
    current = new_list;
    while (current)
    {
        int *number = (int *)current->content;
        if (number) {
            printf("%d ", *number);
        }
        current = current->next;
    }
    printf("\n");

    // Deallocazione della memoria
    ft_lstclear(&list, &del);
    ft_lstclear(&new_list, &del);

    return 0;
}
