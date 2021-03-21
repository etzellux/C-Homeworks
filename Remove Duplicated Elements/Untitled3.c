#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int * dizi_olustur(int *dizi1);
void main()
{
	srand(time(NULL));
	int *dizi;
	dizi = dizi_olustur(dizi);
}
int * dizi_olustur(int *dizi1)
{
	dizi1 = (int *) malloc(20*sizeof(int));
	int *dizi2 = (int *) malloc(20*sizeof(int));
	int i,j,k,l;
	printf("Dizinin ilk hali:\n");
	for(i=0;i<20;i++)
	{
		*(dizi1 + i) = rand()%10;
		printf("%d  ",*(dizi1 + i));
	}
	printf("\n");
	for(l=0;l<2;l++)
	{
	
		for(i=0;i<20;i++)
		{
			for(j=i+1;j<20;j++)
			{
				if(*(dizi1 + i) == *(dizi1 + j))
				{
					for(k=j;k<20;k++)
					{
						*(dizi1 + k) = *(dizi1 + k + 1);
					}
				}
			}
		}
	}
	
	printf("Dizinin son hali:\n");
	for(i=0;*(dizi1 + i) != *(dizi1 + i + 1);i++)
	{
		*(dizi2 + i) = *(dizi1 + i);
		printf("%d  ",*(dizi1 + i));
	}
	return dizi2;
}

