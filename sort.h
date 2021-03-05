
#ifndef SORT_H_
#define SORT_H_

#include "store.h"
/*
   Tipul functie de comparare pentru 2 elemente
   returneaza 0 daca sunt egale, 1 daca o1>o2, -1 altfel
*/
typedef int(*FunctieComparare)(void* o1, void* o2);
typedef Store (*FunctieSortare)(void* s);

typedef int(*getAtributeInt)(void* o1);
typedef char*(*getAtributeChar)(void* o1);

typedef Store*(*FunctieFiltrare)(void* o1, char* str, getAtributeChar g);



/**
* Sorteaza in place
* cmpf - relatia dupa care se sorteaza
*/
void sort(Store* l, FunctieComparare cmpF);

#endif



