#include <stdio.h>
#include <stdlib.h>
int yer=1;
int dizi[2];
void push(int a)
{
	dizi[yer]=a;
	yer--;
}
int pop()
{
	yer++;
	return dizi[yer];
}
int main()
{
	push(5);
	push(10);
	printf("******\n");
	printf("%d\n",pop());
	printf("%d\n",pop());
	
}
