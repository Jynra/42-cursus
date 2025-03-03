/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:06:38 by ellucas           #+#    #+#             */
/*   Updated: 2025/03/03 15:51:12 by ellucas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Initialise une pile vide
t_stack *init_stack(void)
{
    t_stack *stack;
    
    stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->top = NULL;
    stack->bottom = NULL;
    stack->size = 0;
    return (stack);
}

// Ajoute un élément au sommet de la pile
int push_to_stack(t_stack *stack, int value)
{
    t_node *new_node;
    
    new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return (0);
    new_node->value = value;
    new_node->prev = NULL;
    
    if (stack->size == 0)
    {
        new_node->next = NULL;
        stack->top = new_node;
        stack->bottom = new_node;
    }
    else
    {
        new_node->next = stack->top;
        stack->top->prev = new_node;
        stack->top = new_node;
    }
    stack->size++;
    return (1);
}

// Affiche les éléments de la pile
void print_stack(t_stack *stack)
{
    t_node *current;
    
    if (!stack || !stack->top)
    {
        printf("Pile vide\n");
        return;
    }
    
    current = stack->top;
    printf("Pile (du haut vers le bas): ");
    while (current)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// Libère la mémoire de la pile
void free_stack(t_stack *stack)
{
    t_node *current;
    t_node *next;
    
    if (!stack)
        return;
    
    current = stack->top;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    int i;
    int value;
    
    if (argc < 3)
    {
        printf("Usage: %s <nombre1> <nombre2> ...\n", argv[0]);
        return (1);
    }
    
    // Initialisation de la pile
    stack_a = init_stack();
    if (!stack_a)
        return (1);
    
    // Remplissage de la pile avec les arguments (en ordre inverse car push met au sommet)
    for (i = argc - 1; i > 0; i--)
    {
        value = atoi(argv[i]);
        if (!push_to_stack(stack_a, value))
        {
            printf("Erreur lors de l'ajout à la pile\n");
            free_stack(stack_a);
            return (1);
        }
    }
    
    // Affichage avant swap
    printf("Avant sa:\n");
    print_stack(stack_a);
    
    // Appliquer sa
    sa(stack_a);
    
    // Affichage après swap
    printf("Après sa:\n");
    print_stack(stack_a);
    
    // Libération de la mémoire
    free_stack(stack_a);
    
    return (0);
}

/*
int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int i;
    int value;
    
    if (argc < 3)
    {
        printf("Usage: %s <nombre1> <nombre2> ...\n", argv[0]);
        return (1);
    }
    
    // Initialisation des piles
    stack_a = init_stack();
    stack_b = init_stack();
    if (!stack_a || !stack_b)
    {
        if (stack_a)
            free_stack(stack_a);
        if (stack_b)
            free_stack(stack_b);
        return (1);
    }
    
    // Remplissage de la pile a avec les arguments (en ordre inverse)
    for (i = argc - 1; i > 0; i--)
    {
        value = atoi(argv[i]);
        if (!push_to_stack(stack_a, value))
        {
            printf("Erreur lors de l'ajout à la pile\n");
            free_stack(stack_a);
            free_stack(stack_b);
            return (1);
        }
    }
    
    // Affichage initial
    printf("État initial:\n");
    printf("stack_a: ");
    print_stack(stack_a);
    printf("stack_b: ");
    print_stack(stack_b);
    
    // Test de sa
    printf("\nAprès sa:\n");
    sa(stack_a);
    printf("stack_a: ");
    print_stack(stack_a);
    
    // Ajoutons quelques valeurs à stack_b pour tester sb
    push_to_stack(stack_b, 10);
    push_to_stack(stack_b, 20);
    
    printf("\nAvant sb:\n");
    printf("stack_b: ");
    print_stack(stack_b);
    
    // Test de sb
    sb(stack_b);
    printf("Après sb:\n");
    printf("stack_b: ");
    print_stack(stack_b);
    
    // Réinitialisons les piles pour tester sab (ss)
    free_stack(stack_a);
    free_stack(stack_b);
    stack_a = init_stack();
    stack_b = init_stack();
    
    push_to_stack(stack_a, 3);
    push_to_stack(stack_a, 2);
    push_to_stack(stack_a, 1);
    
    push_to_stack(stack_b, 30);
    push_to_stack(stack_b, 20);
    push_to_stack(stack_b, 10);
    
    printf("\nAvant sab (ss):\n");
    printf("stack_a: ");
    print_stack(stack_a);
    printf("stack_b: ");
    print_stack(stack_b);
    
    // Test de sab (ss)
    ss(stack_a, stack_b);
    printf("Après ss:\n");
    printf("stack_a: ");
    print_stack(stack_a);
    printf("stack_b: ");
    print_stack(stack_b);
    
    // Libération de la mémoire
    free_stack(stack_a);
    free_stack(stack_b);
    
    return (0);
}
*/