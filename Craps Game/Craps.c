#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int zarat(int a)
{
	printf("Zarlar atiliyor!...\n");
	int zar1= rand()%6 +1; //user1s dice
	printf("Kullanici%d'in 1. zari:%d\n",a,zar1);
	int zar2= rand()%6 +1; //user2s dice
	printf("Kullanici%d'in 2. zari:%d\n",a,zar2);
	int toplam=zar1+zar2;
	printf("Toplam:%d\n",toplam);
	return toplam;
}
int karsilastir(int toplam,int puan,int a,int i)
{
	if(toplam==puan)
	{
		printf("Kullanici%d kazandi!",a);
		return -1;
	}
	else if(toplam==7&&a!=1 || toplam==7&&i!=1)
	{
		printf("Kullanici%d 7 atti:/,",a);
		if(a==1)
		{
			a++;
		}
		else
		{
			a--;
		}
		printf("Kullanici%d kazandi!",a);
		return -1;
	}
	else
	{
	
		if(i==1)
		{
			if((toplam==7 || toplam==11)&& a!=2)
			{
				printf("Kullanici%d kazandi,Craps!",a);
				return -1;
			}
			else if((toplam==2 || toplam==3 || toplam==12)&& a!=2)
			{
				if(a==1)
				{
					a++;
				}
				else
				{
					a--;
				}
				printf("Kullanici%d kazandi,Craps!",a);
				return -1;
			}
			else
			{
				return toplam;
			}
		}
		else
		{
			return puan;
		}
	}
}
int main()
{
	srand(time(NULL));
	int toplam1,toplam2,puan=0,temp1=0,temp2=0,i=1;
	while(i)
	{
		toplam1=zarat(1);
		printf("****************\n");
		temp1= karsilastir(toplam1,puan,1,i);
		if(i==1)
		{
			puan = temp1;
		}
		if(temp1== -1)
		{
			break;
		}
		toplam2=zarat(2);
		printf("****************\n");
		temp2= karsilastir(toplam2,puan,2,i);
		if(temp2== -1)
		{
			break;
		}
		i++;
	}
}
