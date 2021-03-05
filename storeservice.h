#pragma once
#include "store.h"
#include "Produs.h"
#include "sort.h"

typedef struct{
	Store* storelist;
	Store* undolist;
} BigList;

/*
	Functie care creaza o lista ce contine o lista de produse si o lista de undo
*/
BigList createBigList();

/*
	Functie care dealoca lista ce contine lista de produse si lista de undo.
*/
void destroyBigList(BigList* );
/*
	Functie care adauga o entitate in store
*/
int addProduct(BigList* list, int, char*, char*, char*, int, int);


/*
	Functie care sterge o entitate din store
*/
int deleteEnt(BigList* list,int );


/*
	Functie care face update la un produs
*/
int updateEnt(BigList* , int, char*, char*, char*, int, int);


/*
	Functie care dealoca memoria ocupata de store
*/
void destroySt(Store*);

int cmpType(Entity, Entity);

int cmpTypeDecreasing(Entity, Entity);

int cmpProducer(Entity, Entity);

int cmpProducerDecreasing(Entity, Entity);

int cmpModel(Entity, Entity);

int cmpModelDecreasing(Entity, Entity);

int cmpPrice(Entity, Entity);

int cmpPriceDecreasing(Entity, Entity);

int cmpAmount(Entity, Entity);

int cmpAmountDecreasing(Entity, Entity);

Store* getAllProduct(BigList* list,char*, getAtributeChar );

int cmpIntDecreasing(Entity e1, Entity e2, getAtributeInt f);

int cmpCharDecreasing(Entity e1, Entity e2, getAtributeChar f);

Store* sortingService(BigList* list, FunctieComparare);
