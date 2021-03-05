#include "Produs.h"
#include "store.h"
#include "storeservice.h"
#include "sort.h"

#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include <stdio.h>




void testeStoreService() {
	
	BigList list = createBigList();
	assert(addProduct(&list, 1, "masina", "audi", "a3", 1000, 1) == 0);
	assert(deleteEnt(&list, 1) == 0);
	addProduct(&list, 1, "masina", "audi", "a3", 1000, 1);
	assert( updateEnt(&list, 1, "masina2", "audi2", "a33", 1000, 2) == 0);

	//assert(list.storelist->elements[0]->amount == 2);
	
	assert(updateEnt(&list, 1, "masina2", "audi2", "a33", 1000, 2) == 0);
	assert(updateEnt(&list, 3, "masina2", "audi2", "a33", 1000, 2) == -1);
	
	Store* s = sortingService(&list, cmpAmountDecreasing);
	
	destroySt(getAllProduct(&list,"", getProducer));
	destroySt(getAllProduct(&list, "a", getProducer));
	destroySt(s);
	destroyBigList(&list);

	BigList list1 = createBigList();
	destroyBigList(&list1);
}


void testeStore() {
	Store* s = newstore(destroyProduct, copyProduct);
	Product* produs = createProduct(1, "masina", "audi", "a3", 1000, 1);
	Product* produs2 = createProduct(2, "masina2", "audi2", "a33", 1000, 2);
	Product* produs3 = createProduct(3, "masina2", "audi2", "a33", 1000, 2);
	assert(addEntity(s, produs) == 0);
	assert(deleteEntity(s, 1) == 0);
	destroyStore(s);
	s = newstore(destroyProduct, copyProduct);
	addEntity(s, produs2);
	addEntity(s, produs3);
	assert(deleteEntity(s, 5) == 0);
	assert(deleteEntity(s, 3) == 0);
	destroyStore(s);
	Product* produs4 = createProduct(1, "masina", "audi", "a3", 1000, 1);
	Product* produs5 = createProduct(2, "masina2", "audi2", "a33", 1000, 2);
	Product* produs6 = createProduct(3, "masina2", "audi2", "a33", 1000, 2);
	Product* produs7 = createProduct(4, "masina2", "audi2", "a33", 1000, 2);
	Product* produs8 = createProduct(5, "masina2", "audi2", "a33", 1000, 2);
	Product* produs9 = createProduct(99, "masina2", "audi2", "a33", 1000, 2);
	Product* produs10 = createProduct(5, "amasina2", "aaudi2", "aa33", 11000, 12);
	s = newstore(destroyProduct, copyProduct);
	addEntity(s, produs4);
	addEntity(s, produs5);
	addEntity(s, produs6);
	addEntity(s, produs7);
	addEntity(s, produs8);
	assert(searchById(s, 99) == 11);
	assert(searchById(s, 4) == 10);
	assert(updateProduct(s, produs9) == -1);
	assert(updateProduct(s, produs10) == 0);
	destroyProduct(produs9);
	
	/*
		----------->TESTUL LA FUNCTIA DE SORTARE DIN sort.h
	*/
	sort(s, cmpAmountDecreasing);
	destroySt(s);

	s = newstore(destroyProduct, copyProduct);
	produs10 = createProduct(5, "amasina2", "aaudi2", "aa33", 11000, 12);
	addEntity(s, produs10);
	Store* copyS = getCopyStore(s);
	assert(copyS->capacity == s->capacity);
	assert(copyS->dimension == s->dimension);
	destroyStore(s);
	destroyStore(copyS);
	s = newstore(destroyProduct, copyProduct);
	produs10 = createProduct(5, "amasina2", "aaudi2", "aa33", 11000, 12);
	produs4 = createProduct(1, "masina", "audi", "a3", 1000, 1);
	addEntity(s, produs4);
	addEntity(s, produs10);
	assert(deleteEntity(s, 1) == 0);
	destroyStore(s);
	Product* produs12 = createProduct(1, "masina", "audi", "a3", 1000, 1);
	Product* produs13 = createProduct(2, "masina", "audi", "a3", 1000, 2);
	Product* produs14 = createProduct(2, "masina", "audi", "a3", 100, 2);
	Product* produs15 = createProduct(2, "n", "b", "b", 101, 3);
	Product* produs16 = createProduct(2, "i", "aa", "a1", 99, 1);
	assert(cmpType(produs12,produs13) == 0);
	assert(cmpTypeDecreasing(produs13, produs14) == 0);//type egal
	assert(cmpTypeDecreasing(produs14, produs15) == 1);
	assert(cmpTypeDecreasing(produs14, produs16) == -1);
	assert(cmpProducer(produs12, produs13) == 0);
	assert(cmpProducerDecreasing(produs13, produs14) == 0);//producer egal
	assert(cmpProducerDecreasing(produs14, produs15) == 1);
	assert(cmpProducerDecreasing(produs14, produs16) == -1);
	assert(cmpModel(produs12, produs13) == 0);
	assert(cmpModelDecreasing(produs13, produs14) == 0);//producer egal
	assert(cmpModelDecreasing(produs14, produs15) == 1);
	assert(cmpModelDecreasing(produs14, produs16) == -1);
	assert(cmpPrice(produs12, produs13) == 0);
	assert(cmpPrice(produs14, produs13) == -1);
	assert(cmpPrice(produs13, produs14) == 1);
	assert(cmpPriceDecreasing(produs13, produs12) == 0);//pret egal
	assert(cmpPriceDecreasing(produs16, produs13) == 1);//pret egal
	assert(cmpPriceDecreasing(produs13, produs16) == -1);//pret egal
	assert(cmpAmount(produs13, produs13) == 0);
	assert(cmpAmount(produs14, produs15) == -1);
	assert(cmpAmount(produs15, produs14) == 1);
	assert(cmpAmountDecreasing(produs13, produs14) == 0);//pret egal
	assert(cmpAmountDecreasing(produs13, produs16) == -1);//pret egal
	assert(cmpAmountDecreasing(produs16, produs13) == 1);//pret egal
	destroyProduct(produs14);
	destroyProduct(produs12);
	destroyProduct(produs13);
	destroyProduct(produs16);
	destroyProduct(produs15);
	s = newstore(destroyProduct, copyProduct);
	produs12 = createProduct(1, "masina", "audi", "a3", 1000, 1);
	produs13 = createProduct(2, "masina", "audi", "a3", 1000, 2);
	addEntity(s,produs12);
	destroySt(s);
	s = newstore(destroyProduct, copyProduct);
	produs12 = createProduct(1, "masina", "audi", "a3", 2, 1);
	produs13 = createProduct(2, "masina", "audi", "a3", 1, 2);
	addEntity(s, produs12);
	addEntity(s, produs13);
	destroySt(s);
}





