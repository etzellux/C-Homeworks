#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int topla(int sayi,int toplam)
{
	if(sayi>1)
	{
		toplam+=sayi;
		sayi--;
		return topla(sayi,toplam);
	}
	else if(sayi==1)
	{
		toplam+=sayi;
		return toplam;
	}	
}
int main()
{
	int sayi;
	printf("Enter a number:");
	scanf("%d",&sayi);
	printf("Sum of 1 to the %d:%d",sayi,topla(sayi,0));
	
}
