/**
 * \file ListePortes.h
 * \brief Ce fichier contient l'interface d'une liste de portes.
 * \author Admin
 * \version 0.1
 * \date mai 2014
 * 
 */

#ifndef LISTEPORTES_H_
#define LISTEPORTES_H_

#include <stdexcept>
#include "Porte.h"


namespace TP1
{

class ListePortes
{
public:
	//constructeur par d�faut
	ListePortes();

	//destructeur
	virtual ~ListePortes();

	//Constructeur de copie
	ListePortes(const ListePortes&);

	//Surcharge de l'op�rateur =
	const ListePortes& operator =(const ListePortes& source);

	//Cette fonction doit ajouter la porte p � la liste donn�e.
	//Dans une liste de portes, plusieurs portes de couleurs diff�rentes peuvent
	//donner acc�s � la m�me autre pi�ce. Par contre, deux portes de m�me couleur
	//ne peuvent pas relier deux m�mes pi�ces. Si une tentative d'ajouter une porte
	//menant � la m�me pi�ce et ayant la m�me couleur qu'une porte d�j� pr�sente
	//dans la liste est effectu�e, il faut lancer une exception logic_error (doublon).
	void ajoutePorte(Porte &p);

	//Cette fonction doit retourner le nombre de portes pr�sentes dans la liste de portes.
	int tailleListePortes() const;

	//Cette fonction doit supprimer la porte dont l'indice dans la liste est sp�cifi�
	//par porteASupprimer dans la liste. Par exemple, si porteASupprimer vaut 0, il faut
	//supprimer la premi�re porte de la liste. Si l'indice de la porte � supprimer
	//est invalide, c'est-�-dire s'il est n�gatif ou plus grand ou �gal au nombre
	//de portes pr�sentes dans la liste, il faut lancer une exception invalid_argument.
	void supprimePorte(int porteASupprimer);

	//Retourne si la liste des portes est vide ?
	bool estVideListePortes() const;

	// el�ment dans la liste � une position donn�e,  la premi�re position est en position 1;
	// Lance une exception invalid_argument si la position n'est pas correcte.
	Porte elementAt(int pos) const;

private:
	class NoeudListePortes //noeud typique d'une liste doublement cha�n�e
	{
		public:
			Porte porte; // La porte contenue dans ce noeud de la liste cha�n�e.
			NoeudListePortes *suivant; // Un pointeur vers le noeud suivant de la liste. NULL s'il s'agit du dernier noeud.
			NoeudListePortes *precedent;// Un pointeur vers le noeud pr�c�dent de la liste. NULL s'il s'agit du premier noeud.
	};

	NoeudListePortes *acces;// pointeur sur le d�but de la liste des portes
	NoeudListePortes *fin;// pointeur sur la fin de la liste des portes
};

}

#endif /* LISTEPORTES_H_ */
