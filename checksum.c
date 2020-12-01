#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main ()
{
  int i = 0, sc, m, k=7, t;
  char data_stream[40], *temp,*temp1, carry = '0';
  sc = 8;
  m = sc;
  temp=(char*)calloc(8,sizeof(char));
  temp1=(char*)calloc(8,sizeof(char));
  printf ("\nEnter 32 bit stream : ");
  scanf("%s",data_stream);
  for (int i = 0; i <8; i++)
    {  
        temp[k] = *(i+data_stream);
        k--;
    }

  while (i < 32)
    {
     i = 0;
     k = m;
     t = m + sc;
     while (t > k)
     {
     if ((temp[i]== *(data_stream+(t-1))) && (carry == '0'))
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
     else if ((temp[i]== *(data_stream+(t-1))) && (carry == '1'))
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
     else if ((temp[i]!= *(data_stream+(t-1))) && (carry == '0'))
     {
     temp[i] = '1';
     carry = '0';
     }
     else if ((temp[i]!= *(data_stream+(t-1))) && (carry == '1'))
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
    
    int b=7;
    for(int i=0;i<8;i++)
    {
       if (temp[b]=='1')
       {
           temp1[i]='0';
       }
       else if(temp[b]=='0')
       {
           temp1[i]='1';
       }
       b--;
       
    }
    printf("\nChecksum is : : %s",temp1);
    return 0;
}
