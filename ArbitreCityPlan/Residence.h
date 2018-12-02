#include "Batiment.h"

class Residence : public Batiment
{
private:
	int capacitee;

public:
	Residence() {
		this->capacitee = 0;
	};
	Residence(int id, int ligne, int colonne, int capacitee) {
		*this = Batiment(id, ligne, colonne);
		this->capacitee = capacitee;
	};
	Residence(const Residence&obj) {
		*this = obj;
	};
	Residence(Residence&&obj) {
		*this = obj;
	};

	Residence &operator=(const Batiment&obj) {
		this->id = obj.id;
		this->nbLignes = obj.nbLignes;
		this->nbColonnes = obj.nbColonnes;
		this->forme = obj.forme;
		this->position = obj.position;
		return *this;
	};
	Residence &operator=(const Residence&obj) {
		*this = obj;
		return *this;
	};
	Residence &operator=(Residence&&obj) {
		*this = obj;
		return *this;
	};

	virtual int getCapacitee() {
		return this->capacitee;
	};
};