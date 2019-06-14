/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 03:00:47 by mobounya          #+#    #+#             */
/*   Updated: 2019/06/14 23:12:13 by mobounya         ###   ########.fr       */
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

void    ft_tetristolist(char *str, t_tetris *list)
{
    int         k;
    int         j;

    j = 0;
    while (*str != '\0')
    {
        k = 0;
        while (*str != '\n')
        {
           list->tetris[j][k] = *str;
            k++;
            str++;
        }
        list->tetris[j][k++] = *str;
        list->tetris[j][k] = '\0';
        str++;
        j++;
    }
}

int     ft_is_format_valid(char *str)
{
    int     i;
    int     hashtags;
    int     points;

    i = 0;
    hashtags = 0;
    points = 0;
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
    return 1;
}
int     ft_is_tetrimino_valid(t_tetris *lst)
{
    int     i;
    int     j;
    unsigned int    sides;

    i = 0;
    j = 0;
    sides = 0;
    while (j < 4)
    {
        i++;
        j++;
    }

    return 0;
}

int    ft_readtetris(int fd, t_tetris *head)
{
    char            str[TETRIS_SIZE + 1];
    int             re;

    while ((re = read(fd, str, TETRIS_SIZE)) > 0)
    {
        if (re < 20)
            return 0;
        str[20] = '\0';
        if (ft_is_format_valid(str) == 0)
            return 0;
        ft_tetristolist(str, head);
        re = read(fd, str, 1);
        if (re == -1)
            return 0;
        if (re == 0)
            break;
        if (str[0] != '\n')
            return 0;
        head->next = malloc(sizeof(t_tetris));
        head = head->next;
    }
    return 1;
}
void    ft_freelst(t_tetris *head)
{
    t_tetris    *temp;

    while(head != NULL)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
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
    head = malloc(sizeof(t_tetris));
    if (ft_readtetris(fd, head) == 0)
    {
        printf("Error\n");
        ft_freelst(head);
        return 0;
    }
    
    while(head)
    {
        printf("%s", head->tetris[0]);
        printf("%s", head->tetris[1]);
        printf("%s", head->tetris[2]);
        printf("%s", head->tetris[3]);
        printf("======================\n");
        head = head->next;
    }

}
