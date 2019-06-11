#include <algorithm>
#include <list>
#include <string>
#ifndef MONDEMAGIQUE_H
#define MONDEMAGIQUE_H

using namespace std;
 template<typename T, typename S>
 
class MondeMagique
{
public:
	MondeMagique();
	~MondeMagique();
	list<T*> obtenirlistMaitre();
	list<S*> obtenirlistCompagnon();
	void ajouter(S* s);
	void ajouter(T* t);
	void supprimer(S* s);
	void supprimer(T* t);
	template<typename predicat>
	void supprimerMaitre(predicat p);
	template<typename predicat>
	void supprimerCompagnon(predicat p);
	void vider();
	MondeMagique& operator+=(T* t);
	MondeMagique&operator-=(T* t);
	MondeMagique&operator+=(S* s);
	MondeMagique&operator-=(S* s);
protected:


list<S*> listCompagnon_;
list<T*> listMaitre_;

};


template<typename T, typename S>
MondeMagique<T,S>::MondeMagique()
{
}
template<typename T, typename S>
MondeMagique<T,S>::~MondeMagique()
{
}

template<typename T, typename S>
list<T*> MondeMagique<T, S>::obtenirlistMaitre()
{
	return listMaitre_;
}

template<typename T, typename S>
 list<S*> MondeMagique<T, S>::obtenirlistCompagnon()
{
	 return listCompagnon_;
}

 template<typename T, typename S>
 inline void MondeMagique<T, S>::ajouter(S* s)
 {
	 listMaitre_.push_back(s);
 }

 template<typename T, typename S>
 void MondeMagique<T, S>::ajouter(T * t)
 {
	 listCompagnon_.push_back(t);
 }

 template<typename T, typename S>
 inline void MondeMagique<T, S>::supprimer(S * s)
 {
	 listMaitre_.erase(find(listMaitre_.begin(), listMaitre_.end(), s));
 }

 template<typename T, typename S>
 inline void MondeMagique<T, S>::supprimer(T * t)
 {
	 listCompagnon_.erase(find(listCompagnon_.begin(), listCompagnon_.end(), t));
 }

 template<typename T, typename S>
 inline void MondeMagique<T, S>::vider()
 {
	 listMaitre_.clear();
	 listCompagnon_.clear();
 }

 template<typename T, typename S>
 inline MondeMagique<T, S>& MondeMagique<T, S>::operator+=(T* t)
 {
	 this->ajouter(t);
	 return *this;
 }

 template<typename T, typename S>
 inline MondeMagique<T,S> & MondeMagique<T, S>::operator-=(T * t)
 {
	 this->supprimer(t);
	 return *this;
 }

 template<typename T, typename S>
 inline MondeMagique<T,S> & MondeMagique<T, S>::operator+=(S * s)
 {
	 this->ajouter(s);
	 return *this;
 }

 template<typename T, typename S>
 inline MondeMagique<T,S> & MondeMagique<T, S>::operator-=(S * s)
 {
	 this->supprimer(s);
	 return this*;
 }

 

 

 

 template<typename T, typename S>
 template<typename predicat>
 inline void MondeMagique<T, S>::supprimerMaitre(predicat p)
 {
	 listMaitre_.remove_if(p);
 }

 template<typename T, typename S>
 template<typename predicat>
 inline void MondeMagique<T, S>::supprimerCompagnon(predicat p)
 {
	 listCompagnon_.remove_if(p);
	
 }

 

 

 



 














#endif



