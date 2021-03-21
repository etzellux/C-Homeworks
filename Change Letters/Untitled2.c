#include <stdio.h>
#include <stdlib.h>

int replace( char *s, char a, char b);

void main()
{
	char text[20],a,b;
	printf("Lutfen bir metin giriniz:");
	scanf("%s",&text);
	fflush(stdin);
	printf("Degistirmek istediginiz harfi giriniz:");
	scanf("%c",&a);
	fflush(stdin);
	printf("Degistirilecek harfi giriniz:");
	scanf("%c",&b);
	int n = replace(&text[0],a,b);
	printf("Metinin son hali:%s\n",text);
	printf("n=%d",n);
	
}

int replace( char *s, char a, char b)
{
	int sayac=0,i;
	for(i=0;*(s + i)!='\0';i++)
	{
		if(*(s + i) == a)
		{
			*(s + i) = b;
			sayac++;
		}
	}
	return sayac;
}
