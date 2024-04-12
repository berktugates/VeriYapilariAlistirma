#include <stdio.h>
#include <stdlib.h>

#define BOY 10

struct stack{
	int dizi[BOY];
	int indis;
};

struct stack y1;

void elemanEkle(int sayi){
	if(y1.indis == BOY -1){
		printf("Bu stack tamamen dolu!");
	}
	else{
		y1.indis++;
		y1.dizi[y1.indis] = sayi;
	}
};

void elemanSil(){
	if(y1.indis == -1){
		printf("Bu stack zaten bos!");
	}
	else{
		int cikanSayi = y1.dizi[y1.indis];
		printf("Cikan sayi: %d\n",cikanSayi);
		y1.indis--;
	}
};

void yazdir(){
	system("cls");
	int i= y1.indis;
	if(y1.indis == -1){
		printf("Bu stack bos!");
	}
	else{
		for(i;i>-1;i--){
			printf("%d\n",y1.dizi[i]);
		}
	}	
};

int main(int argc, char *argv[]) {
	
	y1.indis = -1;
	int secim,sayi;
	
	while(1==1){
		printf("Stack'e eleman eklemek icin 1'e basiniz\n");
		printf("Stack'ten eleman silmek icin 2'ye basiniz\n");
		printf("Elemanlari yazdirmak icin 3'e basiniz\n");
		printf("Cikis yapmak icin 4'e basiniz\n");
		printf("Seciminizi yapiniz: ");
		scanf("%d",&secim);
		
		switch(secim){
			case 1:
				printf("Eklemek istediginiz sayiyi giriniz: ");
				scanf("%d",&sayi);
				elemanEkle(sayi);
				break;
			case 2:
				elemanSil();
				break;
			case 3:
				yazdir();
				break;
			case 4:
				return 0;
				break;
			default:
				printf("Hatali secim yaptiniz!");
				break;				
		}
	}
	
	
	
	
	
	return 0;
}
