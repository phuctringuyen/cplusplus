//============================================================================
// Name        : 03_stdlib.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
	cout << "Hello World" << endl; // prints Hello World

	printf("** Recherche:\n");

	char* chaine1 = "Amateur de C++ et de programmation";
	char* motif = "C++";
	char* souschaine = strstr(chaine1, motif);

	// trouver le motif et donner sa position
	if (souschaine != NULL) {
		printf("Trouve le motif [%s} dans [%s] :\n[%s] à la position [%d]\n\n",
				motif, chaine1, souschaine, souschaine-chaine1);
	}

	printf("** Comparaison, concatenation:\n");
	char* chaine2 = new char[strlen(chaine1) + 50];
	strcpy(chaine2, chaine1);
	strcat(chaine2, ", un nouvel ouvrage est disponible chez ENI");
	printf("chaine2 = %s\n", chaine2);

	char chaine3[50];
	memset(chaine3, 'O', 3);		// [OOO...]
	chaine3[3] = 0;					// [OOO0...]
	if (strcmp(chaine3, "OOO"))		// false car \0 est aussi compté, "OOO0" donne true !
		printf("chaine3 = %s\n", chaine3);

	char* chaine4 = "ABC";
	char* chaine5 = new char[strlen(chaine4) + 1];  // +1 pour le \0
	strcpy(chaine5, chaine4);		// 5 = "ABC"
	printf("chaine5 = %s\n", chaine5);

	char* chaine6 = strlwr(chaine5);		// chaine5 est modifiée en minuscule!!!
	printf("chaine5 = %s  chaine6 = %s\n\n", chaine5, chaine6);

	// Entrée/Sortie
	printf("** Entrée/Sortie\n");
	char message[500];
	sprintf(message, "2 x 2 = %d\n", 2*2);	// ecrire dans message
	printf("message %s\n", message);





//	char *lecture = new char[50];
//	printf("Nombre: ?");
//	scanf("%s", lecture);
//	double nombre = atof(lecture);
//	double pi = 3.141592;
//	printf("le nombre plus grand est %2f\n", max(nombre, pi));

	return 0;
}
