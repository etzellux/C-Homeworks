#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	printf("Lutfen bekleyiniz...\n");
	double sayi=100000,toplam=0,i,harcananzaman1,harcananzaman2;;
	clock_t start1,end1,start2,end2;
	register double j;
	start1 = clock();
	for(i=0;i<sayi;i+=0.0001)
	{
		toplam+=i;
	}
	printf("Toplam:%f\n",toplam);
	end1 = clock();
	harcananzaman1=(((double)(end1-start1))/CLOCKS_PER_SEC);
	printf("Zaman1:%f\n",harcananzaman1);
	toplam=0;
	start2= clock();
	for(j=0;j<sayi;j+=0.0001)
	{
		toplam+=j;
	}
	printf("Toplam:%f\n",toplam);
	end2 = clock();
	harcananzaman2 = (((double)(end2-start2))/CLOCKS_PER_SEC);
	printf("Zaman2:%f\n",harcananzaman2);
	printf("*************\n");
	printf("Zaman farki:%f",harcananzaman1-harcananzaman2);
	
	
}
