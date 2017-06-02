/*
** tools.c for space_invader in /home/extra/Projet/Mini-projet/bootcamp-rebirth/rb_space_invader/space
** 
** Made by Extra
** Login   <gaspard.witrand@epitech.eu>
** 
** Started on  Sat Apr 15 14:57:11 2017 Extra
** Last update Sat Apr 15 15:00:47 2017 Extra
*/

#include <unistd.h>
#include <stdlib.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    ++i;
  return (i);
}

void	my_puterror(char *str)
{
  write(2, str, my_strlen(str));
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
