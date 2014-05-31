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
	//constructeur par défaut
	ListePortes();

	//destructeur
	virtual ~ListePortes();

	//Constructeur de copie
	ListePortes(const ListePortes&);

	//Surcharge de l'opérateur =
	const ListePortes& operator =(const ListePortes& source);

	//Cette fonction doit ajouter la porte p à la liste donnée.
	//Dans une liste de portes, plusieurs portes de couleurs différentes peuvent
	//donner accès à la même autre pièce. Par contre, deux portes de même couleur
	//ne peuvent pas relier deux mêmes pièces. Si une tentative d'ajouter une porte
	//menant à la même pièce et ayant la même couleur qu'une porte déjà présente
	//dans la liste est effectuée, il faut lancer une exception logic_error (doublon).
	void ajoutePorte(Porte &p);

	//Cette fonction doit retourner le nombre de portes présentes dans la liste de portes.
	int tailleListePortes() const;

	//Cette fonction doit supprimer la porte dont l'indice dans la liste est spécifié
	//par porteASupprimer dans la liste. Par exemple, si porteASupprimer vaut 0, il faut
	//supprimer la première porte de la liste. Si l'indice de la porte à supprimer
	//est invalide, c'est-à-dire s'il est négatif ou plus grand ou égal au nombre
	//de portes présentes dans la liste, il faut lancer une exception invalid_argument.
	void supprimePorte(int porteASupprimer);

	//Retourne si la liste des portes est vide ?
	bool estVideListePortes() const;

	// elément dans la liste à une position donnée,  la première position est en position 1;
	// Lance une exception invalid_argument si la position n'est pas correcte.
	Porte elementAt(int pos) const;

private:
	class NoeudListePortes //noeud typique d'une liste doublement chaînée
	{
		public:
			Porte porte; // La porte contenue dans ce noeud de la liste chaînée.
			NoeudListePortes *suivant; // Un pointeur vers le noeud suivant de la liste. NULL s'il s'agit du dernier noeud.
			NoeudListePortes *precedent;// Un pointeur vers le noeud précédent de la liste. NULL s'il s'agit du premier noeud.
	};

	NoeudListePortes *acces;// pointeur sur le début de la liste des portes
	NoeudListePortes *fin;// pointeur sur la fin de la liste des portes
};

}

#endif /* LISTEPORTES_H_ */