void testeProdus() {
	// Product* createProduct(int, char*, char*, char*, int, int); ->cream un nou produs
	Product* produs = createProduct(1, "masina", "audi", "a3", 1000,1 );
	
	assert(strcmp(produs->type, "masina") == 0);
	assert(strcmp(produs->producer, "audi") == 0);
	assert(strcmp(produs->model, "a3") == 0);
	assert(produs->id == 1);
	assert(produs->price == 1000);
	assert(produs->amount == 1);

	Product* copieProdus = copyProduct(produs);
	
	assert(strcmp(produs->type, copieProdus->type) == 0);
	assert(strcmp(produs->producer, copieProdus->producer) == 0);
	assert(strcmp(produs->model, copieProdus->model) == 0);
	assert(produs->id == copieProdus->id);
	assert(produs->price == copieProdus->price);
	assert(getID(produs) == getID(copieProdus));
	assert(produs->amount == copieProdus->amount);
	assert(strcmp(getType(produs), "masina") == 0);
	assert(strcmp(getProducer(produs), "audi") == 0);
	assert(strcmp(getModel(produs), "a3") == 0);
	assert(getPrice(produs) == 1000);
	assert(getAmount(produs) == 1);


	//void destroyProduct(Product*); ->dealocam memoria ocupata de produs
	destroyProduct(produs);
	destroyProduct(copieProdus);
}






void runTeste() {

	testeProdus();
	testeStore();
	
	testeStoreService();
	
}


