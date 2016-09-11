#include <string.h>

class Point {
private:
	int x, y;
public:
	void afficher();
	void positionner(int X, int Y);
	int couleur;
};


class Chaine {
private:
	char* buffer;
	int t_buf;
	int longeur;

public:
	Chaine() {
		printf("Constructeur par default\n");
		t_buf = 100;
		buffer = new char[t_buf];
		longeur = 0;
	}
	Chaine(int t_buf) {
		printf("Constructeur Chaine(%d)\n", t_buf);
		this->t_buf = t_buf;
		this->buffer = new char[t_buf];
		this->longeur = 0;
	}
	Chaine(const Chaine&);				// constructeur de copie
	Chaine& operator = (const Chaine&);	// affectation copie
	~Chaine() {
		delete[] buffer;
	}
	void affecter(const char* ch, int len);
	void afficher();
};

void Chaine::affecter(const char* ch, int len) {
	longeur = len;
	memcpy(buffer, ch, len);
}
void Chaine::afficher() {
	printf("Chaine: t_buf %d, longeur %d, buffer: %c %c %c %c %c %c %c %c...\n",
			t_buf, longeur, buffer[0], buffer[1], buffer[2], buffer[3],
			buffer[4], buffer[5], buffer[6], buffer[7]);
}

Chaine::Chaine(const Chaine& ch) {
	t_buf = ch.t_buf;
	longeur = ch.longeur;
	buffer = new char[t_buf];
	for (int i=0; i<longeur; i++) {
		buffer[i] = ch.buffer[i];
	}
}

Chaine& Chaine::operator = (const Chaine& ch) {
	if (this != &ch) {		// eviter de liberer la mémoire si s = s!!
		delete[] buffer;
		t_buf = ch.t_buf;
		longeur = ch.longeur;
		buffer = new char[t_buf];
		for (int i=0; i<longeur; i++) {
			buffer[i] = ch.buffer[i];
		}
	}
	return *this;
}
