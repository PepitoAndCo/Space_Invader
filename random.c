#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int		main()
{
  int		i;
  time_t	old_time;
  time_t	new_time;

  i = 0;
  old_time = 0;
  while (1)
    {
      new_time = time(NULL);
      if (old_time != new_time)
	{
	  srand(new_time);
	  old_time = new_time;
	  i = 0;
	}
      else
	{
	  new_time += i;
	  srand(new_time);
	  ++i;
	}
      printf("%c", rand() % 125);
      usleep(50);
    }
  return (0);
}
