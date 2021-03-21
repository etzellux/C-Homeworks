#include <stdio.h>
#include <time.h>
void dizi_uret(int *ptr,int m,int n) // m satýr sayýsý, n sütun sayýsý
{
	int min,max,i,j;
	printf("Lutfen bir minimum deger giriniz:");
	scanf("%d",&min);
	printf("Lutfen bir maximum deger giriniz:");
	scanf("%d",&max);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			*(ptr + i*n + j) = rand()%(max-min) + min;
		}
	}	
}
int hesapla(int *ptr,int m,int n)
{
	int i,j,temp,satir,toplam=0,sonuc;
	int *dizi;
	dizi = (int *) malloc(m*n*sizeof(int));
	printf("Toplamini istediginiz satiri giriniz:");
	scanf("%d",&satir);
	for(i=0;i<n;i++)
	{
		toplam += *(ptr + (satir-1)*n + i);
	}
	printf("%d.satirin elemanlarinin toplami:%d\n",satir,toplam);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			*(dizi + i*n + j) = *(ptr + i*n + j);
		}
	}
	for(i=0;i<m*n-1;i++)
	{
		for(j=1;j<m*n;j++)
		{
			if(*(dizi + j) > *(dizi + j + 1))
			{
				temp = *(dizi + j);
				*(dizi + j) = *(dizi + j + 1);
				*(dizi + j + 1) = temp;
			}
		}
	}
	sonuc = *(dizi + m*n);
	for(i=m*n-1;i>0;i--)
	{
		if(*(dizi + i)<sonuc)
		{
			sonuc = *(dizi + i);
			break;
		}
	}
	return sonuc;
	
}
void main()
{
	srand(time(NULL));
	int i,j,m,n;
	int *dizi;
	printf("Dizinin satir sayisini giriniz:");
	scanf("%d",&m);
	printf("Dizinin sutun sayisini giriniz:");
	scanf("%d",&n);
	dizi = (int *) malloc(m*n*sizeof(int));
	dizi_uret(dizi,m,n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d  ",*(dizi + i*n + j));
		}
		printf("\n");
	}
	int deger = hesapla(dizi,m,n);
	printf("2.Maximum = %d",deger);
	
}
