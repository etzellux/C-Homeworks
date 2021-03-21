#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double * vektorOlustur(double *vektor,int elemanSayisi)
{
	vektor = (double *) malloc(elemanSayisi*sizeof(double));
	//Parametre olarak alinan adresi baslangic alarak istenilen
	//eleman sayisinca malloc fonksiyonu kullanilarak yer ayrildi.
}
void vektorDoldur(double *vektor,int elemanSayisi)
{
	int a,i;
	for(i=0;i<elemanSayisi;i++)
	{
		a = rand()%10;
		*(vektor + i) = (double)a;
	}
	//Vektorun baslangic adresinden bitis adresine kadar tum elemanlarina 
	// [0,9] araligindan rastgele elemanlar a integeri kullanilarak atandi
}
void vektorYazdir(double *vektor,int elemanSayisi)
{
	int i;
	printf("*******************************\n");
	for(i=0;i<elemanSayisi;i++)
	{
		printf("%.4f ",*(vektor + i));
	}
	printf("\n");
	printf("*******************************\n");
	//Vektorun icindeki tum degerler tek tek okunarak printf fonksiyonu ile
	//elemanSayisinca bir for dongusu icerisinde ekrana yazdirildi.
}
double * noktasalCarpim(double *vektor1, double *vektor2,int elemanSayisi)
{
	int i; //i, for dongusunde kullaniliyor.
	double toplam=0.0,a;
	for(i=0;i<elemanSayisi;i++)
	{
		a = *(vektor1 + i) * *(vektor2 + i); // a degiskeni vektorlerin ayni siradaki elemanlarinin carpimini tutuyor.
		toplam+=a;							// toplam degiskenine a degerleri ekleniyor.
	}
	double *carpimsonucu;
	carpimsonucu = (double *) vektorOlustur(carpimsonucu,1);
	*(carpimsonucu) = pow((double)toplam,(double)0.5);
	return carpimsonucu;
	//For dongusunde iki vektorun ayni siradaki elemanlari carpilip bir
	//toplam degiskenine ataniyor. Toplam degiskeninin pow fonksiyonu ile 
	//karekoku aliniyor ve carpimsonucu pointerinin tuttugu adrese bu deger ataniyor.
	//carpimsonucu pointerý return ile geri donduruluyor. 
}
double * normbul(double *vektor,int elemanSayisi)
{
	int i; // i, for dongusunde kullaniliyor.
	double toplam=0,a;
	for(i=0;i<elemanSayisi;i++)
	{
		a = *(vektor + i) * *(vektor + i); // a degiskeni elemanlarin karesini tutuyor.
		toplam += a; 					  // toplam degiskenine a degerleri ekleniyor
	}
	double *normbulSonucu;
	normbulSonucu = (double *) vektorOlustur(normbulSonucu,1);
	*(normbulSonucu) = pow((double)toplam,(double)0.5);
	return normbulSonucu;
	//For dongusunde alinan vektorun elemanlarinin karesi aliniyor ve toplam degiskenine ataniyor.
	// pow fonksiyonu ile toplam degerinin karekoku aliniyor ve bu deger normbulSonucu pointerinin tuttugu
	// adrese ataniyor. normbulSonucu pointeri return ile geri donduruluyor.
}
double * cosbul(double *vektor1, double *vektor2,int elemanSayisi)
{
	double *vektor1_norm,*vektor2_norm,*noktacarpim;
	vektor1_norm = normbul(vektor1,elemanSayisi);
	vektor2_norm = normbul(vektor2,elemanSayisi);
	noktacarpim = (double *) noktasalCarpim(vektor1,vektor2,elemanSayisi);
	
	double *cosbulSonucu;
	cosbulSonucu = (double *) vektorOlustur(cosbulSonucu,1);
	*(cosbulSonucu) = *(noktacarpim) / (*vektor1_norm * *vektor2_norm);
	return cosbulSonucu;
}

void main()
{
	srand(time(NULL));
	int elemanSayisi;
	double *vektor1,*vektor2; //vektorlerin baslangic adresleri
	printf("Lutfen eleman sayisini giriniz:");
	scanf("%d",&elemanSayisi);
	
	vektor1 = (double *)vektorOlustur(vektor1,elemanSayisi);
	vektorDoldur(vektor1,elemanSayisi);
	vektor2 = (double *)vektorOlustur(vektor1,elemanSayisi);
	vektorDoldur(vektor2,elemanSayisi);
	
	printf("\nVektor1:\n");
	vektorYazdir(vektor1,elemanSayisi);
	printf("\nVektor2:\n");
	vektorYazdir(vektor2,elemanSayisi);
	printf("\n");
	
	printf("Vektorlerin nokta carpimlarinin sonucu:\n");
	double *noktasalCarpimSonucu = (double *) noktasalCarpim(vektor1,vektor2,elemanSayisi);
	vektorYazdir(noktasalCarpimSonucu,1);
	
	printf("Birinci vektorun normu:\n");
	double *normbulSonucu = (double *) normbul(vektor1,elemanSayisi);
	vektorYazdir(normbulSonucu,1);
	
	printf("iki vektorun arasindaki acinin cosinusu:\n");
	double * cosbulSonucu = (double *) cosbul(vektor1,vektor2,elemanSayisi);
	vektorYazdir(cosbulSonucu,1);
}
