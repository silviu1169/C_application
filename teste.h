#pragma once

#include "Produs.h"
#include "store.h"
#include "storeservice.h"

#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include <stdio.h>




/*
	Functie care testeaza storeservice-ul
*/
void testeStoreService();

/*
	Functie care testeaza entitatea Store cu tot cu functiile din store.h 
*/
void testeStore();

/*
	Functie care testeaza entitatea Produs cu tot cu functiile din Produs.h
*/
void testeProdus();


/*
	Functie care ruleaza toate testele
*/
void runTeste();

