/*
** main.c for SpaceInvader in /home/remi.verny/TaffPingouin/SpaceInvader
** 
** Made by Remi Verny
** Login   <remi.verny@epitech.net>
** 
** Started on  Sat Apr 15 12:21:37 2017 Remi Verny
** Last update Sun Apr 16 11:16:59 2017 Remi Verny
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

int	ncurses_init()
{
  if (initscr() == NULL)
    return (NCURSES_ERROR);
  if (keypad(stdscr, TRUE) == ERR)
    return (NCURSES_ERROR);
  if (curs_set(0) == ERR)
    return (NCURSES_ERROR);
  if (noecho() == ERR)
    return (NCURSES_ERROR);
  return (0);
}

void                    set_canon(int i)
{
  static struct termios old_term;
  static struct termios new_term;

  if (i == 0)
    {
      ioctl(0, TCGETS, &old_term);
      ioctl(0, TCGETS, &new_term);
      new_term.c_lflag &= ~ECHO;
      new_term.c_lflag &= ~ICANON;
      ioctl(0, TCSETS, &new_term);
    }
  if (i == 1)
    ioctl(0, TCSETS, &old_term);
}

int	main(int ac, char **av)
{
  t_vars	*vars;
  char		**map;

  if (ac != 2)
    return (ARG_ERROR);
  if ((vars = get_vars(av[1])) == NULL)
    return (84);
  map = tab_create(vars);
  if (ncurses_init() == NCURSES_ERROR)
    return (NCURSES_ERROR);
  moving(map, vars);
  clear();
  endwin();
  return (0);
}
