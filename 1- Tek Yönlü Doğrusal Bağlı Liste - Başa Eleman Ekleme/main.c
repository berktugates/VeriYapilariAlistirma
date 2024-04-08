#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int veri;
	struct dugum *gosterici;
};

struct dugum *bas = NULL;
struct dugum *gecici = NULL;

void basaElemanEkle(int sayi){
	struct dugum * eklenecek;
	eklenecek = (struct dugum *) malloc (sizeof(struct dugum *));
	eklenecek->veri = sayi;
	eklenecek->gosterici = bas;
	bas = eklenecek;
};

void yazdir(){
	gecici = bas;
	
	while(gecici->gosterici != NULL){
		printf("%d ", gecici->veri);
		gecici = gecici->gosterici;
	}
	printf("%d", gecici->veri);
};

int main(int argc, char *argv[]) {
	
	int adet,i=0,sayi;
	
	printf("Kac adet sayi eklemek istiyorsunuz: ");
	scanf("%d",&adet);
	
	for(i;i<adet;i++){
		printf("\nBasa eklemek istediginiz sayiyi giriniz: ");
		scanf("%d", &sayi);
		basaElemanEkle(sayi);
		yazdir(); // Her eklenildiðinde görelim.
	}
	
	return 0;
}
