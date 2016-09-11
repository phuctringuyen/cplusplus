//============================================================================
// Name        : 05_stdio.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//#include <stdafx.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;


const int T_BLOC = 16;

void debut(FILE* f) {		// aller sur le début du fichier
	fseek(f, 0, SEEK_SET);
}

void fin(FILE* f) {		// aller sur la fin du fichier
	fseek(f, 0, SEEK_END);
	long taille = ftell(f);
	printf("taille: %i  taille T_BLOC: %d\n", taille, taille % T_BLOC);
	fseek(f, taille - (taille % T_BLOC), SEEK_SET);
}

void haut(FILE* f) {		// remonter dans le fichier
	fseek(f, -T_BLOC, SEEK_CUR);
}

void bas(FILE* f) {		// descendre dans le fichier
	fseek(f, T_BLOC, SEEK_CUR);
}

long taille(FILE* f) {		// déterminer la taille du fichier
	long pos = ftell(f);
	fseek(f, 0, SEEK_END);
	long taille = ftell(f);
	fseek(f, pos, SEEK_SET);	// retourner à la position initiale
	return taille;
}

void afficher_bloc(FILE* f) {
	int offset = ftell(f);
	char chaine_hexa[T_BLOC*3 + 2 + 1];
	char chaine_ascii[T_BLOC*2 + 2 + 1];

	strcpy(chaine_hexa, "");
	strcpy(chaine_ascii, "");

//	int data;
	for(int i=0; i<16; i++) {
		int car = fgetc(f);
		if(car == -1)	break;

		char concat[50];
		sprintf(concat, "%2x ", car);
		strcat(chaine_hexa, concat);

		sprintf(concat, "%c", car >= 32 ? car : ' ');
		strcat(chaine_ascii, concat);

		if(i == T_BLOC/2-1) {		// ajouter espace apres 8 caracteres lus
			strcat(chaine_hexa, " ");
			strcat(chaine_ascii, " ");
		}
	}

	fprintf(stdout, "%4d | %s | %s\n", offset, chaine_hexa, chaine_ascii);
}



int main() {
	cout << "stdio.h library" << endl;

	char* nom_fichier = "c://temp//formation0816.txt";
	FILE* f = NULL;

	try {
		f = fopen(nom_fichier, "rb");

		// lecture continue du fichier
		long p = 0;
		long t = taille(f);
		debut(f);
		while(p < t) {
			afficher_bloc(f);
			p += T_BLOC;
		}
		fclose(f);
	} catch (...) {
		printf("Erreur \n");
	}

	return 0;
}
