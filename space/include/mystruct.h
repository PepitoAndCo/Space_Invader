/*
** mystruct.h for BS tetris in /home/remi.verny/UnixSystem/PSU_2016_tetris/bootstrap
** 
** Made by Remi Verny
** Login   <remi.verny@epitech.net>
** 
** Started on  Mon Feb 20 11:26:36 2017 Remi Verny
** Last update Sat Apr 15 15:01:03 2017 Extra
*/

#ifndef MYSTRUCT_H_
# define MYSTRUCT_H_

# include <ncurses.h>

typedef struct	s_vars
{
  char		player;
  char		ennemy;
  int		x;
  int		y;
}		t_vars;

#endif /* MYSTRUCT_H_ */
