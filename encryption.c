#include <stdio.h>
#include <stdlib.h>

//anahtar means key in turkish

int main()
{
int r,c,i,j,x,k=0;
char key[20];	//name of the matrix file
char script[256];	//text file name to be encrypt
char encrypt[256];	//encrypted text file name


char metin[1000];	//	text


printf("Provide the name of the file that include matrix with its extension.\n");
scanf("%s",&key);


printf("Provide the file name containing the text to be encrypt with the its extension.\n");
scanf("%s",&script);

printf("Provide the name of the file will contain the encrypted text, along with the extension.\n");
scanf("%s",&encrypt);

FILE *anahtar=fopen(key,"r");

fscanf(anahtar,"%c%c",&r,&c);
r=r-48;
c=c-48;
char M[r][c];	//key matrix


for(i=0;i<r;i++)
{
	for(j=0;j<c;j++)
	{
		fscanf(anahtar,"%c",&M[i][j]);	//read file hold in M matrix
				
	}
}

fclose(anahtar);	//close file



FILE *text=fopen(script,"r");

while(!feof(text))
{
	
	fscanf(text,"%c",&metin[k]); //read letter by letter
	k++;
}

fclose(text);	//close file



int *ptr=malloc(k*sizeof(int));	

for(x=0;x<k;x++)
{
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(metin[x]==M[i][j])	//search all matrix for given character at first for loop
			{
				*(ptr+x)=(j+1)*10+(i+1);		//apply our rule
			}
			
		}
	}
	
}
text=fopen(encrypt,"w");
for(x=0;x<k-1;x++)
	fprintf(text,"%d ",ptr[x]);	//write encrypted format to file

free(ptr);	//free memory
fclose(text);	//close file
printf("Encryption is complete ...");

}
