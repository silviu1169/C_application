#pragma once
#include "Produs.h"

typedef void* Entity;
/*
	Functie pentru dealocarea unui element
*/
typedef void(*DestroyF)(Entity);

/*
  Functie pentru copierea unui element
*/
typedef Entity(*CopyF)(Entity);

typedef struct {
	Entity* elements ;
	int dimension;
	int capacity;
	DestroyF dstf;
	CopyF cpyf;

} Store;

int addEntity(Store*, Entity);
/* Adauga o entitate in magazin */

int deleteEntity(Store*, int);
/* Sterge o entitate din magazin */

void ensureCapacity(Store* );

Store* newstore(DestroyF, CopyF);
/* Create a new store */

void destroyStore(Store*);
/* Deletes the actual store */

int updateProduct(Store*, Product*);

int searchById(Store*, int);

/*
	Functie care returneaza o copie a entitati store
*/
Store* getCopyStore(Store*);

/*
	Functie care returneaza elementul de pe o pozitie data
*/
Entity get(Store*, int);

Entity set(Store*, int, Entity);


