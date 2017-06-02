/*
** moving.c for SpaceInvader in /home/remi.verny/TaffPingouin/SpaceInvader/rb_space_invader/space
** 
** Made by Remi Verny
** Login   <remi.verny@epitech.net>
** 
** Started on  Sat Apr 15 14:55:30 2017 Remi Verny
** Last update Mon Apr 17 11:25:48 2017 Remi Verny
*/

#include <ncurses.h>
#include <stdlib.h>
#include <math.h>
#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <term.h>
#include <sys/ioctl.h>
#include "my.h"
#include "myspace.h"
#include "mystruct.h"
#include "mydefine.h"

int	perso(char **map, t_vars *vars)
{
  int	i;
  int	j;

  i = -1;
  while (map[++i] != '\0')
    {
      j = -1;
      while (map[i][++j] != '\0')
	{
	  if (map[i][j] == vars->player)
	    return (0);
	}
    }
  return (-1);
}

void                    change_term(int i)
{
  static struct termios old_term;
  static struct termios new_term;

  if (i == 0)
    {
      ioctl(0, TCGETS, &old_term);
      ioctl(0, TCGETS, &new_term);
      new_term.c_lflag &= ~ECHO;
      new_term.c_cc[VMIN] = 0;
      new_term.c_cc[VTIME] = 1;
      ioctl(0, TCSETS, &new_term);
    }
  if (i == 1)
    ioctl(0, TCSETS, &old_term);
}

void	go_right(char **map, t_vars *vars)
{
  int	i;
  int	j;

  i = -1;
  while (map[++i] != '\0');
  i -= 2;
  j = -1;
  while (map[i][++j] != '\0')
    {
      if (map[i][j] == vars->player && map[i][j + 1] != '#'
	  && map[i][j + 1] != vars->ennemy)
	{
	  map[i][j] = ' ';
	  map[i][j + 1] = vars->player;
	  return ;
	}
    }
}

void	go_left(char **map, t_vars *vars)
{
  int	i;
  int	j;

  i = -1;
  j = -1;
  while (map[++i] != '\0');
  i -= 2;
  while (map[i][++j] != '\0')
    {
      if (map[i][j] == vars->player && j - 1 > 0 )
	{
	  map[i][j] = ' ';
	  map[i][j - 1] = vars->player;
	}
    }
}

void	shoot(char **map, t_vars *vars)
{
  int	i;
  int	j;

  i = -1;
  while (map[++i] != '\0');
  i -= 2;
  j = -1;
  while (map[i][++j] != '\0')
    {
      if (map[i][j] == vars->player && i - 1 != 1 && map[i - 1][j] == ' ')
	map[i - 1][j] = '|';
    }
}

void	move_all(char **map, t_vars *vars)
{
  int	i;
  int	j;

  i = -1;
  while (map[++i] != '\0')
    {
      j = -1;
      while (map[i][++j] != '\0')
	{
	  if (map[i][j] == vars->ennemy && map[i + 1] != '\0'
	      && (map[i + 1][j] == ' '  || map[i + 1][j] == vars->player))
	    {
	      map[i][j] = ' ';
	      map[i + 1][j] = 'Z';
	    }
	  else if (map[i][j] == vars->ennemy && map[i + 2] == '\0')
	    map[i][j] = ' ';
	  else if (map[i][j] == vars->ennemy && map[i + 1] != '\0'
		   && map[i + 1][j] == '|')
	    {
	      map[i][j] = ' ';
	      map[i + 1][j] = ' ';
	    }
	  else if (map[i][j] == '|' && i != 0 && map[i - 1][j] == ' ')
	    {
	      map[i][j] = ' ';
	      map[i - 1][j] = 'Y';
	    }
	  else if (map[i][j] == '|' && i == 1)
	    map[i][j] = ' ';
	}
    }
  i = -1;
  while (map[++i] != '\0')
    {
      j = -1;
      while (map[i][++j] != '\0')
	{
	  if (map[i][j] == 'Z')
	    map[i][j] = vars->ennemy;
	  else if (map[i][j] == 'Y')
	    map[i][j] = '|';
	}
    }
}

void	put_ennemies(char **map, t_vars *vars)
{
  int	i;
  int	j;
  int	nb;
  int	j_rdm;

  i = 0;
  j = -1;
  while (map[i][++j] != '\0');
  nb = abs(get_rand() % (j - 3));
  while (nb > 0)
    {
      j_rdm = abs(get_rand() % (j - 3));
      if (map[1][j_rdm] == ' ')
	map[1][j_rdm] = vars->ennemy;
      --nb;
    }
}

static void	display(char **map, t_vars *vars)
{
  int	i;
  int	j;
  int	x;
  int	y;
  int	tmp;

  x = LINES / 2 - vars->x / 2;
  y = COLS / 2 - vars->y / 2;
  tmp = y;
  start_color();
  init_pair(2, COLOR_GREEN, COLOR_WHITE);
  init_pair(3, COLOR_BLUE, COLOR_GREEN);
  init_pair(4, COLOR_RED, COLOR_MAGENTA);
  init_pair(5, COLOR_YELLOW, COLOR_BLACK);
  i = -1;
  while (map[++i] != '\0')
    {
      j = -1;
      y = tmp;
      while (map[i][++j] != '\0')
	{
	  if (map[i][j] == '#')
	    {
	      attron(COLOR_PAIR(2) | A_BOLD | A_UNDERLINE);
	      mvprintw(x, y, "%c", map[i][j]);
	      attroff(COLOR_PAIR(2) | A_BOLD | A_UNDERLINE);
	    }
	  else if (map[i][j] == vars->ennemy)
	    {
	      attron(COLOR_PAIR(4) | A_BOLD);
	      mvprintw(x, y, "%c", map[i][j]);
	      attroff(COLOR_PAIR(4) | A_BOLD);
	    }
	  else if (map[i][j] == vars->player)
	    {
	      attron(COLOR_PAIR(3) | A_BOLD);
	      mvprintw(x, y, "%c", map[i][j]);
	      attroff(COLOR_PAIR(3) | A_BOLD);
	    }
	  else if (map[i][j] == '|')
	    {
	      attron(COLOR_PAIR(5) | A_BOLD);
	      mvprintw(x, y, "%c", map[i][j]);
	      attroff(COLOR_PAIR(5) | A_BOLD);
	    }
	  ++y;
	}
      ++x;
    }
}

void	moving(char **map, t_vars *vars)
{
  int	cpt;
  int	key;

  cpt = 1;
  change_term(0);
  while (1)
    {
      if (cpt % 30 == 0)
	put_ennemies(map, vars);
      key = getch();
      if (key == KEY_RIGHT)
	go_right(map, vars);
      else if (key == KEY_LEFT)
	go_left(map, vars);
      else if (key == ' ')
	shoot(map, vars);
      else if (key == 27)
	{
	  clear();
	  endwin();
	  exit(0);
	}
      if (cpt % 3 == 0)
	move_all(map, vars);
      if (perso(map, vars) == -1)
	{
	  clear();
	  mvprintw(LINES / 2, COLS / 2 - 9, "VOUS AVEZ PERDU !");
	  change_term(1);
	  getch();
	  break ;
	}
      clear();
      display(map, vars);
      ++cpt;
      //      printw("%d --- ", cpt);
    }
  change_term(1);
}
