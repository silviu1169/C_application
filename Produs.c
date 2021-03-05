
#include "Produs.h"

#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "store.h"
Product* createProduct(int id, char* type, char* producer, char* model, int price, int amount) {
	/* 
		Primeste caracteristicile unui produs, creaza entitatea Product si da un pointer la  entitatea Product 
	*/
	
	Product* p = malloc(sizeof(Product));
	int nr = 0;

	p->id = id;

	nr = strlen(type) + 1;
	p->type = malloc(sizeof(char)*nr);
	strcpy_s(p->type, nr, type);

	nr = strlen(producer) + 1;
	p->producer = malloc(sizeof(char)*nr);
	strcpy_s(p->producer, nr, producer);

	nr = strlen(model) + 1;
	p->model = malloc(sizeof(char)*nr);
	strcpy_s(p->model, nr, model);
	
	p->price = price;
	p->amount = amount;

	return p;
	}



void destroyProduct(Product* p) {
	/* 
		Primeste o entitate Product si o elimina din memorie
	*/
	free(p->model);
	free(p->producer);
	free(p->type);
	free(p);
	

}


Product* copyProduct(Product* produs) {
	/*
		Functie care copiaza un product si returneaza un pointer la copia respectiva.
	*/
	Product* produsCopy = malloc(sizeof(Product));
	int nr = strlen(produs->type) + 1;
	produsCopy->type = malloc(sizeof(char)*nr);
	strcpy_s(produsCopy->type, nr, produs->type);

	nr = strlen(produs->producer) + 1;
	produsCopy->producer = malloc(sizeof(char)*nr);
	strcpy_s(produsCopy->producer, nr, produs->producer);

	nr = strlen(produs->model) + 1;
	produsCopy->model = malloc(sizeof(char)*nr);
	strcpy_s(produsCopy->model, nr, produs->model);

	produsCopy->id = produs->id;
	produsCopy->price = produs->price;
	produsCopy->amount = produs->amount;
	return produsCopy;
}


int getPrice(Product* p) {
	return p->price;
}

int getAmount(Product* p) {
	return p->amount;
}

char* getType(Product* p) {
	return p->type;
}

char* getProducer(Product* p) {
	return p->producer;
}

char* getModel(Product* p) {
	return p->model;
}

int getID(Product* p) {
	return p->id;
}

