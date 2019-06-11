/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 03:00:47 by mobounya          #+#    #+#             */
/*   Updated: 2019/06/12 00:36:59 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#define TETRIS_SIZE 20

typedef struct  s_tetris 
{
        char tetris[4][6];
        struct s_tetris *next;
}       t_tetris;

int     ft_is_Tetrimino_valid(int fd)
{
    char            str[TETRIS_SIZE + 1];
    int             re;
    int             i;
    unsigned int    hashtags;
    unsigned int    points;

    while ((re = read(fd, str, TETRIS_SIZE)) > 0)
    {
        hashtags = 0;
        points = 0;
        i = 0;
        
        if (re < 20)
            return 0;
        str[20] = '\0';
        if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19] != '\n')
            return 0;
        while (str[i])
        {
            if (str[i] == '#')
                hashtags++;
            if (str[i] == '.')
                points++;
            i++;
        }
        if (hashtags != 4 || points != 12)
            return 0;
        re = read(fd, str, 1);
        if (re == -1)
            return 0;
        if (re == 0)
            break;
        if (str[0] != '\n')
            return 0;
    }
    return 1;
}

t_tetris    *ft_readtetris(int fd)
{
    int             re;
    char            str[TETRIS_SIZE + 1];
    t_tetris        *head;
    int             i;
    int             k;
    int             j; 
    t_tetris        *temp;

    head = NULL;
    while ((re = read(fd, str, TETRIS_SIZE)) > 0)
    {
        if (re == -1)
            exit(1);
        str[re] = '\0';
        if (!(head = malloc(sizeof(t_tetris))))
            return (NULL);
        j = 0;
        i = 0;
        while (str[i] != '\0')
        {
            k = 0;
            while (str[i] != '\n')
            {
                head->tetris[j][k] = str[i];
                k++;
                i++;
            }
            head->tetris[j][k++] = str[i];
            head->tetris[j][k] = '\0';
            i++;
            j++;
        }
        printf("%s", head->tetris[0]);
        read(fd, str, 1);
        head = head->next;
    }
    return head;
}

int     main(int argc, char **argv)
{
    int fd;
    t_tetris *head;
    int re;

    fd = open(argv[1], O_RDONLY);
    if (argc != 2)
    {
        write(1, "usage: fillit tetriminos_file\n", 30);
        return -1;
    }
    if (ft_is_Tetrimino_valid(fd) == 0)
        return 0;
    fd = open(argv[1], O_RDONLY); 
    ft_readtetris(fd);
}
