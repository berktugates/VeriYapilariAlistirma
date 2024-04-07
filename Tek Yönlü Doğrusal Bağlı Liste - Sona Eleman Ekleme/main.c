#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int veri;
	struct dugum *gosterici;
};

struct dugum *bas=NULL;
struct dugum *gecici=NULL;

void sonaEkle(int sayi){
	struct dugum *eklenen;
	eklenen = (struct dugum *) malloc (sizeof(struct dugum *));
	eklenen->veri=sayi;
	eklenen->gosterici=NULL;
	
	if(bas==NULL){
		bas = eklenen;
	}
	else{
		gecici = bas;
		while(gecici->gosterici != NULL){
			gecici= gecici->gosterici;			
		}
		gecici->gosterici = eklenen;
	}
}

void yazdir(){
	gecici = bas;
	while(gecici->gosterici != NULL){
		printf("%d ", gecici->veri);
		gecici=gecici->gosterici;
	}
	printf("%d", gecici->veri);
}

int main(int argc, char *argv[]) {
	
	int adet,sayi,i=0;
	printf("Sona kac tane eleman eklemek istiyorsunuz: ");
	scanf("%d", &adet);
	
	for(i;i<adet;i++){
		printf("\nEklemek istediginiz sayiyi giriniz: ");
		scanf("%d", &sayi);
		sonaEkle(sayi);
		yazdir();
	}
	
	return 0;
}
