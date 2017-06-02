/*
** main.c for SpaceInvader in /home/remi.verny/TaffPingouin/SpaceInvader
** 
** Made by Remi Verny
** Login   <remi.verny@epitech.net>
** 
** Started on  Sat Apr 15 12:21:37 2017 Remi Verny
** Last update Sat Apr 15 13:14:44 2017 Remi Verny
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
}

void	display_loop()
{
  int	key;
  int	col;

  col = COLS / 2 - 6;
  while (1)
    {
      key = getch();
      refresh();
      if (key == KEY_RIGHT && col != COLS - 12)
	{
	  clear();
	  mvprintw(LINES / 2, ++col, "Hello World!");
	}
      if (key == KEY_LEFT && col != 0)
	{
	  clear();
	  mvprintw(LINES / 2, --col, "Hello World!");
	}
      if (key == 27)
	break ;
    }
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
  display_loop();
  clear();
  attroff(COLOR_PAIR(1) | A_BOLD | A_UNDERLINE);
  endwin();
  return (0);
}
