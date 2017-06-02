/*
** tab_create.c for space_invader in /home/extra/Projet/Mini-projet/bootcamp-rebirth/rb_space_invader/space
** 
** Made by Extra
** Login   <gaspard.witrand@epitech.eu>
** 
** Started on  Sat Apr 15 16:05:06 2017 Extra
** Last update Sat Apr 15 17:09:30 2017 Remi Verny
*/

#include <ncurses.h>
#include <stdlib.h>
#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <term.h>
#include <sys/ioctl.h>
#include "my.h"
#include "myspace.h"
#include "mystruct.h"
#include "mydefine.h"
#include <string.h>

char	**tab_create(t_vars *vars)
{
  char	**map;
  int	i;
  int	j;

  i = 0;
  if ((map = malloc(sizeof(char *) * (vars->x + 1))) == NULL)
    return (NULL);
  while (i < vars->x)
    {
      if ((map[i] = malloc(sizeof(char) * (vars->y + 1))) == NULL)
	return (NULL);
      j = 0;
      while (j < vars->y)
	{
	  map[i][j] = ' ';
	  ++j;
	}
      map[i][j] = '\0';
      ++i;
    }
  map[i - 2][vars->y / 2] = vars->player;
  map[i] = '\0';
  i = 0;
  while (map[i] != '\0')
    {
      if (i == 0)
	{
	  j = -1;
	  while (map[i][++j] != '\0')
	    map[i][j] = '#';
	}
      map[i][0] = '#';
      map[i][strlen(map[i]) - 1] = '#';
      ++i;
    }
  j = -1;
  while (map[i - 1][++j] != '\0')
    {
      map[i - 1][j] = '#';
    }
  return (map);
}
