#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
static int  i=0,j=0,r=0,c=0,result=0,n=0;
void position(int);

void print(int a[3][3])
{
	 for(i=0;i<3;i++)
	 {
	 	for(j=0;j<3;j++)
	 	{
	 		printf("%5d",a[i][j]);
		}
		printf("\n");
	 }
}

void enter1(int a[3][3])
{
	
	puts("Player 1 Enter position:");
	scanf("%d",&n);
	if(n>9||n<1)
	{
		puts("invalid input.Re enter position.");
		enter1(a);
		
	}
	else
	{
		position(n);
		check1(a);
	}
}

void enter2(int a[3][3])
{
	puts("Player 2 Enter position:");
	scanf("%d",&n);
	if(n>9||n<1)
	{
		puts("invalid input.Re enter position.");
		enter2(a);
		
	}
	else
	{
		position(n);
		check2(a);
	}
}

void position(int n)
{
	switch(n)
		{
		case 1:
			r=0;
			c=0;
			break;
		case 2:
			r=0;
			c=1;
			break;
		case 3:
			r=0;
			c=2;
			break;
		case 4:
			r=1;
			c=0;
			break;
		case 5:
			r=1;
			c=1;
			break;
		case 6 :
			r=1;
			c=2;
			break;
		case 7:
			r=2;
			c=0;
			break;
		case 8:
			r=2;
			c=1;
			break;
		case 9:
			r=2;
			c=2;
			break;
	}
}
	
check1(int a[3][3])
{
	if(a[r][c]==0)
	{
		a[r][c]=1;
		result_check(a);
	}
	else
	{
		puts("postion already entered.Enter another position.");
		enter1(a);
	}
}

check2(int a[3][3])
{
	if(a[r][c]==0)
	{
		a[r][c]=2;
		result_check(a);
	}
	else
	{
		puts("postion already entered.Enter another position.");
		enter2(a);
	}
}

result_check(int a[3][3])
{
	for(i=0;i<3;i++)
	{
		if(a[i][0]==a[i][1]&&a[i][1]==a[i][2]&&a[i][2]!=0)
		{
			result=1;
			break;
		}
		if(a[0][i]==a[1][i]&&a[1][i]==a[2][i]&&a[2][i]!=0)
		{
			result=1;
			break;
		}
	}
	if(a[0][0]==a[1][1]&&a[1][1]==a[2][2]&&a[2][2]!=0)
		{
			result=1;
		}
	if(a[0][2]==a[1][1]&&a[1][1]==a[2][0]&&a[2][0]!=0)
	{
		result=1;
	}
}

int main()
{
	int a[3][3]={0},count=0;
	puts("XO GAME FOR 2 PLAYERS");
	puts("Value of position are:");
	puts("1  2  3");
	puts("4  5  6");
	puts("7  8  9");
	puts("Enter value of to select position:");
	while(result==0)
	{
		print(a);
		enter1(a);
		count++;
		if(result==0)
		{
			if(count==5)
			{
				print(a);
				puts("Match is draw.");
				exit(0);
			}
			print(a);
			enter2(a);
		}
		else
		{
			print(a);
			printf("Player 1 is winner.");
			exit(0);
		}
	}
	print(a);
	puts("Player 2 is winner.");
}



