#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct text
{
	char metin[20];
	char harfler[20];
	char en_benzer[20];
	int sesli_sayisi;
	int sessiz_sayisi;
	int benzerlik_puani;
	
};
struct text metin_ata(struct text message,char yazi[20])
{
	strcpy(message.metin,yazi);
	return message;
}
char* harfleri_belirle(char harfler[20])
{
	int i,j,k;
	for(i=0;i<strlen(harfler);i++)
	{
		for(j=0;j<strlen(harfler);j++)
		{
			if(harfler[j] == harfler[i] && i!=j)
			{
				for(k=j;j<strlen(harfler);i++)
				{
					harfler[k] = harfler[k+1];
				}
			}
		}
	}
	return harfler;
}
struct text hesapla(struct text message)
{
	char harf;
	int i,j,k,sayac_sesli=0,sayac_sessiz=0;
	strcpy(message.harfler,message.metin);
	for(i=0;i<strlen(message.harfler);i++)
	{
		for(j=0;j<strlen(message.harfler);j++)
		{
			if(message.harfler[j] == message.harfler[i] && i!=j)
			{
				for(k=j;k<strlen(message.harfler);k++)
				{
					message.harfler[k] = message.harfler[k+1];
				}
			}
		}
	}
	for(i=0;i<strlen(message.metin);i++)
	{
		harf = message.metin[i];
		if(harf == 'a' || harf == 'e' || harf == 'i' || harf == 'o' || harf == 'u')
		{
			sayac_sesli++;
		}
		else
		{
			sayac_sessiz++;
		}
	}
	message.sesli_sayisi = sayac_sesli;
	message.sessiz_sayisi = sayac_sessiz;
	return message;
}
int karsilastir(char matris[2][20],char harfler[20])
{
	char temp[20];
	//printf("karsilastirma: %s--%s\n",matris[0],matris[1]);
	strcpy(temp,matris[1]);
	int i,j,k,puan=0;
	for(i=0;i<strlen(matris[0]);i++)
	{
		for(j=0;j<strlen(matris[1]);j++)
		{
			if(matris[0][i] == matris[1][j])
			{
				if(i==j)
				{
					puan += 3;
					matris[1][j] = ' ';
					break;
				}
				else if(i==(j+1) || i==(j-1))
				{
					puan += 2;
					matris[1][j] = ' ';
					break;
				}
			}
		}
	}
	for(i=0;i<strlen(harfler);i++)
	{
		if(harfler[i] == ' ')
		{
			continue;
		}
		for(j=0;j<strlen(matris[1]);j++)
		{
			if(harfler[i] == matris[1][j])
			{
				puan += 1;
				matris[1][j] = ' ';
				break;
			}
		}
	}
	//printf("%s---%s   puan:%d\n",temp,matris[0],puan);
	return puan;
}
void nesneleri_goster(struct text nesneler[15])
{
	int i;
	for(i=0;i<15;i++)
	{
		printf("*********************************************\n");
		printf("%d. nesne: %s\n",i+1,nesneler[i].metin); 
		printf("sesli harfler:%d  sessiz harfler:%d\n",nesneler[i].sesli_sayisi,nesneler[i].sessiz_sayisi);
		printf("en benzer nesne: %s   puan:%d\n",nesneler[i].en_benzer,nesneler[i].benzerlik_puani);
		printf("---------------------------------------------\n");
	}
}
void main()
{
	char metinler[15][20] = {"bilgisayar","kitap","masa","oyuncak","kirmizi","mavi","mor","bulmaca","ayakkabi","ekran","yesil","gitar","mouse","klavye","defter"}; //ABS
	int i,j,k,puan,temp1=0,temp2=0,hedef=0;
	char matris[2][20]; //karsilastirmalar icin
	struct text nesneler[15];
	for(i=0;i<15;i++)
	{
		nesneler[i]	= metin_ata(nesneler[i],metinler[i]);
		nesneler[i] = hesapla(nesneler[i]);
	}
	for(i=0;i<15;i++)
	{
		strcpy(matris[0],metinler[i]);
		for(j=0;j<15;j++)
		{
			strcpy(matris[1],metinler[j]);
			if(i==j)
			{
				continue;
			}
			else
			{
				puan = karsilastir(matris,nesneler[i].harfler);
				if(puan>temp1)
				{
					temp1 = puan;
					nesneler[i].benzerlik_puani = puan;
					strcpy(nesneler[i].en_benzer,metinler[j]);
				}
			}
		}
		temp1=0;
	}
	nesneleri_goster(nesneler);
	printf("\nBirbirine en benzeyen 2 nesne:\n");
	for(i=0;i<15;i++)
	{
		if(nesneler[i].benzerlik_puani > temp2)
		{
			temp2 = nesneler[i].benzerlik_puani;
			hedef =i;
		}
	}
	printf("%s-----%s puan:%d",nesneler[hedef].metin,nesneler[hedef].en_benzer,nesneler[hedef].benzerlik_puani);
	
	
}
