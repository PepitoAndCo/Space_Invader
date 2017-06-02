/*
** mytetris.h for tetris in /home/remi.verny/UnixSystem/PSU_2016_tetris
** 
** Made by Remi Verny
** Login   <remi.verny@epitech.net>
** 
** Started on  Mon Feb 27 13:26:14 2017 Remi Verny
** Last update Sat Apr 15 16:48:36 2017 Remi Verny
*/

#ifndef MYTETRIS_H_
# define MYTETRIS_H_

# include "mystruct.h"

t_vars	*get_vars(char *file);
int	my_strlen(char *str);
void	my_puterror(char *str);
void	my_putstr(char *str);
int	get_rand();
void	moving(char **map, t_vars *vars);
char	**tab_create(t_vars *vars);

#endif /* MYTETRIS_H_ */
