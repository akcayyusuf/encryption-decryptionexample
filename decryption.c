#include <stdio.h>
#include <stdlib.h>

int main()
{
int r,c,i,j,x,k=0;
char key[20];		//name of the matrix file
char script[256];	//name of the encrypted file
char encrypt[256];	//name of the decrypted file


int metin[1000];	//	encryted text


printf("Provide the name of the file that include matrix with its extension.\n");
scanf("%s",&key);


printf("Provide the filename containing the encrypted text with the extension...\n");
scanf("%s",&script);

printf("Provide the name of the file that will contain the decrypted text with the extension.\n");
scanf("%s",&encrypt);

FILE *file=fopen(key,"r");

fscanf(file,"%c%c",&r,&c);
r=r-48;	//ASCII to int 
c=c-48; //ASCII to int 

char M[r][c];	//key matrix


for(i=0;i<r;i++)
{
	for(j=0;j<c;j++)
	{
		fscanf(file,"%c",&M[i][j]);	//read matrix			
	}
}

fclose(file);	

file=fopen(script,"r");
FILE *fp=fopen(encrypt,"w");
i=0;
j=0;
while(!feof(file))
{
	
	fscanf(file,"%d ",&metin[k]);	//read encrypted file
	j=(metin[k]-11)/10;	//value of real column index value
	i=(metin[k]-11)%10; //value of real row index value
	fputc(M[i][j],fp); //Go to the column and row values that you found in the matrix and write to the file
	k++;
}
printf("Decryption is complete ...");
fclose(fp);
fclose(file);
}
