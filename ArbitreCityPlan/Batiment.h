#pragma once
#include<iostream>
class Batiment
{
private :

public:
	int id;
	int nbLignes;
	int nbColonnes;
	int** forme;
	int* position;

	Batiment(); // Constructeur par défaut
	Batiment(int id, int ligne, int colonne);
	Batiment(const Batiment&obj); // Constructeur de recopie
	Batiment(Batiment&&obj); // Constructeur de recopie
	~Batiment(); // Destructeur éventuellement virtuel
	Batiment &operator=(const Batiment&obj); // Operator d'affectation
	Batiment &operator=(Batiment&&obj); // Operator d'affectation
	void setForme(int x, int y, int occupy);
	void setPosition(int x, int y);
	int* getPosition();
	int ifCellOccupy(int x, int y);
	void printForme();

	virtual int getCapacitee();
	virtual int getUtilitaireType();
};