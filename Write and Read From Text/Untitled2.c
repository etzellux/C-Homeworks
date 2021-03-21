#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void yaz()
{
	FILE *fp;
	fp = fopen("kayit.txt","a");
	char metin[100];
	printf("ENTRY:");
	gets(metin);
	strcat(metin,"\n");
	fputs(metin,fp);
	fclose(fp);
}
void oku()
{
	int sayac=0,i;
	FILE *fp;
	fp = fopen("kayit.txt","r");
	char metin[100];
	
	while(feof(fp)==0)
	{
		fgets(metin,100,fp);
		printf("%s",metin);
	}
	
	fclose(fp);
}
void main()
{
	int choice;
	while(1)
	{
		printf("To add an entry --> 1\nTo read the text --> 2\nTo exit -- 3 :");
		scanf("%d",&choice);
		fflush(stdin);
	
		if(choice == 1)
		{
			yaz();
		}
		else if(choice == 2)
		{
			oku();
		}
		else
		{
			break;
		}
	}
	
}
