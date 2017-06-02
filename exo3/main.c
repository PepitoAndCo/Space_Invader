/*
** main.c for SpaceInvader in /home/remi.verny/TaffPingouin/SpaceInvader
** 
** Made by Remi Verny
** Login   <remi.verny@epitech.net>
** 
** Started on  Sat Apr 15 12:21:37 2017 Remi Verny
** Last update Sat Apr 15 13:00:05 2017 Remi Verny
*/

#include <ncurses.h>

#define NCURSES_ERROR	84

/*
** Centrer correctement
*/

void	display()
{
  start_color();
  init_pair(1, COLOR_BLUE, COLOR_WHITE);
  attron(COLOR_PAIR(1) | A_BOLD | A_UNDERLINE);
  mvprintw(LINES / 2, (COLS / 2 - 6), "Hello World!");
  attroff(COLOR_PAIR(1) | A_BOLD | A_UNDERLINE);
}

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
  display();
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
