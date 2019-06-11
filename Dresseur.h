/*
Fichier: Dresseur.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  6 septembre 2016 par Maude Carrier
Description: les dresseurs sont les etres capables d'attraper des creatures
*/
#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include "Foncteur.h"
#include "Creature.h"
#include "ObjetMagique.h"
using namespace std;
class Dresseur
{
public:
	Dresseur();
	Dresseur(const std::string& nom, const std::string& equipe);
	~Dresseur();

	std::string obtenirNom() const;
	void modifierNom(const std::string& nom);
	
	unsigned int obtenirNombreCreatures() const;

	auto obtenirCreatures() const;
	Creature* obtenirUneCreature(const string&nom) const; //À MODIFIFIER !!
	void modifierCreature(std::list<Creature*>  creatures);
	
	bool ajouterCreature(Creature* creature);
	bool enleverCreature(const std::string& nom);

	ObjetMagique obtenirObjetMagique() const;
	void modifierObjetMagique(const ObjetMagique& objetMagique);

	void utiliserObjetMagique(Creature* creature);

	std::string obtenirEquipe() const;
	void modifierEquipe(const std::string& equipe);

	friend std::ostream& operator<<(std::ostream& os, const Dresseur& dresseur);

	bool operator==(const Dresseur& dresseur) const;
	bool operator==(const std::string& nom) const;
	friend bool operator==(const std::string& nom, const Dresseur& dresseur);
	template<typename Unaire>
	void appliquerFoncteurUnaire(Unaire& unaire);
	template<typename foncteurUnaire>
	void supprimerElement(foncteurUnaire&foncteur);
	template<typename foncteurOrdre>
	Creature*	obtenirCreatureMax(foncteurOrdre&foncteur);

private:
	list <Creature*> creatures_;

	std::string nom_;
	std::string equipe_;
	ObjetMagique objetMagique_;
	

};

#endif

template<typename Unaire>
void Dresseur::appliquerFoncteurUnaire(Unaire&unaire)
{
	for (Creature* creature : creatures_) {
		unaire(creature);
	}
}

template<typename foncteurUnaire>
inline void Dresseur::supprimerElement(foncteurUnaire & foncteur)
{
	creatures_.remove_if(foncteur());
}

template<typename foncteurOrdre>
inline Creature * Dresseur::obtenirCreatureMax(foncteurOrdre & foncteur)
{
	
	creatures_.sort(foncteur);
	return creatures_.back();
}








