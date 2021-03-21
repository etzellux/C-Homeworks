#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int metin_say(char dosya_adi[50])
{
	char metin[100];
	int sayac=0;
	FILE *fp;
	fp = fopen(dosya_adi,"r");
	while(feof(fp)==0)
	{
		fgets(metin,100,fp);
		sayac++;
	}
	fclose(fp);
	return sayac-1;
}
void kayit()
{
	char metin[100]; //Kullanicidan alinan stringi tutar
	FILE *fp;
	fp = fopen("soru2.txt","a");
	printf("Lutfen bir metin giriniz:");
	fflush(stdin);
	gets(metin);
	strcat(metin,"\n");
	fputs(metin,fp);
	fclose(fp);
	// FILE pointeri olan fp ve fopen fonksiyonu kullanilarak
	// soru2.txt dosyasina akis saglandi.Kullanicidan alinan string metin
	// degiskenine atandi. fputs fonksiyonu ile metin yazdirildi ve akis
	// fclose ile kapatildi.
}
void oku()
{
	int i,n; //dongude kullanildilar
	char metin[100];
	FILE *fp;
	fp = fopen("soru2.txt","r");
	n = metin_say("soru2.txt"); //satir sayisini tutar
	printf("\n**************************\n");
	for(i=0;i<n;i++)
	{
		fgets(metin,100,fp);
		printf("%s",metin);
	}
	printf("\n**************************\n");
	fclose(fp);
	// FILE pointeri olan fp ve fopen fonksiyonu ile soru2.txt
	// dosyasina r modunda akis saglandi. Dosyanin sonuna gelene kadar devam 
	// eden bir for dongusunde dosyadaki metinler fgets ile okundu ve ekrana printf ile yazildi.
	// fclose ile akis kapatildi.
}
void karsilastir()
{
	int i,j,n,m;
	char dosya_adi[50]; // karsilastirilmak istenen dosyanin adini tutar.
	char metin1[100];
	char metin2[100];
	printf("\nDosyaniz yok ise kayit.txt'i kullanabilirsiniz\n");
	printf("Lutfen karsilastirmak istediginiz dosya adini giriniz:");
	scanf("%s",&dosya_adi);
	FILE *fp_1,*fp_2;  // dosya akisini saglamak icin kullanilan pointerlar
	fp_1 = fopen("soru2.txt","r"); 
	fp_2 = fopen(dosya_adi,"r");
	n = metin_say("soru2.txt"); // soru2.txt'deki satir sayisini tutar
	m = metin_say(dosya_adi); // dosya_adi ile belirtilen dosyanin satir sayisini tutar
	for(i=0;i<n;i++)
	{
		fgets(metin1,100,fp_1);
		for(j=0;j<m;j++)
		{
			fgets(metin2,100,fp_2);
			if(strcmp(metin1,metin2)==0)
			{
				printf("\n%s %d. satir ve soru2.txt %d. satir ayni\n",dosya_adi,j+1,i+1);
			}
		}
		rewind(fp_2); //dosyanin basina donmeyi saglar.
	}
	printf("\n");
	fclose(fp_1);
	fclose(fp_2);
	//Istenilen dosyalara akis saglandi ve ic ice 2 for dongusuyle iki dosyadaki stringler
	// metin1 ve metin2ye atanarak strcmp fonksiyonu ile karsilastirildi. Metinler ayni oldugu durumda metinlerin
	// satir numaralari ekrana yazdirildi.
}
void bul()
{
	int sayac=0,i,n; // sayac aranan metinin dosya icinde kac tane oldugunu tutar. i ve n dongude kullanilir.
	char aranan[100]; // Kullanicidan alinan stringi tutar.
	char metin[100];  // dosyadan cekilen stringleri tutar.
	FILE *fp;
	fp = fopen("soru2.txt","r");
	fflush(stdin);
	printf("Aradiginiz metini giriniz:");
	gets(aranan);
	strcat(aranan,"\n");
	n = metin_say("soru2.txt"); // soru2.txt'in satir sayisini tutar.
	for(i=0;i<n;i++)
	{
		fgets(metin,100,fp);
		if(strcmp(metin,aranan)==0)
		{
			sayac++;
		}
	}
	if(sayac>0)
	{
		printf("\n**************************\n");
		printf("%smetini soru2.txt icinde %d kez bulunmakta\n",aranan,sayac);
		printf("\n**************************\n");
	}
	else
	{
		printf("\n**************************\n");
		printf("%smetini soru2.txt icinde bulunmamaktadir\n",aranan);
		printf("\n**************************\n");
	}
	fclose(fp);
	// r modunda soru2.txt'e akis saglandi. Dosya icindeki stringler bir for dongusu icerisinde metin degiskenine
	// teker teker atandi. metin degiskeninin aranan degiskeni ile ayni olmasi durumunda
	// sayac 1 arttýrýldý. Sayacin 0'dan buyuk olmasi durumunda ekrana yazdirildi.
}
void main()
{
	char metin[100];
	int secenek;
	while(1)
	{
		printf("\nKaydet-->1\nOku-->2\nKarsilastir-->3\nBul-->4\nCikis-->5\nislem:");
		scanf("%d",&secenek);
		
		if(secenek==1)
		{
			kayit();
		}
		else if(secenek==2)
		{
			oku();
		}
		else if(secenek==3)
		{
			karsilastir();
		}
		else if(secenek==4)
		{
			bul();
		}
		else if(secenek==5)
		{
			break;
		}
		else
		{
			printf("Gecersiz Komut!\n");
		}
	}
}
