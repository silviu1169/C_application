
#include "store.h"
#include <stdlib.h>



/*
	Adauga un produs nou in store. 
*/
int addEntity(Store* s, Entity e) {    
	
	if (s->dimension < s->capacity) {
	
		s->elements[s->dimension] = e;
		s->dimension += 1;
	}
	else {
		ensureCapacity(s);
		addEntity(s, e);
	}
	return 0;
}

/*
	Functie care mareste capacitatea store-ului.
*/
void ensureCapacity(Store* s) {
	
	Entity* nElems = malloc(sizeof(Entity)*(s->capacity+ 2));
	//copy elems
	for (int i = 0; i < s->dimension; i++) {
	
		nElems[i] = s->elements[i];
	}
	//dealocate old vector
	free(s->elements);
	s->elements = nElems;
	s->capacity += 2;

}

/*
	Sterge o un produs din store. 
*/

int deleteEntity(Store* s, int id) {
	
	int i = 0;
	while(i<s->dimension){
		Product* p = get(s, i);
		if (p->id == id) {
			if (p->amount > 1){
				//If the amount of the Entity is greater than 1, than we'll decrease the amount
				p->amount -= 1;
				return 0;}
			else {
				//If the amount of the Entity is 1, than we'll delete Entity
				
				destroyProduct(p);
				for (int j = i; j < s->dimension - 1; j++)
					s->elements[j] = s->elements[j + 1];
				s->dimension -= 1;
				return 0;
			}
			
			
		}
		i++;
	}
	
	
	return 0;
}


/*
	Functie care creeaza o entitate Store si returneaza pointerul la entitatea respectiva.
*/
Store* newstore(DestroyF dstf, CopyF cpyf) {

	Store* s = malloc(sizeof(Store));
	s->dimension = 0;
	s->capacity = 2;
	s->elements = malloc(sizeof(Entity) * s->capacity);
	s->dstf = dstf;
	s->cpyf = cpyf;
	return s;
}

/*
	Primeste un pointer la entitatea Store si dealoca memoria ocupata de entitate.
*/
void destroyStore(Store* s) {

	int i = 0;
	for (; i < s->dimension; i++) {
		destroyProduct(s->elements[i]);	
	}
	free(s->elements);
	free(s);


}
/*
	Functie care face update la un produs. Primeste un pointer la produsul cu caracteristicile actualizate, distruge produsul vechi
	si il pune pe cel actualizat.
*/
int updateProduct(Store* s, Product* e) {
	int i = 0;
	for (; i < s->dimension; i++) {
		Product* p = get(s, i);
		if (p->id == e->id){
			destroyProduct(set(s,i,e));
			
			return 0;
		}
	}
	return -1;


}
/*
	Functie care primeste un int -id- si returneaza 10 daca id ul este in lista de elemente sau 11 in caz contrar
*/
int searchById(Store* s, int id) {

	for (int i = 0; i < s->dimension; i++) {
		Product* p = get(s, i);
		if (p->id == id) {
			return 10;
		}
	}
	return 11;
}

/*
	Functie care returneaza un pointer la o copie a entitati store
*/
Store* getCopyStore(Store* s) {

	Store* storeCopy = malloc(sizeof(Store));
	storeCopy->dimension = s->dimension;
	storeCopy->capacity = s->capacity;
	storeCopy->elements = malloc(sizeof(Product)*s->dimension);
	storeCopy->cpyf = s->cpyf;
	storeCopy->dstf = s->dstf;
	for (int i = 0; i < s->dimension; i++) {
		storeCopy->elements[i] = copyProduct(s->elements[i]);
		
	}
	return storeCopy;
}

/*
	Functie care returneaza elementul de pe o pozitie data
*/
Entity get(Store* s, int i) {
	return s->elements[i];
}

Entity set(Store* s, int poz, Entity e) {
	Entity rez = s->elements[poz];
	s->elements[poz] = e;
	return rez;

}