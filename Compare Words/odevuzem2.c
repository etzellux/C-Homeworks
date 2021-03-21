#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void harfleri_bul(char *,char *);
void indisleri_belirle(char ,char *,int *);
int karsilastir(int *,int *);
int main()
{
	int i,j,k;                 //1-text,2-nesneler
	int nesne_puan[10] = {0};
	int indistutucu1[10] = {0};
	int indistutucu2[10] = {0};
	char *text,*harfler,nesne[10];
	char nesneler[10][10] = {"kitap","kalem","makine","klavye","mouse","ekran","silgi","masa","koltuk","bilgisayar"};
	text = (char *) malloc(10*sizeof(char));
	harfler = (char *) malloc(10*sizeof(char));
	printf("Lutfen bir nesne giriniz:");
	scanf("%s",text);
	harfleri_bul(text,harfler);
	for(i=0;i<10;i++) // bütün nesneleri karsilastirmak için
	{
		strcpy(nesne,nesneler[i]);
		for(j=0;j<strlen(harfler);j++) //bütün nesnelerin harflerini karsilastirmak için
		{
			indisleri_belirle(harfler[j],text,indistutucu1);
			indisleri_belirle(harfler[j],nesne,indistutucu2);
			nesne_puan[i] = karsilastir(indistutucu1,indistutucu2);
		}
		printf("%s nesnesinin benzerlik puani:%d\n",nesne,*(nesne_puan + i));
	}
}
void harfleri_bul(char *text,char *harfler)
{
	int i,j,k,sayac=0;
	strcpy(harfler,text);
	for(i=0;i<strlen(harfler);i++)
	{
		for(j=0;j<strlen(harfler);j++)
		{
			if(harfler[i]==harfler[j])
			{
				sayac++;
			}
			if(sayac>1)
			{
				for(k=j;k<strlen(harfler);k++)
				{
					harfler[j] = harfler[j+1];
				}
			}
		}
		sayac=0;
	}
}
void indisleri_belirle(char harf,char metin[10],int *indistutucu)
{
	int i;
	for(i=0;i<strlen(metin);i++)
	{
		if(metin[i]==harf)
		{
			*(indistutucu + i) = i;
		}
		
	}
}
int karsilastir(int *indistutucu1,int *indistutucu2)
{

	int i,j,puan=0;
	for(i=0;indistutucu1[i]!=0;i++)
	{
		for(j=0;indistutucu2[j]!=0;j++)
		{
			if(indistutucu1[i]==indistutucu2[j])
			{
				puan += 3;
				indistutucu2[j] = 20;
			}
			else if(indistutucu1[i]==(indistutucu1[j] +1) || indistutucu1[i]==(indistutucu1[j] -1))
			{
				puan += 2;
				indistutucu2[j] = 20;
			}
			else
			{
				puan += 1;
				indistutucu2[j] = 20;
			}
		}
	}
	return puan;
	
}

