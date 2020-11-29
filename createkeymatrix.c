#include <time.h>
#include <stdlib.h>
#include <stdio.h>


int main()
{
int w,h;
int i,j,x,random,k=0;
char filename[20];

printf("Give the name of the file to be written to the matrix with its extension...\n");
scanf("%s",&filename);  


FILE *key=fopen(filename,"w");

	
	

	printf("Give the number of rows and columns of the matrix in the same order..\n");
	scanf("%d %d",&w,&h);
	while(w*h<54 || w>9||h>9)	//Check for user inputs
	{
		printf("Wrong input your  array size lower than 54 try again\n");
		scanf("%d %d",&w,&h);
	}

    int M[w][h];	//Encryption Matris defined
	int *p=&M;		
	
	 int mylist[54];	//A string to hold ASCII codes has been defined for easier selection..
	
	
	for(i=0;i<52;i++)	//fill mylist array
	{
		if(i<26){
		
		mylist[i]=65+i;
		}
		else 
		{
			mylist[i]=71+i;
		}
	}
	mylist[52]=32;
	mylist[53]=46;


	
	

i = 0;
srand(time(NULL));   // it has to be called once

for(i=0;i<w;i++)		//Check if the inserted character has been placed before
{
	for(j=0;j<h;j++)
	{
	
		random=rand()%54;
		M[i][j]=mylist[random];
		x=0;
		while(x<k &&k!=0&&k<54)
		{
			
			if(*(p+x)==M[i][j])
			{
				
				random=rand()%54;
				M[i][j]=mylist[random];
				x=0;
			}
			else{
				x++;
			}
			
		}
		if(k>53)
		{
			M[i][j]=0;
		}
		k++;
	}
}
	
	
	
	fputc(w+48,key);	//write row number at file
	fputc(h+48,key);	//write column number at file
	for(i=0;i<w;i++)
	{
		for(j=0;j<h;j++)
		{
			fputc(M[i][j],key);	//write characters at file
		}
	}
	printf("The password matrix file has been created	. . .");
}












