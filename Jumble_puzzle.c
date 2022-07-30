#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
static int i,j,result=0,tr,tc,r=0,c=0,temp;
static char m;
static int a[3][3]={0,5,3,7,8,2,6,4,1};

void print();
void enter();
void position();
void check();
void swap();
void res_check();

void print()
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

void enter()
{
	printf("Enter movement:");
	scanf("%c",&m);
	fflush(stdin);
	position();
	check();
}

void position()
{
	tc=c;
	tr=r;
	if(m=='w')
		r--;
	else if(m=='a')
		c--;
	else if(m=='s')
		r++;
	else if(m=='d')
		c++;
	else
	{
		puts("Incorrect input try again to enter in wasd format");
		enter();
	}
}


void check()
{
	if(r>2||r<0||c>2||c<0)
	{
		puts("Movement not possible. Re enter movement.");
		r=tr;
		c=tc;
		enter();
	}
}

void swap()
{
	temp=a[tr][tc];
	a[tr][tc]=a[r][c];
	a[r][c]=temp;
}

void res_check()
{
	if(a[0][0]==1&&a[0][1]==2&&a[0][2]==3&&a[1][0]==4&&a[1][1]==5&&a[1][2]==6&&a[2][0]==7&&a[2][1]==8&&a[2][2]==0)
	{
		print();
		puts("FINALLY YOU HAVE SOLVED THE GAME!!!!!!");
		result=1;
	}
}

int main()
{
	int t=1;
	puts("Welcome to jumble game!!!");
	puts("solve the jumble by moving 0 using WASD key");
	while(result==0)
	{
		print();
		if(t==1)
		{
			getch();
		}
		enter();
		system("cls");
		swap();
		res_check();
		t=0;
	}
	return 0;
}
