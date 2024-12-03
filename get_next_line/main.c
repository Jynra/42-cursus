/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:53:31 by ellucas           #+#    #+#             */
/*   Updated: 2024/12/03 12:53:56 by ellucas          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    // Test 1: Lecture d'un fichier texte
    fd = open("test_file.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening test_file.txt");
        return (1);
    }
    printf("== Reading from test_file.txt ==\n");
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // Affiche la ligne retournée
        free(line);
    }
    close(fd);

    // Test 2: Lecture d'un descripteur invalide
    printf("\n== Invalid FD Test ==\n");
    line = get_next_line(-1);
    if (!line)
        printf("Returned NULL as expected for invalid FD\n");

    // Test 3: Lecture de l'entrée standard (Ctrl+D pour terminer)
    printf("\n== Reading from stdin (Enter text, Ctrl+D to end) ==\n");
    while ((line = get_next_line(0)) != NULL)
    {
        printf("You entered: %s", line);
        free(line);
    }

    // Test 4: Lecture avec des BUFFER_SIZE extrêmes
    printf("\n== Extreme BUFFER_SIZE Tests (adjust BUFFER_SIZE at compile time) ==\n");
    fd = open("test_file.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening test_file.txt");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // Affiche la ligne retournée
        free(line);
    }
    close(fd);

    return (0);
}

