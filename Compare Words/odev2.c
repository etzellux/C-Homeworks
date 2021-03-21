#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int indisbul(char text,char nesne[10])
{
	int i;
	for(i=0;i<10;i++)
	{
		if(nesne[i] == text)
		{
			return i;
		}
	}
}
void karsilastir(char nesne[10][10], char text[10],int *arr_puan)
{
	*arr_puan= 0;
	char compared[10];
	int i,j,k,l;
	for(i=0;i<10;i++)
	{
		if(strcmp(nesne[i],text)==0)
		{
			arr_puan[i] = 3*strlen(text);
		}
		else
		{
			for(j=0;j<10;j++)
			{
				if(strchr(nesne[i],text[j])!=NULL)
				{
					k = indisbul(text[j],nesne[i]);
					if(j==k)
					{
						arr_puan[i] += 3;
					}
					else if(j==(k-1) || j==(k+1))
					{
						arr_puan[i] += 2;
					}
					else
					{
						arr_puan[i] += 1;
					}			
				}
			}
		}
		printf("%s nesnesinin puani:%d\n",nesne[i],arr_puan[i]);
	}
}
int main()
{
	char nesne[10][10] = {"kitap","kalem","makine","klavye","mouse","ekran","silgi","masa","koltuk","bilgisayar"};
	char *text = (char *) malloc(10*sizeof(char));
	int *arr_puan = (int *) malloc(10*sizeof(int));
	printf("Bir nesne giriniz:");
	scanf("%s",text);
	karsilastir(nesne,text,arr_puan);
} 
