#include "Map.h"
#include "Batiment.h"
#include "Residence.h"
#include "Utilitaire.h"
Map::Map()
{
	nbLignes = 0;
	nbColonnes = 0;
	distanceMax = 0;
	carte = new int*[nbLignes];
	for (int i = 0; i < nbLignes; ++i) {
		carte[i] = new int[nbColonnes];
	}
	std::vector<Batiment> batiments;
}




Map::Map(const Map & obj)
{
	nbLignes = obj.nbLignes;
	nbColonnes = obj.nbColonnes;
	distanceMax = obj.distanceMax;
	nbTypeBatiment = obj.nbTypeBatiment;
	residences = obj.residences;
	utilitaires = obj.utilitaires;
	carte = obj.carte;
}

Map::Map(Map && obj)
{
	nbLignes = obj.nbLignes;
	nbColonnes = obj.nbColonnes;
	distanceMax = obj.distanceMax;
	nbTypeBatiment = obj.nbTypeBatiment;
	residences = obj.residences;
	utilitaires = obj.utilitaires;
	carte = obj.carte;
}

Map::~Map()
{
	/*for (int i = 0; i < nbLignes; ++i)
		delete[] carte[i];
	delete[] carte;*/

}

Map & Map::operator=(const Map & obj)
{
	nbLignes = obj.nbLignes;
	nbColonnes = obj.nbColonnes;
	distanceMax = obj.distanceMax;
	nbTypeBatiment = obj.nbTypeBatiment;
	residences = obj.residences;
	utilitaires = obj.utilitaires;
	carte = obj.carte;
	//pas sur
	return (*this);
}

Map & Map::operator=(Map && obj)
{
	nbLignes = obj.nbLignes;
	nbColonnes = obj.nbColonnes;
	distanceMax = obj.distanceMax;
	nbTypeBatiment = obj.nbTypeBatiment;
	residences = obj.residences;
	utilitaires = obj.utilitaires;
	carte = obj.carte;
	//pas sur
	return (*this);
}


std::vector<std::string> cutLineInTab(std::string line) {
	std::vector<std::string> arrayLigne;
	std::istringstream buf(line);
	std::istream_iterator<std::string> beg(buf), end;

	std::vector<std::string> tokens(beg, end); // done!

	for (auto& s : tokens) {
		arrayLigne.push_back(s);
	}
	
	return arrayLigne;
}


Map& Map::Initialisation(const char * configFile, const char * planFile)
{
	std::string line;
	std::ifstream myconfig(configFile);
	std::ifstream myplan(planFile);

	int nblignelues = 0, idTmp = 0;
	if (myconfig.is_open() && myplan.is_open())
	{
		int nbBatiment = 0;
		std::vector<std::string> planLine;
		getline(myplan, line);
		nbBatiment = std::stoi(cutLineInTab(line)[0]);
		for (int nbline = 0; nbline < nbBatiment; nbline++) {
			getline(myplan, line);
			planLine.push_back(line);
		}
		myplan.close();

		while (getline(myconfig, line))
		{
			nblignelues += 1;

			std::vector<std::string> arrayLigne;
			std::vector<std::string> R_Forme;
			std::vector<std::string> U_Forme;
			std::string formeTmp;
			int ligneTmp, colonneTmp, capaciteeTmp, typeTmp;
			Batiment* batimentTmp;

			int getIdTmp;
			std::string planLineTmp;
			std::vector<std::string> arrayPlanLine;
			switch (line.at(0)) {
			case 'R':
				arrayLigne = cutLineInTab(line);
				ligneTmp = std::stoi(arrayLigne[1]);
				colonneTmp = std::stoi(arrayLigne[2]);
				capaciteeTmp = std::stoi(arrayLigne[3]);
				
				// record forme
				for (int l = 0; l < ligneTmp; l++) {
					getline(myconfig, line);
					R_Forme.push_back(line);
				}

				// add plan residence to map
				for (auto iter = planLine.cbegin(); iter != planLine.cend(); iter++) {
					planLineTmp = (*iter);
					arrayPlanLine = cutLineInTab(planLineTmp);
					getIdTmp = std::stoi(arrayPlanLine[0]);
					if (getIdTmp == idTmp) {
						batimentTmp = new Residence(idTmp, ligneTmp, colonneTmp, capaciteeTmp);
						// set position
						batimentTmp->setPosition(std::stoi(arrayPlanLine[1]), std::stoi(arrayPlanLine[2]));
						// set forme
						for (int l = 0; l < ligneTmp; l++) {
							formeTmp = R_Forme[l];
							for (int c = 0; c < colonneTmp; c++) {
								if ('.' == formeTmp[c]) {
									batimentTmp->setForme(l, c, 0);
								}
								else if ('#' == formeTmp[c]) {
									batimentTmp->setForme(l, c, 1);
								}
							}
						}
						this->residences.push_back(batimentTmp);
					}
				}
				idTmp++;
				break;
			case 'U':
				arrayLigne = cutLineInTab(line);
				ligneTmp = std::stoi(arrayLigne[1]);
				colonneTmp = std::stoi(arrayLigne[2]);
				typeTmp = std::stoi(arrayLigne[3]);
				
				// record forme
				for (int l = 0; l < ligneTmp; l++) {
					getline(myconfig, line);
					U_Forme.push_back(line);
				}

				// add plan utilitaire to map
				for (auto iter = planLine.cbegin(); iter != planLine.cend(); iter++) {
					planLineTmp = (*iter);
					arrayPlanLine = cutLineInTab(planLineTmp);
					getIdTmp = std::stoi(arrayPlanLine[0]);
					if (getIdTmp == idTmp) {
						batimentTmp = new Utilitaire(idTmp, ligneTmp, colonneTmp, typeTmp);
						// set position
						batimentTmp->setPosition(std::stoi(arrayPlanLine[1]), std::stoi(arrayPlanLine[2]));
						// set forme
						for (int l = 0; l < ligneTmp; l++) {
							formeTmp = U_Forme[l];
							for (int c = 0; c < colonneTmp; c++) {
								if ('.' == formeTmp[c]) {
									batimentTmp->setForme(l, c, 0);
								}
								else if ('#' == formeTmp[c]) {
									batimentTmp->setForme(l, c, 1);
								}
							}
						}
						this->utilitaires.push_back(batimentTmp);
					}
				}
				idTmp++;
				break;
			default:
				//Si c'est la premiere ligne
				if (isdigit(line.at(0))) {
					arrayLigne = cutLineInTab(line);

					this->nbLignes = std::stoi(arrayLigne[0]);
					this->nbColonnes = std::stoi(arrayLigne[1]);
					this->distanceMax = std::stoi(arrayLigne[2]);
					this->nbTypeBatiment = std::stoi(arrayLigne[3]);

				}
				//. ou # : batiment
				else {
				}
				break;
			}

		}
		myconfig.close();

	}
	else std::cout << "Unable to open file";

	return *this;
}

std::vector<Batiment*> Map::getResidences()
{
	return this->residences;
}

std::vector<Batiment*> Map::getUtilitaires()
{
	return this->utilitaires;
}



