#ifndef  FONCTEUR_H
#define  FONCTEUR_H

#include "Dresseur.h"
#include <stdlib.h>
#include <time.h>

#include <string>
#include <stdlib.h>

#define RAND_MIN_DEFAUT 0
#define RAND_MAX_DEFAUT 6

//Froncteur permettant d'obtenir l'attaque de la créature passée en argument
class FoncteurObtenirAttaqueCreature
{
public:
    FoncteurObtenirAttaqueCreature() {}
    ~FoncteurObtenirAttaqueCreature() {}

    unsigned int operator() (const Creature* creature) const {
        return creature->obtenirAttaque();
    }
};


class FoncteurComparerCreatures 
{

public:
	FoncteurComparerCreatures(Creature* creature1, Creature* creature2)
		:creature1_(creature1), creature2_(creature2) {};


	bool operator()(const Creature* creature1, const Creature* creature2) {

		return (creature1->obtenirAttaque() < creature2->obtenirAttaque());
	}

private:
	
	Creature* creature2_;
	Creature* creature1_;
	
};

class FoncteurComparerDresseurs {


public:
	FoncteurComparerDresseurs(Dresseur* dresseur1, Dresseur* dresseur2)
	 :dresseur1_(dresseur1), dresseur2_(dresseur2) {};

	bool operator()(const Dresseur* dresseur1, const Dresseur* dresseur2) {

		return (dresseur1->obtenirNom() < dresseur2->obtenirNom());
	}
private: 
   
	Dresseur* dresseur1_;
	Dresseur* dresseur2_;


};


class FoncteurComparerPouvoirs {


public:

	FoncteurComparerPouvoirs(Pouvoir* pouvoir1, Pouvoir* pouvoir2) :pouvoir1_(pouvoir1), pouvoir2_(pouvoir2) {};

	bool operator()(const Pouvoir* pouvoir1, const Pouvoir* pouvoir2) {

		return (pouvoir1->obtenirNombreDeDegat() < pouvoir2->obtenirNombreDeDegat());

	}

private:

	Pouvoir*  pouvoir1_;
	Pouvoir*  pouvoir2_;



};






class FoncteurCreaturesDeMemeNom {

public:
	FoncteurCreaturesDeMemeNom(const string& nom) :nom_(nom) {};
	bool operator()(const Creature* creature){

		return(creature->obtenirNom() == nom_);
	}


private:

	string nom_;


	
};





class FoncteurEgalCreatures {

public:
	FoncteurEgalCreatures(Creature* creature) :creature_(creature) {};
	bool operator()(const Creature* creature) {

		return(*creature == *creature_);
	}


private:
	Creature* creature_;
};






class FoncteurCreatureVie {

	FoncteurCreatureVie(int max, int min) :vieMax_(max), vieMin_(min), compteur_(0) {};
	void operator()(const Creature* creature) {

		if (creature->obtenirPointDeVie() < vieMax_&&creature->obtenirPointDeVie() > vieMin_)
			compteur_++;

	}
	int obtenirCompteur() const {
		return compteur_;
	}

private:

	int vieMax_;
	int vieMin_;
	int compteur_;
};

class FoncteurGenerateurNombresAlea {

public:

	FoncteurGenerateurNombresAlea() :borneInf_(0), borneSup_(6) {};
	FoncteurGenerateurNombresAlea(int inf, int sup) :borneInf_(inf), borneSup_(sup) {};
	int operator()() {

		srand(time(NULL));
		return (borneInf_ + rand() % (borneSup_ - borneInf_+1));

	}

private:
	int borneInf_;
	int borneSup_;

};


#endif
