/*
** main.c for SpaceInvader in /home/remi.verny/TaffPingouin/SpaceInvader
** 
** Made by Remi Verny
** Login   <remi.verny@epitech.net>
** 
** Started on  Sat Apr 15 12:21:37 2017 Remi Verny
** Last update Sat Apr 15 13:18:41 2017 Remi Verny
*/

#include <ncurses.h>

#define NCURSES_ERROR	84

/*
** Centrer correctement
*/
int	main(__attribute__((unused)) int ac, __attribute__((unused)) char **av)
{
  if (initscr() == NULL)
    return (NCURSES_ERROR);
  if (keypad(stdscr, TRUE) == ERR)
    return (NCURSES_ERROR);
  if (curs_set(0) == ERR)
    return (NCURSES_ERROR);
  if (noecho() == ERR)
    return (NCURSES_ERROR);
  mvprintw(LINES / 2, (COLS / 2 - 6), "Hello World!");
  while (1)
    {
      refresh();
      if (getch() == 27)
	break ;
    }
  clear();
  endwin();
  return (0);
}
