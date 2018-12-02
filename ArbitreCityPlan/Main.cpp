#include <locale>
#include <iostream>
#include "FileHandling.hpp"
#include "Map.h"

int main() {

	Map map;
	//这个方法初始化map
	map.Initialisation("config.in","plan.in");
	//获取map的一些属性
	std::cout << "map: lignes, colonnes, maxDis, buildingTypes" << std::endl;
	std::cout << map.nbLignes << map.nbColonnes << map.distanceMax << map.nbTypeBatiment << std::endl;
	//这两个方法分别获取map里的residence和utilitaire数组
	std::vector<Batiment*> residences = map.getResidences();
	std::vector<Batiment*> utilitaires = map.getUtilitaires();
	//下面举例如何使用获取到的residences和utilitaires，再去获取其中的数据。
	//注释只在residences里写了，utilitaires同理。
	int* posTmp;
	std::vector<Batiment*>::const_iterator iterR;
	for (iterR = residences.begin(); iterR != residences.end(); ++iterR)
	{
		Batiment* batimentTmp = *iterR;
		//获取residence的基本属性
		std::cout << "residence: id ,lignes, colonnes, capacitee" << std::endl;
		std::cout << batimentTmp->id << batimentTmp->nbLignes << batimentTmp->nbColonnes << batimentTmp->getCapacitee() << std::endl;
		//获取residence的position
		posTmp = batimentTmp->getPosition();
		std::cout << "position" << posTmp[0] << "," << posTmp[1] << std::endl;
		for (int l = 0; l < batimentTmp->nbLignes; l++) {
			for (int c = 0; c < batimentTmp->nbColonnes; c++) {
				//用ifCellOccupy方法获取位置是否是占用
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

