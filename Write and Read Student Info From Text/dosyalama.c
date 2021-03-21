#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
struct ogrenci //student
{
	char ad[10]; //name
	char no[3];	//id number
};
void yaz(FILE *fp,struct ogrenci *ogrenci)
{
	printf("Lutfen bir isim giriniz:");
	scanf("%s",&(ogrenci->ad));
	printf("Lutfen bir no giriniz:");
	scanf("%s",&(ogrenci->no));
	fprintf(fp,"%s %s ",&(ogrenci->ad),&(ogrenci->no));
}
void ara(FILE *fp,char *aranan)
{
	int ad[10];
	int no[3];
	int i,j=0;
	for(i=0;i<20;i++)
	{
		fscanf(fp,"%s %s ",&ad,&no);
		if()
		{
			printf("**********************");
			printf("Ad:%s\nNo:%s",ad,no);
			printf("**********************");
			j=1;
		}
	}
	if(j!=1)
	{
		printf("Aranan isimde ogrenci yoktur.\n");
	}
}
void main()
{
	FILE *fp;
	fp = fopen("kayit.txt","ab");
	struct ogrenci ogrenciler[20];
	int secim,i=0;
	while(1)
	{
		printf("Ogrenci bilgisi girmek icin-->1\nOgrenci bilgisi aramak icin-->2\nCikmak icin-->3\n:");
		scanf("%d",&secim);
		if(secim==1)
		{
			yaz(fp,&ogrenciler[i++]);
		}
		else if(secim==2)
		{
			char aranan[10];
			printf("Aranan ogrenci ismini giriniz:");
			scanf("%s",&aranan);
			ara(fp,&aranan);
		}
		else if(secim==3)
		{
			break;
		}
	}
	fclose(fp);
}

