//============================================================================
// Name        : 02_structure.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory.h>
#include <stdio.h>
#include "personne.h"
//#include

using namespace std;

//struct Adresse {
//	char *adresse1, adresse2;
//	int code_postale;
//	char *ville;
//};

//struct Client {
//	char *nom;
//	Adresse adresse;
//};

//struct Liste {
//	char *element;
//	Liste *liste;
//};

//struct Personne {
//	char *nom;
//	int age;
//} jean, albert;

union Valeur {   // size is 8 bytes, as double
	int nb_i;
	float nb_f;
	double nb_d;
};
enum TNB {t_aucun, t_int, t_float, t_double};
struct Nombre {
	char t_nb;
	Valeur val;
};

void afficher(Nombre& n) {
	switch (n.t_nb) {
	case t_int:
		printf("%d\t", n.val.nb_i);
		break;
	case t_float:
		printf("%f\t", n.val.nb_f);
		break;
	case t_double:
		printf("%f\t", n.val.nb_d);
		break;
	}
}

Nombre* lire_int() {
	Nombre* c = new Nombre;
	c->t_nb = t_int;
	printf("entier:");
	scanf("%d", &c->val.nb_i);
	return c;
}
Nombre* lire_float() {
	Nombre* c = new Nombre;
	c->t_nb = t_float;
	printf("float:");
	scanf("%f", &c->val.nb_f);
	return c;
}
Nombre* lire_double() {
	Nombre* c = new Nombre;
	c->t_nb = t_double;
	printf("double:");
	scanf("%lg", &c->val.nb_d);
	return c;
}

struct Rib {
	char* banque;
	int guichet;
	int compte;
};

struct NombreComplexe {
	double reel, imaginaire;
};
typedef NombreComplexe Complexe;
typedef NombreComplexe* PComplexe;
typedef NombreComplexe& RComplexe;


int main() {
	cout << "Hello World" << endl; // prints Hello World

	Complexe c1;
	PComplexe pc1 = &PComplexe;
	RComplexe rc1 = c1;

//	Rib compte1, compte2;
//	char* banque = new char[10];
//	strcpy(banque, "banque A");
//	compte1.banque = banque;
//	compte1.guichet = 1234;
//	compte1.compte = 55667788;
////	compte2 = compte1;
//	printf("compte1: %s %d %d\n", compte1.banque, compte1.guichet, compte1.compte);
//	printf("compte2: %s %d %d\n", compte2.banque, compte2.guichet, compte2.compte);
//	strcpy(compte2.banque, "banque B");
//	printf("compte1: %s %d %d\n", compte1.banque, compte1.guichet, compte1.compte);
//	printf("compte2: %s %d %d\n", compte2.banque, compte2.guichet, compte2.compte);
//	Rib *c1, *c2;
//	c1 = &compte1;
//	c2 = c1;
//	c1->compte = 333;
//	printf("c2: %s %d %d\n", c2->banque, c2->guichet, c2->compte);


//	Client cli;
//	cli.nom = "Les minoteries réusies";
//	cli.adresse .ville = "Pau";
//	cout << cli.nom << " à " << cli.adresse.ville << endl;

//	Personne *serge = (Personne*) malloc(sizeof(Personne));
//	serge->age = 37;

//	Personne *personnel = (Personne*) malloc(sizeof(Personne) * 2);
//	personnel[0].nom = "Georges";
//	personnel[0].age = 20;
//	personnel[1].nom = "Enzo";
//	personnel[1].age = 30;

//	Personne* josie = new Personne;
//	Personne* employes = new Personne[2];

//	Personne jean;
//	Personne* daniel = new Personne;
//	Personne* personnel = new Personne[2];
//	jean.age = 20;
//	daniel->age = 30;

//	cout << sizeof(Valeur) << endl;

	return 0;
}
