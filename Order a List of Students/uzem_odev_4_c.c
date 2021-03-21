#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct ogrenci
{
	char isim[10];
	int no;
};
void main()
{
	int i;
	struct ogrenci read1;
	int sayac;
	printf("isim sirali dosyayi okumak icin ->1\nnumara sirali dosyayi okumak icin ->2:");
	scanf("%d",&sayac);
	FILE *fp;
	if(sayac==1)
	{
		fp = fopen("uzem_odev_4_a.txt","r");
	}
	else
	{
		fp = fopen("uzem_odev_4_b.txt","r");
	}
	for(i=0;i<20;i++)
	{
		fscanf(fp,"%s %d ",&read1.isim,&read1.no);
		printf("%s %d \n",read1.isim,read1.no);
	}
	fclose(fp);
}
