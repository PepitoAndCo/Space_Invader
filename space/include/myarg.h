/*
** myarg.h for Printf in /home/remi.verny/UnixSystem/Printf
** 
** Made by Remi Verny
** Login   <remi.verny@epitech.net>
** 
** Started on  Sat Nov 12 12:33:47 2016 Remi Verny
** Last update Sat Feb 18 13:47:02 2017 Remi Verny
*/

#ifndef MYARG_H_
# define MYARG_H_

# include <stdarg.h>

typedef struct	s_mods
{
  char		*flags;
  char		*width;
  char		*precision;
  int		modifiers;
}		t_mods;

t_mods		*filling_struct(char *str, int *a, va_list ap);

#endif /* MYARG_H_ */
