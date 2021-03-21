#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct ogrenci
{
	char isim[10];
	int no;
};
struct ogrenci isim_olustur(struct ogrenci example)
{
	char sesli[5] = "aiuoe";
	char sessiz[21] = "qwrtypsdfghjklmnbvcxz";
	int i,j=(rand()%5 +5);
	for(i=0;i<j;i++)
	{
		if(i%2==0)
		{
			int k = rand()%5;
			example.isim[i] = sesli[k];
		}
		else
		{
			int k = rand()%21;
			example.isim[i] = sessiz[k];
		}
	}
	return example;
}
void main()
{
	srand(time(NULL));
	int i,j,k,temp;
	struct ogrenci ogrenciler[20],temp2;
	for(i=0;i<20;i++)
	{
		ogrenciler[i] = isim_olustur(ogrenciler[i]);
		ogrenciler[i].no = i+1;
	}
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			k = rand()%10;
			if(k%2==0)
			{
				temp = ogrenciler[j].no;
				ogrenciler[j].no = ogrenciler[i].no;
				ogrenciler[i].no = temp;
			}
		}
	}
	//for(i=0;i<20;i++)
	//{
	//	printf("Ogrenci isim:%s\nOgrenci no:%d\n",ogrenciler[i].isim,ogrenciler[i].no);
	//}
	printf("**********************\n");
	for(i=1;i<20;i++)
	{
		for(j=0;j<19;j++)
		{
			if(ogrenciler[j].no>ogrenciler[j+1].no)
			{
				temp2 = ogrenciler[j];
				ogrenciler[j] = ogrenciler[j+1];
				ogrenciler[j+1] = temp2;
			}
		}
	}
	//for(i=0;i<20;i++)
	//{
	//	printf("Ogrenci isim:%s\nOgrenci no:%d\n",ogrenciler[i].isim,ogrenciler[i].no);
	//}
	FILE *fp;
	fp = fopen("uzem_odev_4_b.txt","w");
	for(i=0;i<20;i++)
	{
		fprintf(fp,"%s %d ",ogrenciler[i].isim,ogrenciler[i].no);
	}
	fclose(fp);
	printf("dosyalar numara sirali olarak yazdirildi...");
	
	
}
