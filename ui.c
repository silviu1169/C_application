#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "Produs.h"
#include "store.h"
#include "storeservice.h"
#include "teste.h"
#include "sort.h"

#include <stdio.h>
#include <stdlib.h>
#include "ui.h"

void readProduct(BigList* list) {
	/* Reads the characteristics of product from input and adds to the store */
	int id;
	char type[30];
	char producer[30];
	char model[30];
	int price;
	int amount;
	printf("Identifier:"); scanf_s("%d", &id);
	printf("Type:"); scanf_s("%s", type, sizeof(type));
	printf("Producer:"); scanf_s("%s", producer, sizeof(producer));
	printf("Model:"); scanf_s("%s", model, sizeof(model));
	printf("Price:"); scanf_s("%d", &price);
	printf("Amount:"); scanf_s("%d", &amount);
	addProduct(list, id, type, producer, model, price, amount);
}

void printStore(Store* storelist) {

	int i = 0;
	
	printf("id |type|producer|model|price|amount\n"); 

	for (; i < storelist->dimension; i++) {
		Product* s = get(storelist, i);
		printf(" %d     %s    %s     %s    %d    %d\n", s->id, s->type, s->producer, s->model, s->price, s->amount);
	}
}

void deleteProduct(BigList* list) {
	int id = -1;
	printf("Dati ID-ul produsului care trebuie sters: ");
	scanf_s("%d", &id);
	deleteEnt(list, id);

}

void updateProduct1(BigList* list) {
	int id;
	char type[30];
	char producer[30];
	char model[30];
	int price;
	int amount;
	printf("Identifier for the product you want to update:"); scanf_s("%d", &id);
	printf("Updated Type:"); scanf_s("%s", type, sizeof(type));
	printf("Updated Producer:"); scanf_s("%s", producer, sizeof(producer));
	printf("Updated Model:"); scanf_s("%s", model, sizeof(model));
	printf("Updated Price:"); scanf_s("%d", &price);
	printf("Updated Amount:"); scanf_s("%d", &amount);
	updateEnt(list, id, type, producer, model, price, amount);
}


void destroy(BigList* list) {
	destroyBigList(list);
}

void sorting(BigList* list, FunctieComparare fc) {
	Store* sorted = sortingService(list, fc);
	printStore(sorted);
	destroySt(sorted);
}



void filtering(BigList* list, FunctieFiltrare f, getAtributeChar g) {
	printf("Filter substring:");
	char str[30];
	scanf_s("%s", str, sizeof(str));
	Store* filterS = f(list, str, g);
	printStore(filterS);
	//
	destroySt(filterS);
}

void uiUndo(BigList* list) {
	if (list->undolist->dimension == 0) {
		printf("No more UNDO! \n");
	}
	else {
		Store* s = list->storelist;
		list->storelist = list->undolist->elements[list->undolist->dimension - 1];
		list->undolist->dimension--;
		destroySt(s);
	}
}



void run() {
	//Store* s = newstore(destroyProduct, copyProduct);
	BigList list = createBigList();
	
	int run = 1;
	while(run) {
		
		int cmd = 0;
		printf("Commands:\n   1 Add\n   2 Print\n   3 Delete by ID\n   4 Update Product\n   5 Sorted type -growing\n");
		printf("   6             -decreasing\n   7 Sorted producer -growing\n   8                 -decreasing\n   9 Sorted model- growing\n");
		printf("  10             - decreasing\n  11 Sorted price -growing\n  12              -decreasing\n");
		printf("  13 Sorted amount -growing\n  14               -decreasing\n  15 Filter type\n  16 Filter Producer\n  17 Filter Model\n");
		printf("  18 UNDO\n   0 Exit\nCommand:");
		scanf_s("%d", &cmd);
		switch (cmd) {
		case 1:
			readProduct(&list);
			break;
		case 2:
			printStore(list.storelist);
			break;
		case 3:
			deleteProduct(&list);
			break;
		case 4:
			updateProduct1(&list);
			break;
		case 5:
			sorting(&list, cmpType);
			break;
		case 6:
			sorting(&list, cmpTypeDecreasing);
			break;
		case 7:
			sorting(&list, cmpProducer);
			break;
		
		case 8:
			sorting(&list, cmpProducerDecreasing);
			break;
		case 9:
			sorting(&list, cmpModel);
			break;
		case 10:
			sorting(&list, cmpModelDecreasing);
			break;
		case 11:
			sorting(&list, cmpPrice);
			break;
		case 12:
			sorting(&list, cmpPriceDecreasing);
			break;
		case 13:
			sorting(&list, cmpAmount);
			break;
		case 14:
			sorting(&list, cmpAmountDecreasing);
			break;
		case 15:
			filtering(&list, getAllProduct, getType);
			break;
		case 16:
			filtering(&list, getAllProduct, getProducer);
			break;
		case 17:
			filtering(&list, getAllProduct, getModel);
			break;
		case 18:
			uiUndo(&list);
			break;
		case 0:
			run = 0;
			break;
		default:
			printf("Comanda invalida!!!\n");
		}
	}
	destroyBigList(&list);

}

int main() {
	
	/*
			TESTELE TREBUIE REFACUTE PENTRU CA ASTEA DE ACUM SUNT PENTRU LAB UL TRECUT CAND AVEAM DOAR O LISTA\
	
	*/


	//Rulam testele
	runTeste();

	//run();
	_CrtDumpMemoryLeaks();
	return 0;
}
