#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int		get_rand()
{
  srand(time(NULL));
  return (rand());
}
