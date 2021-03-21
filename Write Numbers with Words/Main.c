#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct integer{
	int deger;
	int basamak_sayisi;
	int *basamaklar;
	char *text;
};
struct integer basamak_sayisi(struct integer example)
{
	int i,temp;
	temp = example.deger;
	for(i=0;temp>0;i++)
	{
		temp = temp / 10;
	}
	example.basamak_sayisi = i;
	example.basamaklar = (int *) (malloc(example.basamak_sayisi*sizeof(int)));
	temp = example.deger;
	for(i=example.basamak_sayisi-1;i>=0;i--)
	{
		*(example.basamaklar + i) = temp % 10;
		//printf("%d\n",*(basamaklar + i));
		temp = temp / 10;
	}
	return example;
}
struct integer text_olustur(struct integer example)
{
	int i=0,j=0,k=0,l=0,boluk_sayisi,temp;
	char bolukler[7][10] = {" ","yuz","bin","milyon","milyar","trilyon","katrilyon"};
	char onlar[10][10] = {" ","on","yirmi","otuz","kirk","elli","altmis","yetmis","seksen","doksan"};
	char birler[10][10] = {" ","bir","iki","uc","dort","bes","alti","yedi","sekiz","dokuz"};
	temp = example.basamak_sayisi;
	boluk_sayisi = (example.basamak_sayisi/3);
	while(j<example.basamak_sayisi)
	{
		if(temp%3==0)
		{
			if(i==0 || i%3==0)
			{
				if(example.basamaklar[j]==0)
				{
					j++;
				}
				else
				{
						if(example.basamaklar[j]==1)
					{
						printf("%s ",bolukler[1]);
						j++;
					
					}
					else
					{
						printf("%s ",birler[example.basamaklar[j]]);
						printf("%s ",bolukler[1]);
						j++;
					}
				}
			}
			else if(i==1 || i%3==1)
			{
				printf("%s ",onlar[example.basamaklar[j]]);
				j++;
			}
			else if( i==2 || i%3==2)
			{
				printf("%s ",birler[example.basamaklar[j]]);
				if(j!= example.basamak_sayisi-1)
				{
					printf("%s ",bolukler[boluk_sayisi]);
					boluk_sayisi--;
				}
				j++;
			}
			i++;
		}
		else if(temp%3==1)
		{
			if(example.basamaklar[i]==1)
			{
				printf("%s ",bolukler[boluk_sayisi+1]);
				
			}
			else
			{
				printf("%s",birler[example.basamaklar[j]]);
				printf("%s ",bolukler[boluk_sayisi+1]);
				
			}
			j++;
			i=0;
			temp =3;
		}
		else if(temp%3==2)
		{
			printf("%s ",onlar[example.basamaklar[j]]);
			printf("%s ",birler[example.basamaklar[j+1]]);
			printf("%s ",bolukler[boluk_sayisi+1]);
			j+=2;
			i=0;
			temp =3;
		}
	}
	return example;
}
void main()
{
	int temp,i,j;
	struct integer example;
	printf("Lutfen bir sayi giriniz:");
	scanf("%d",&example.deger);
	example = basamak_sayisi(example);
	for(i=0;i<example.basamak_sayisi;i++)
	{
		printf("%d\n",*(example.basamaklar + i));
	}
	example = text_olustur(example);
	

	
	
}
