#include<string.h>
#include<stdlib.h>
#include <stdio.h>

int
main ()
{
  int i = 0, sc, m, k, t;
  char *data_steam, *temp, carry = '0';
  sc = 8;
  m = sc;
  data_steam = malloc (40 * sizeof (char));
  temp = malloc (8 * sizeof (char));
  printf ("\nEnter 32 bit stream : ");
  scanf ("%s", &data_steam);
  for (int r = sc - 1; r >= 0; r--)
    {
      strcpy (temp[sc - r], data_steam[r]);
    }
  while (i < 32)
    {
      i = 0;
      k = m;
      t = m + sc;
      while (t > k)
	{
	  if (strcmp (temp[i], data_steam[t]) == 0 && carry == '0')
	    {
	      if (temp[i] == '1')
		{
		  temp[i] = '0';
		  carry = '1';
		}
	      else
		{
		  temp[i] = '0';
		  carry = '1';
		}
	    }
	  else if (strcmp (temp[i], data_steam[t]) == 0 && carry == '1')
	    {
	      if (temp[i] == '1')
		{
		  temp[i] = '1';
		  carry = '1';
		}
	      else
		{
		  temp[i] = '1';
		  carry = '0';
		}
	    }
	  else if(strcmp(temp[i],data_steam[t])==1 && carry=='1')
	  {
	      temp[i]='0';
	      carry='1';
	  }
	  else if (strcmp(temp[i],data_steam[t]==1 && carry=='0'))
	  {
	      temp[i]='1';
	      carry='0';
	  }
	  i++;
	  t--;
	}
      m += sc;
      i += k;
      printf ("\n\n");
    }
    printf("string is : : %s ",temp);
  return 0;
}
