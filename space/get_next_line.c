/*
** get_next_line.c for getnextline in /home/extra/Projet/Mini-projet/GetNextLine
** 
** Made by Extra
** Login   <gaspard.witrand@epitech.eu>
** 
** Started on  Thu Jan  5 14:43:45 2017 Extra
** Last update Mon Apr  3 17:52:20 2017 Extra
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*rest(char buff[READ_SIZE], char *line)
{
  int	i;
  int	j;

  i = 0;
  while (buff[i] && buff[i] != '\n')
    ++i;
  if (buff[i] == '\n')
    ++i;
  j = 0;
  while (buff[i])
    {
      buff[j] = buff[i];
      ++i;
      ++j;
    }
  buff[j] = '\0';
  return (line);
}

char	*malloc_it(char *dest, int *index, int size)
{
  char	*str;
  int	i;

  if ((str = malloc(*index + 1 + size)) == NULL)
    return (NULL);
  i = 0;
  if (dest != NULL)
    {
      while (dest[i])
	{
	  str[i] = dest[i];
	  ++i;
	}
    }
  *index = i;
  str[i] = '\0';
  free(dest);
  return (str);
}

void	get_line(char **dest, char buff[READ_SIZE], int *index, int size)
{
  int	i;

  if ((*dest = malloc_it(*dest, index, size)) == NULL)
    {
      *index = -1;
      return ;
    }
  i = 0;
  while (buff[i] && buff[i] != '\n')
    {
      (*dest)[*index] = buff[i];
      ++(*index);
      ++i;
    }
  (*dest)[*index] = '\0';
}

int	newline(char **line, char buff[READ_SIZE], int *len, int *index)
{
  int	i;
  int	max;

  max = 0;
  i = 0;
  while (buff[i])
    {
      if (buff[i] == '\n')
	{
	  ++max;
	  break ;
	}
      ++i;
    }
  *len = i;
  if (max != 0)
    get_line(line, buff, len, *index);
  return (*index == -1 ? -1 : max);
}

char		*get_next_line(const int fd)
{
  static char	buff[READ_SIZE];
  char		*line;
  int		index;
  int		size;
  int		len;

  line = NULL;
  size = 0;
  len = 0;
  if (buff[0] && newline(&line, buff, &len, &index) == 1)
    return (rest(buff, line));
  get_line(&line, buff, &index, len);
  while ((size = read(fd, buff, READ_SIZE)) > 0)
    {
      buff[size] = '\0';
      if (newline(&line, buff, &len, &index) == 1)
	break ;
      get_line(&line, buff, &index, len);
    }
  if (size == -1 || (size == 0 && buff[0] == 0 && line[0] == 0))
    {
      free(line);
      return (NULL);
    }
  return (rest(buff, line));
}
