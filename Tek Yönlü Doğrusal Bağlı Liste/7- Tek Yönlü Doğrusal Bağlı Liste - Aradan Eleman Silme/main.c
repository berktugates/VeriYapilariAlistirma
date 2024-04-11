#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int veri;
	struct dugum *gosterici;
};
struct dugum *bas = NULL;
struct dugum *gecici = NULL;

void basaEkle(int sayi){
	struct dugum *eklenen;
	eklenen=(struct dugum *) malloc(sizeof(struct dugum *));
	eklenen->veri = sayi;
	eklenen->gosterici = bas;
	bas=eklenen;
};

void sonaEkle(int sayi){
	struct dugum *eklenen;
	eklenen=(struct dugum *) malloc(sizeof(struct dugum *));
	eklenen->veri=sayi;
	eklenen->gosterici = NULL;
	
	if(bas->gosterici == NULL){
		bas=eklenen;
	}
	else{
		gecici=bas;
		while(gecici->gosterici!=NULL){
			gecici=gecici->gosterici;
		}
		gecici->gosterici = eklenen;
	}
};

void arayaEkle(int n,int sayi){
	struct dugum *eklenen;
	eklenen = (struct dugum *) malloc(sizeof(struct dugum *));
	eklenen->veri = sayi;
	
	gecici=bas;
	while(gecici->gosterici->veri != n){
		gecici = gecici->gosterici;
	}
	
	struct dugum *gecici2;
	gecici2 = (struct dugum *)malloc(sizeof(struct dugum *));
	
	gecici2 = gecici->gosterici;
	gecici->gosterici = eklenen;
	eklenen->gosterici = gecici2;
};

void bastanSil(){
	gecici = bas->gosterici;
	free(bas);
	bas = gecici;
}

void sondanSil(){
	if(bas->gosterici != NULL){
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

void aradanSil(int sayi){
	gecici = bas;
	if(gecici->veri == sayi){
		bastanSil();
	}
	else{
		struct dugum *gecici2;
		gecici2 = (struct dugum *) malloc(sizeof(struct dugum *));
		
		while(gecici->gosterici->veri != sayi){
			gecici = gecici->gosterici;
		}
		if(gecici->gosterici->gosterici == NULL){
			sondanSil();
		}
		else{
			gecici2 = gecici->gosterici->gosterici;
			free(gecici->gosterici);
			gecici->gosterici = gecici2;
		}
	}
};

void yazdir(){
	system("cls");
	gecici = bas;
	while(gecici->gosterici != NULL){
		printf("%d ",gecici->veri);
		gecici=gecici->gosterici;
	}
	printf("%d",gecici->veri);	
}

int main(int argc, char *argv[]) {
	
	int adet,i=0,secim,sayi,n;

	printf("Kac adet islem yapmak istiyorsunuz: ");
	scanf("%d",&adet);
	
	for(i;i<adet;i++){
		printf("\nBasa eleman eklemek icin 1'e basiniz: \n");
		printf("Sona eleman eklemek icin 2'ye basiniz: \n");
		printf("Araya eleman eklemek icin 3'e basiniz: \n");
		printf("Bastan eleman silmek icin 4'e basiniz: \n");
		printf("Sondan eleman silmek icin 5'e basiniz: \n");
		printf("Aradan eleman silmek icin 6'ya basiniz: \n");
		printf("Hangi islemi yapmak istiyorsunuz: ");
		scanf("%d",&secim);
		
		switch(secim){
			case 1:
				printf("Basa eklemek istediginiz sayiyi giriniz: ");
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
				bastanSil();
				yazdir();
				break;
			case 5:
				sondanSil();
				yazdir();
				break;
			case 6:
				printf("Aradan silmek istediginiz sayiyi giriniz: ");
				scanf("%d",&sayi);
				aradanSil(sayi);
				yazdir();
				break;
			default:
				printf("Hatali giris yaptiniz!");
				break;
		}
	}
	
	return 0;
}
