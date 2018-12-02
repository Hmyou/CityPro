#include <locale>
#include <iostream>
#include "FileHandling.hpp"
#include "Map.h"

int main() {

	Map map;
	//���������ʼ��map
	map.Initialisation("config.in","plan.in");
	//��ȡmap��һЩ����
	std::cout << "map: lignes, colonnes, maxDis, buildingTypes" << std::endl;
	std::cout << map.nbLignes << map.nbColonnes << map.distanceMax << map.nbTypeBatiment << std::endl;
	//�����������ֱ��ȡmap���residence��utilitaire����
	std::vector<Batiment*> residences = map.getResidences();
	std::vector<Batiment*> utilitaires = map.getUtilitaires();
	//����������ʹ�û�ȡ����residences��utilitaires����ȥ��ȡ���е����ݡ�
	//ע��ֻ��residences��д�ˣ�utilitairesͬ��
	int* posTmp;
	std::vector<Batiment*>::const_iterator iterR;
	for (iterR = residences.begin(); iterR != residences.end(); ++iterR)
	{
		Batiment* batimentTmp = *iterR;
		//��ȡresidence�Ļ�������
		std::cout << "residence: id ,lignes, colonnes, capacitee" << std::endl;
		std::cout << batimentTmp->id << batimentTmp->nbLignes << batimentTmp->nbColonnes << batimentTmp->getCapacitee() << std::endl;
		//��ȡresidence��position
		posTmp = batimentTmp->getPosition();
		std::cout << "position" << posTmp[0] << "," << posTmp[1] << std::endl;
		for (int l = 0; l < batimentTmp->nbLignes; l++) {
			for (int c = 0; c < batimentTmp->nbColonnes; c++) {
				//��ifCellOccupy������ȡλ���Ƿ���ռ��
				std::cout << batimentTmp->ifCellOccupy(l, c);
			}
			std::cout << std::endl;
		}
	}

	std::vector<Batiment*>::const_iterator iterU;
	for (iterU = utilitaires.begin(); iterU != utilitaires.end(); ++iterU)
	{
		Batiment* batimentTmp = *iterU;
		std::cout << "utilitaire: id ,lignes, colonnes, type" << std::endl;
		std::cout << batimentTmp->id << batimentTmp->nbLignes << batimentTmp->nbColonnes << batimentTmp->getUtilitaireType() << std::endl;
		int* posTmp = batimentTmp->getPosition();
		std::cout << "position" << posTmp[0] << "," << posTmp[1] << std::endl;
		for (int l = 0; l < batimentTmp->nbLignes; l++) {
			for (int c = 0; c < batimentTmp->nbColonnes; c++) {
				std::cout << batimentTmp->ifCellOccupy(l, c);
			}
			std::cout << std::endl;
		}
	}

	system("PAUSE");
	return 0;

}

