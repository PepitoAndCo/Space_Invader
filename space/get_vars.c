/*
** get_vars.c for space_invaders in /home/extra/Projet/Mini-projet/bootcamp-rebirth/rb_space_invader/space
** 
** Made by Extra
** Login   <gaspard.witrand@epitech.eu>
** 
** Started on  Sat Apr 15 14:54:20 2017 Extra
** Last update Sat Apr 15 15:57:40 2017 Extra
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "myspace.h"
#include "mydefine.h"
#include "mystruct.h"
#include "get_next_line.h"

int	check_map(char *str)
{
  int	i;
  int	coma;

  i = 0;
  coma = 0;
  while (str[i])
    {
      if (str[i] == ',')
	++coma;
      else if (str[i] < '0' || str[i] > '9')
	return (1);
      ++i;
    }
  if (coma != 1)
    return (1);
  return (0);
}

t_vars	*get_vars(char *file)
{
  t_vars *vars;
  char	*str;
  int	fd;
  int	count;
  int	i;

  count = 0;
  i = 0;
  if ((vars = malloc(sizeof(t_vars))) == NULL)
    {
      my_puterror(MALLOC_MSG);
      return (NULL);
    }
  //First check
  if ((fd = open(file, O_RDONLY)) == -1)
    {
      my_puterror(OPEN_MSG);
      return (NULL);
    }
  while ((str = get_next_line(fd)) != NULL)
    {
      free(str);
      ++count;
    }
  if (count != 3)
    {
      my_puterror(ERROR_FILE);
      return (NULL);
    }
  if ((close(fd)) == -1)
    {
      my_puterror(CLOSE_MSG);
      return (NULL);
    }

  //Values catch
  if ((fd = open(file, O_RDONLY)) == -1)
    {
      my_puterror(OPEN_MSG);
      return (NULL);
    }
  if ((str = get_next_line(fd)) == NULL)
    {
      my_puterror(READ_MSG);
      return (NULL);
    }
  if (my_strlen(str) != 1)
    {
      my_puterror("Error on player character line\n");
      return (NULL);
    }
  vars->player = str[0];
  free(str);

  if ((str = get_next_line(fd)) == NULL)
    {
      my_puterror(READ_MSG);
      return (NULL);
    }
  if (my_strlen(str) != 1)
    {
      my_puterror("Error on ennemy character line\n");
      return (NULL);
    }
  vars->ennemy = str[0];
  free(str);

  //Map size
  if ((str = get_next_line(fd)) == NULL)
    {
      my_puterror(READ_MSG);
      return (NULL);
    }
  if (my_strlen(str) < 3)
    {
      my_puterror("Error map size line\n");
      return (NULL);
    }
  if ((check_map(str)) == 1)
    {
      my_puterror(MAP_MSG);
      return (NULL);
    }
  if ((vars->x = atoi(str)) < 1)
    {
      my_puterror("Error on map X\n");
      return (NULL);
    }
  while (str[i] && str[i] != ',')
    ++i;
  if (i == 0)
    {
      my_puterror(MAP_MSG);
      return (NULL);
    }
  ++i;
  if ((vars->y = atoi(&str[i])) < 1)
    {
      my_puterror("Error on map X\n");
      return (NULL);
    }
  free(str);
  if ((close(fd)) == -1)
    {
      my_puterror(CLOSE_MSG);
      return (NULL);
    }
  return (vars);
}
