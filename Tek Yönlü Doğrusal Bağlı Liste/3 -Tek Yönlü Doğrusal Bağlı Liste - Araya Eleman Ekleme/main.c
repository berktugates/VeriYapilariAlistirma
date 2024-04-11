#include <stdio.h>
#include <stdlib.h>

// Araya ekleme islemini yapmak icin basa veya sona ekleme yapmamýz lazým dugumler eklendikten sonra araya ekleme islemi yapilabilir.

struct dugum{
	int veri;
	struct dugum *gosterici;
};

struct dugum *bas=NULL;
struct dugum *gecici=NULL;

void basaEkle(int sayi){
	struct dugum *eklenen;
	eklenen = (struct dugum *) malloc (sizeof(struct dugum *));
	eklenen->veri = sayi;
	eklenen->gosterici = bas;
	bas=eklenen;
};

void arayaEkle(int n, int sayi){
	struct dugum * eklenen;
	eklenen = (struct dugum *) malloc (sizeof(struct dugum *));
	eklenen->veri = sayi;
	
	gecici = bas;
	while(gecici->gosterici->veri != n){
		gecici = gecici->gosterici;
	}
	
	struct dugum * gecici2;
	gecici2 = (struct dugum *) malloc (sizeof(struct dugum *));
	
	gecici2 = gecici->gosterici;
	gecici->gosterici = eklenen;	
	eklenen->gosterici = gecici2;
};

void yazdir(){
	gecici = bas;
	while(gecici->gosterici != NULL){
		printf("%d ", gecici->veri);
		gecici = gecici->gosterici;
	}	
	printf("%d",gecici->veri);
};

int main(int argc, char *argv[]) {
	int adet,sayi,secim,i=0,n;
	
	printf("Kac adet sayi eklemek istiyorsunuz: ");
	scanf("%d",&adet);
	
	for(i;i<adet;i++){
		printf("\nBasa sayi eklemek icin 1'e basiniz\n");
		printf("Araya sayi eklemek icin 2'ye basiniz\n");
		printf("Seciminizi yapiniz: ");
		scanf("%d", &secim);
		switch(secim){
			case 1:
				printf("Basa eklemek istediginiz sayiyi giriniz: ");
				scanf("%d",&sayi);
				basaEkle(sayi);
				yazdir();
				break;
			case 2:
				printf("Hangi sayidan once eklemek istiyorsunuz: ");
				scanf("%d",&n);
				printf("Hangi sayiyi eklemek istiyorsunuz: ");
				scanf("%d",&sayi);
				arayaEkle(n,sayi);
				yazdir();
				break;
			default:
				printf("Hatali giris yaptiniz!");
				break;
		}
	}
	
	return 0;
}
