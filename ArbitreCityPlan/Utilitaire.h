#include "Batiment.h"

class Utilitaire : public Batiment
{
private:
	int type;

public:
	Utilitaire() { 
		this->type = 0;
	};
	Utilitaire(int id, int ligne, int colonne, int type) {
		*this = Batiment(id, ligne, colonne); 
		this->type = type;
	};
	Utilitaire(const Utilitaire&obj) { 
		*this = obj;
	};
	Utilitaire(Utilitaire&&obj) {
		*this = obj;
	};

	Utilitaire &operator=(const Batiment&obj) {
		this->id = obj.id;
		this->nbLignes = obj.nbLignes;
		this->nbColonnes = obj.nbColonnes;
		this->forme = obj.forme;
		this->position = obj.position;
		return *this;
	};
	Utilitaire &operator=(const Utilitaire&obj) { 
		*this = obj;
		return *this;
	};
	Utilitaire &operator=(Utilitaire&&obj) { 
		*this = obj;
		return *this;
	};

	virtual int getUtilitaireType() {
		return this->type;
	};
};