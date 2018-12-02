#include "Batiment.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iterator>

class Map{

public :
	std::vector<Batiment*> residences;
	std::vector<Batiment*> utilitaires;
	int nbLignes;
	int nbColonnes;
	int distanceMax;
	int nbTypeBatiment;
	int **carte;

	Map(); // Constructeur par défaut
	Map(const Map&obj); // Constructeur de recopie
	Map(Map&&obj); // Constructeur de recopie
	~Map(); // Destructeur éventuellement virtuel
	Map &operator=(const Map&obj); // Operator d'affectation
	Map &operator=(Map&&obj); // Operator d'affectation

	Map& Initialisation(const char* configFile, const char* planFile);

	std::vector<Batiment*> getResidences();
	std::vector<Batiment*> getUtilitaires();

};