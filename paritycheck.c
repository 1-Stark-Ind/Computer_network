#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void add_parity()
{
	int count=0;
	int *arr,size, par_,temp;
	printf("Enter the size of Bit Frame: ");
	scanf("%d",&size);
	arr=malloc(size*sizeof(int));
	printf("Enter Bit Frame:");
	for(int i=0;i<size-1;i++)
	{	scanf("%d",&temp);
		if(temp==1 || temp==0)
			arr[i]=temp;
		else
		{
			printf("invalid input");
			exit(0);
		}
	}
	printf("Enter the Parity\n1 for even\n2 for odd:\n");
	scanf("%d",&par_);
	printf("\nyour bit stream is : ");
	for(int i=0;i<size-1;i++)
		printf("%d",arr[i]);
	for(int i=0;i<size-1;i++)
	{
		if (arr[i]==1)
			count= count+1;
	}
	switch(par_)
	{
		case 1:
			if(count%2==0)
				arr[size]= 0;
			else
				arr[size]=1;
			break;
		case 2:
			if(count%2==1)
				arr[size]= 0;
			else
				arr[size]=1;
			break;
		default:
			printf("You choose a wrong option");
			exit(0);
	}
	printf("\nThe new bit stream is : ");
		for(int i=0;i<size;i++)
			printf("%d",arr[i]);
}			
void check_parity()
{
	int *arr,size,count=0,temp,par_;
	printf("Enter the size of recieved bit frame:");
	scanf("%d",&size);
	arr=malloc(size*sizeof(int));
	printf("Enter the bit frame :");
	for(int i=0;i<size;i++)
	{	scanf("%d",&temp);
		if(temp==1 || temp==0)
			arr[i]=temp;
		else
		{
			printf("invalid input");
			exit(0);
		}
	}
	printf("Enter the Parity\n1 for even\n2 for odd:\n");
	scanf("%d",&par_);
	for(int i=0;i<size;i++)
	{
		if (arr[i]==1)
			count= count+1;
	}
	switch(par_)
	{
		case 1:
			if(count%2==0)
				printf("The recieved bit frame is correct");
			else
				printf("The recieved bit frame is incorrect");
			break;
		case 2:
			if(count%2==1)
				printf("The recieved bit frame is correct");
			else
				printf("The recieved bit frame is incorrect");
			break;
		default:
			printf("You choose a wrong option");
			exit(0);
	}
}					
int main(void)
{	
	int option;
	printf("Enter\n1 for adding parity for sending data frame\n2 for checking parity bit in recieved data frame\n::");
	scanf("%d",&option);
	switch(option)
	{
		case 1:
			add_parity();
			break;
		case 2:
			check_parity();
			break;
		default:
			printf("Wrong Option");
			exit(0);
	}	
	
	return 0;
}
