#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main ()
{
  int x[12], y[12], z[12], a[99][99], dist, r = 0;

  for (int i = 0; i < 10; i++)
    {
      x[i] = rand () % 100 + 1;
      y[i] = rand () % 100 + 1;
      z[i] = rand () % 50 + 1;
      printf ("\nThe co-ordinates of node %d is : (%d , %d, %d)", (i + 1),
	      x[i], y[i], z[i]);
    }
  printf ("\n\nDistance table is as follows: \n");
  for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < 10; j++)
	{
	  dist =
	    sqrt ((pow ((x[j] - x[i]), 2) + pow ((y[j] - y[i]), 2) +
		   pow ((z[j] - z[i]), 2)));
	  printf ("%d \t", dist);
	}
      printf ("\n");
    }
  dist = 0;
  printf ("\nEnter the range to identify neighbour :");
  scanf ("%d", &r);
  for (int i = 0; i < 10; i++)
    {
      printf ("\nThe neighbour table of node %d is :", i + 1);
      for (int j = 0; j < 10; j++)
	{
	  if (i != j)
	    {
	      dist =
		sqrt ((pow ((x[j] - x[i]), 2) + pow ((y[j] - y[i]), 2) +
		       pow ((z[j] - z[i]), 2)));
	      if (dist < r)
		{
		  printf (" %d", j + 1);
		}
	    }
	}
    }
}
