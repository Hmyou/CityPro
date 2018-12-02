#include "Batiment.h"

Batiment::Batiment()
{
	id = 0;
	nbLignes = 0;
	nbColonnes = 0;
	// init position all 0
	forme = new int*[nbLignes];
	for (int i = 0; i < nbLignes; ++i){
		forme[i] = new int[nbColonnes];
	}
	for (int l = 0; l < nbLignes; l++) {
		for (int c = 0; c < nbColonnes; c++) {
			this->forme[l][c] = 0;
		}
	}

	position = new int[0, 0];
}

Batiment::Batiment(int idA , int nbLignesA, int nbColonnesA)
{
	id = idA;
	nbLignes = nbLignesA;
	nbColonnes = nbColonnesA;
	// init position all 0
	forme = new int*[nbLignes];
	for (int i = 0; i < nbLignes; ++i) {
		forme[i] = new int[nbColonnes];
	}
	for (int l = 0; l < nbLignes; l++) {
		for (int c = 0; c < nbColonnes; c++) {
			this->forme[l][c] = 0;
		}
	}

	position = new int[0, 0];

}

Batiment::Batiment(const Batiment &obj)
{
	id = obj.id;
	nbLignes = obj.nbLignes;
	nbColonnes = obj.nbColonnes;
	forme = obj.forme;
	position = obj.position;
}

Batiment::Batiment(Batiment && obj)
{
	id = obj.id;
	nbLignes = obj.nbLignes;
	nbColonnes = obj.nbColonnes;
	forme = obj.forme;
	position = obj.position;
}

Batiment::~Batiment()
{
	/*for (int i = 0; i < nbLignes; ++i)
		delete[] forme[i];
	delete[] forme;*/
}

Batiment & Batiment::operator=(const Batiment &obj)
{
	id = obj.id;
	nbLignes = obj.nbLignes;
	nbColonnes = obj.nbColonnes;
	forme = obj.forme;
	position = obj.position;
	return (*this);

}

Batiment & Batiment::operator=(Batiment && obj)
{
	id = obj.id;
	nbLignes = obj.nbLignes;
	nbColonnes = obj.nbColonnes;
	forme = obj.forme;
	position = obj.position;
	return (*this);
}

void Batiment::setForme(int x, int y, int occupy)
{
	this->forme[x][y] = occupy;
}

void Batiment::setPosition(int x, int y)
{
	this->position[0] = x;
	this->position[1] = y;
}

int * Batiment::getPosition()
{
	return this->position;
}

int Batiment::ifCellOccupy(int x, int y)
{
	return this->forme[x][y];
}

void Batiment::printForme()
{
	for (int l = 0; l < this->nbLignes; l++) {
		for (int c = 0; c < this->nbColonnes; c++) {
			std::cout << this->forme[l][c];
		}
		std::cout << std::endl;
	}
}

int Batiment::getCapacitee()
{
	return 0;
}

int Batiment::getUtilitaireType()
{
	return 0;
}
