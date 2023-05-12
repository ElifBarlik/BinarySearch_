#include <stdio.h>
#include <stdlib.h>

//tanimlamalar
struct queue {
	int data;
	struct queue *next;
} *front, *rear, *temp, *new1 ;

//EnQueueu islemi
void ekleme(int deger){
	new1 = (struct queue*)malloc(sizeof(struct queue));
	
	new1->data = deger;
	new1->next=NULL;
	
	//kuyruk bossa
	if (front==NULL){
		front=new1;
		rear=new1;
	}
	else
	{
		rear->next= new1;
		rear=new1;	
	}
	printf("\n%d kuyruga eklendi.\n", new1->data);	
}


//Dequeue islemi
void silme(){
	temp = front;
	if (front==NULL) {
		printf("\nKuyruk Bos");
	}
	else
	{
		if (front ==rear)
		{
			printf("\n%d kuyruktan silindi.\n", front->data);
			front=NULL;
			rear=NULL;
			free(temp);
			temp=NULL;
		}
		else
		{
			printf("\n%d kuyruktan silindi.\n", front->data);
			front=front->next; //en basta olanin yerine bir sonraki en basa gelir.
			temp->next=NULL; //gecerli olanin bir sonraki adres degeri bosalir.
			free(temp);
			temp = NULL;
		}
		
	}
}


//kuyruk elemanlarini ekranda goster
void goruntule(){
	temp = front;
	if (front==NULL){
		printf("\nKuyruk Bos\n");
	}
	else
	{
		printf("\nKuyruk icindeki elemanlar: ");
		while(temp!=NULL){
			printf("\t%d", temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
	
}


int main(int argc, char *argv[]) {
	int secim, sayi;
	while(1){
	printf("\n1. Ekleme\n2. Silme\n3. Goruntuleme\n4. Cikis\n\nSeciminiz: ");
	scanf("%d",&secim);
	switch(secim)
	{
		
		case 1: printf("\nEklenecek sayi: ");
				scanf("%d",&sayi);
				ekleme(sayi);
				break;
		case 2: silme();
				break;
		case 3: goruntule();
				break;
		case 4: printf("\nCikis yapildi.");
				break;
		default : printf("\nGecersiz secim.");
	}
	if (secim==4)
		break;
}
	return 0;
}

