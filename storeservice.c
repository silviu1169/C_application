#include "store.h"
#include "Produs.h"
#include "sort.h"
#include "storeservice.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



BigList createBigList() {
	BigList list;
	list.storelist = newstore(destroyProduct, copyProduct);
	list.undolist = newstore(destroyProduct, copyProduct);
	return list;
}

void destroyBigList(BigList* list) {
	destroyStore(list->storelist);
	if (list->undolist->dimension > 0)
		for (int i = 0; i < list->undolist->dimension; i++) {
			destroyStore(list->undolist->elements[i]);
		}
	else
		destroyStore(list->undolist);

}

/*
	Functie care adauga un nou produs in store.
*/
int addProduct(BigList* list, int id, char* type, char* producer, char* model, int price, int amount) {

	Entity e = createProduct(id, type, producer, model, price, amount);
	Store* copie = getCopyStore(list->storelist);
	addEntity(list->undolist, copie);
	
	
	addEntity(list->storelist, e);

	return 0;
}
/*
	Functie care sterge un produs din store.
*/
int deleteEnt(BigList* list, int id) {
	Store* copie = getCopyStore(list->storelist);
	addEntity(list->undolist, copie);
	deleteEntity(list->storelist, id);
	return 0;
}


/*
	Functie care primeste un pointer la store si il distruge.
*/
void destroySt(Store* s) {
	destroyStore(s);
}

/*
	Functia returneaza valoarea 0 daca entitatea a fost gasita si updatata sau valoarea -1 daca entitatea nu exista in store
*/
int updateEnt(BigList* list, int id, char* type, char* producer, char* model, int price, int amount) {

	int i = 0;
	for (; i < list->storelist->dimension; i++) {
		if (getID(get(list->storelist,i)) == id) {

			if (searchById(list->storelist, id) == 10) {

				Entity e = createProduct(id, type, producer, model, price, amount);
				Store* copie = getCopyStore(list->storelist);
				addEntity(list->undolist, copie);
				updateProduct(list->storelist, e);
				return 0;
			}
		}
	}
	return -1;

}


int cmpType(Product* e1, Product* e2) {
	return strcmp(e1->type, e2->type);
}

int cmpTypeDecreasing(Product* e1, Product* e2) {
	int i = strcmp(e1->model, e2->model);
	if (i == 0) return 0;
	else {
		if (i < 0) return 1;
		else {
			return -1;
		}
	}

}

int cmpProducer(Product* e1, Product* e2) {
	return strcmp(e1->producer, e2->producer);
}

int cmpProducerDecreasing(Product* e1, Product* e2) {
	int i = strcmp(e1->model, e2->model);
	if (i == 0) return 0;
	else {
		if (i < 0) return 1;
		else {
			return -1;
		}
	}

}


int cmpModel(Product* e1, Product* e2) {
	return strcmp(e1->model, e2->model);
}

int cmpModelDecreasing(Product* e1, Product* e2) {
	int i = strcmp(e1->model, e2->model);
	if (i == 0) return 0;
	else {
		if (i < 0) return 1;
		else {
			return -1;
		}
	}

}

int cmpPrice(Product* e1, Product* e2) {
	if (e1->price == e2->price) {
		return 0; }
	else {
		if (e1->price > e2->price) {
			return 1;}
		else return -1;
	}
}

int cmpAmount(Product* e1, Product* e2) {
	if (e1->amount == e2->amount) {
		return 0;}
	else {
		if (e1->amount > e2->amount) {
			return 1;}
		else return -1;}
}

int cmpAmountDecreasing(Product* e1, Product* e2) {
	if (e1->amount == e2->amount) {
		return 0;}
	else {
		if (e1->amount < e2->amount) {
			return 1;}
		else return -1;}
}

int cmpPriceDecreasing(Product* e1, Product* e2) {
	if (e1->price == e2->price) {
		return 0;}
	else {
		if (e1->price < e2->price) {
			return 1;}
		else return -1;}
}

Store* sortingService(BigList* list, FunctieComparare fc) {
	Store* copyS = getCopyStore(list->storelist);
	sort(copyS, fc);
	return copyS;

}

Store* getAllProduct(BigList* list, char* subString, getAtributeChar g) {
	if (subString == NULL || strlen(subString) == 0) {
		return getCopyStore(list->storelist);
	}
	Store* rez = newstore(destroyProduct, copyProduct);
	for (int i = 0; i < list->storelist->dimension; i++) {
		Product* p = get(list->storelist, i);
		if (strstr( g (get ( list->storelist, i ) ) , subString) != NULL) {
			addEntity(rez, copyProduct(p));
		}
	}
	return rez;
}