#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int
sender_end ()
{
  int i = 0, sc, m, k, t;
  char data_stream[41], *temp, *temp1, carry = '0';
  printf ("\nEnter 32 bit stream : ");
  scanf ("%s", data_stream);
  printf ("\nEnter the size of Checksum : :");
  scanf ("%d", &sc);
  temp = (char *) calloc (sc, sizeof (char));
  temp1 = (char *) calloc (sc, sizeof (char));
  m = sc;
  k = m - 1;
  for (int i = 0; i < m; i++)
    {
      temp[k] = *(i + data_stream);
      k--;
    }
  if (sc % 4 == 0 && sc < 32)
    {
      while (i < 32)
	{
	  i = 0;
	  k = m;
	  t = m + sc;
	  while (t > k)
	    {
	      if ((temp[i] == *(data_stream + (t - 1))) && (carry == '0'))
		{
		  if (temp[i] == '1')
		    {
		      temp[i] = '0';
		      carry = '1';
		    }
		  else
		    {
		      temp[i] = '0';
		      carry = '0';
		    }
		}
	      else if ((temp[i] == *(data_stream + (t - 1)))
		       && (carry == '1'))
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
	      else if ((temp[i] != *(data_stream + (t - 1)))
		       && (carry == '0'))
		{
		  temp[i] = '1';
		  carry = '0';
		}
	      else if ((temp[i] != *(data_stream + (t - 1)))
		       && (carry == '1'))
		{
		  temp[i] = '0';
		  carry = '1';
		}
	      i++;
	      t--;
	    }
	  m += sc;
	  i += k;

	}

      int b = sc - 1;
      for (int i = 0; i < sc; i++)
	{
	  if (temp[b] == '1')
	    {
	      temp1[i] = '0';
	    }
	  else if (temp[b] == '0')
	    {
	      temp1[i] = '1';
	    }
	  b--;

	}
      printf ("\nChecksum is : : %s", temp1);
      int p = 0;
      for (int i = 32; i < sc + 32; i++)
	{
	  *(data_stream + i) = temp[p];
	  p++;
	}
      printf ("\ndata stream is :: %s", data_stream);
      return 0;
    }
  else
    {
      printf ("Size of checksum is incorrect");
      return 2;
    }
}

int
receiver_end ()
{

  int i = 0, sc, m, k, t,size_,count=0;
  char data_stream[64], *temp, *temp1, carry = '0';
  printf ("\nEnter the size of data_stream : :");
  scanf ("%d", &size_);
  printf ("\nEnter received bit stream : ");
  scanf ("%s", data_stream);
  sc=size_-32;
  temp = (char *) calloc (sc, sizeof (char));
  temp1 = (char *) calloc (sc, sizeof (char));
  m = sc;
  k = m - 1;
  for (int i = 0; i < m; i++)
    {
      temp[k] = *(i + data_stream);
      k--;
    }
  if (sc % 4 == 0 && sc < 32)
    {
      while (i < 32)
	{
	  i = 0;
	  k = m;
	  t = m + sc;
	  while (t > k)
	    {
	      if ((temp[i] == *(data_stream + (t - 1))) && (carry == '0'))
		{
		  if (temp[i] == '1')
		    {
		      temp[i] = '0';
		      carry = '1';
		    }
		  else
		    {
		      temp[i] = '0';
		      carry = '0';
		    }
		}
	      else if ((temp[i] == *(data_stream + (t - 1)))
		       && (carry == '1'))
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
	      else if ((temp[i] != *(data_stream + (t - 1)))
		       && (carry == '0'))
		{
		  temp[i] = '1';
		  carry = '0';
		}
	      else if ((temp[i] != *(data_stream + (t - 1)))
		       && (carry == '1'))
		{
		  temp[i] = '0';
		  carry = '1';
		}
	      i++;
	      t--;
	    }
	  m += sc;
	  i += k;

	}
      i = 0;
      carry = '0';
      for (int y = size_-1; y >=32; y--)
	{
	  if ((temp[i] == *(data_stream + y)) && (carry == '0'))
	    {
	      if (temp[i] == '1')
		{
		  temp[i] = '0';
		  carry = '1';
		}
	      else
		{
		  temp[i] = '0';
		  carry = '0';
		}
	    }
	  else if ((temp[i] == *(data_stream + y)) && (carry == '1'))
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
	  else if ((temp[i] != *(data_stream + y)) && (carry == '0'))
	    {
	      temp[i] = '1';
	      carry = '0';
	    }
	  else if ((temp[i] != *(data_stream + y)) && (carry == '1'))
	    {
	      temp[i] = '0';
	      carry = '1';
	    }
	  i++;
	}
	for(int i=0;i<sc;i++)
	{
	    if(temp[i]=='1')
	    {
	        count++;
	    }
	    
	}
	printf("\nchecksum::\t%s",temp);
	if(count==sc)
	{
	    printf("\nData is correct");
	}
	else
	    {
	        printf("The bit stream is compromised and discarded");
	    }
      return 0;
    }
  else
    {
      printf ("Size of checksum is incorrect");
      return 2;
    }
}

int
main ()
{
  int ch, re = 0;
  printf
    ("Enter your choice..\n1. For sending a bit stream.\n2. For received bit stream.\n :::");
  scanf ("%d", &ch);
  switch (ch)
    {
    case 1:
      do
	{
	  re = sender_end ();
	}
      while (re == 2);
      break;
    case 2:
      do
	{
	  re = receiver_end ();
	}
      while (re == 2);
      break;
    default:
      printf ("Wrong Choice");
      exit (0);
    }
}
