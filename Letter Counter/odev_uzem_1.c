#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void function(char *textmessage,char harf);
int main()
{
	char harf,text[40];
	char *textmessage;
	textmessage = malloc(40*sizeof(char));
	printf("Lutfen bir cumle giriniz:");
	scanf("%s",textmessage);
	fflush(stdin);
	printf("Lutfen aradiginiz harfi giriniz:");
	scanf("%c",&harf);
	function(textmessage,harf);
	free(textmessage);
}
void function(char *textmessage,char harf)
{
	int i,sayac=0;
	for(i=0;*(textmessage+i)!='\0';i++)
	{
		if(toupper(*(textmessage+i)) == toupper(harf))
		{
			sayac++;
			if(sayac==1)
			{
				printf("%s cumlesinde, %c harfi ilk %p adresinde kullanildi\n",textmessage,harf,textmessage+i);
			}
		}
	}
	printf("%c harfi %d kez kullanildi",harf,sayac);
}
