#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int veri;
	struct dugum *gosterici;
};
struct dugum *bas=NULL;
struct dugum *gecici=NULL;

void basaEkle(int sayi){
	struct dugum *eklenen;
	eklenen = (struct dugum *) malloc(sizeof(struct dugum *));
	eklenen->veri = sayi;
	eklenen->gosterici = bas;
	bas = eklenen;
}

void sonaEkle(int sayi){
	struct dugum *eklenen;
	eklenen = (struct dugum *) malloc(sizeof(struct dugum *));
	eklenen->veri = sayi;
	eklenen->gosterici = NULL;
	if(bas->gosterici == NULL){
		bas=eklenen;
	}
	else{
		gecici=bas;
		while(gecici->gosterici != NULL){
			gecici = gecici->gosterici;
		}
		gecici->gosterici = eklenen;
	}
}

void arayaEkle(int n, int sayi){
	struct dugum *eklenen;
	eklenen = (struct dugum *) malloc(sizeof(struct dugum *));
	eklenen->veri = sayi;
	
	gecici = bas;
	while(gecici->gosterici->veri != n){
		gecici = gecici->gosterici;
	}
	
	struct dugum *gecici2;
	gecici2 = (struct dugum *) malloc(sizeof(struct dugum *));
	
	gecici2 = gecici->gosterici;
	gecici->gosterici = eklenen;
	eklenen->gosterici = gecici2;
}

void sondanSil(){
	if(bas->gosterici !=NULL){
		gecici = bas;
		while(gecici->gosterici->gosterici != NULL){
			gecici = gecici->gosterici;
		}
		free(gecici->gosterici);
		gecici->gosterici = NULL;
	}
	else{
		gecici = bas->gosterici;
		free(bas);
		bas = gecici;
	}
}

yazdir(){
	system("cls");
	gecici = bas;
	while(gecici->gosterici !=NULL){
		printf("%d " ,gecici->veri);
		gecici=gecici->gosterici;
	}
	printf("%d",gecici->veri);
}

int main(int argc, char *argv[]) {
	int adet,i=0,secim,sayi,n;
	printf("Kac adet islem yapmak istiyorsunuz: ");
	scanf("%d",&adet);
	
	for(i;i<adet;i++){
		printf("\nBasa eklemek icin 1'e basiniz\n");
		printf("Sona eklemek icin 2'ye basiniz\n");
		printf("Ortaya eklemek icin 3'e basiniz\n");
		printf("Sondan silmek icin 4'e basiniz\n");
		
		printf("Hangi islemi seciyorsunuz: ");
		scanf("%d",&secim);
		
		switch(secim){
			case 1:
				printf("Basa eklemek istediginiz elemani giriniz: ");
				scanf("%d",&sayi);
				basaEkle(sayi);
				yazdir();
				break;
			case 2:
				printf("Sona eklemek istediginiz sayiyi giriniz: ");
				scanf("%d",&sayi);
				sonaEkle(sayi);
				yazdir();
				break;
			case 3:
				printf("Hangi sayidan once eklemek istediginizi giriniz: ");
				scanf("%d",&n);
				printf("Araya eklemek istediginiz sayiyi giriniz: ");
				scanf("%d",&sayi);
				arayaEkle(n,sayi);
				yazdir();
				break;
			case 4:
				sondanSil();
				yazdir();
				break;
			default:
				printf("Hatali giris yaptiniz!");
				break;
		}
	}
	return 0;
}
