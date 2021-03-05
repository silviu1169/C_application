#pragma once
typedef struct {
	
	int id;             //Identificator unic
	char* type;			//Tipul produsului(laptop, frigider, televizor, etc.
	char* producer;		//Producatorul produsului
	char* model;		//Modelul produsului
	int price;			//Pretul produsului
	int amount;			//Cantitatea disponibila
	

} Product;


/*
Primeste caracteristicile unui produs, creaza entitatea Product si da un pointer la  entitatea Product 
*/
Product* createProduct(int, char*, char*, char*, int, int);


/*
	Primeste o entitate Product si o elimina din memorie 
*/
void destroyProduct(Product*);

/*
	Functie care copiaza un product si returneaza un pointer la copia respectiva.
*/
Product* copyProduct(Product*);

int getPrice(Product*);

int getAmount(Product*);

char* getType(Product*);

char* getProducer(Product*);

char* getModel(Product*);

int getID(Product*);




