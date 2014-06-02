/**
 * \file ListePortes.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe ListePortes
 * \author Étudiant 1, étudiant 2
 * \version 0.1
 * \date juin 2014
 *
 */

#include "ListePortes.h"

namespace TP1
{

	//constructeur par défaut
	ListePortes::ListePortes()
	{

	}

	//destructeur
	ListePortes:: ~ListePortes()
	{

	}

	//Constructeur de copie
	ListePortes::ListePortes(const ListePortes&)
	{

	}

	//Surcharge de l'opérateur =
	const ListePortes& ListePortes::operator =(const ListePortes& source)
	{
		return source;
	}

	//Cette fonction doit ajouter la porte p à la liste donnée.
	//Dans une liste de portes, plusieurs portes de couleurs différentes peuvent
	//donner accès à la même autre pièce. Par contre, deux portes de même couleur
	//ne peuvent pas relier deux mêmes pièces. Si une tentative d'ajouter une porte
	//menant à la même pièce et ayant la même couleur qu'une porte déjà présente
	//dans la liste est effectuée, il faut lancer une exception logic_error (doublon).
	void ListePortes::ajoutePorte(Porte &p)
	{

	}

	//Cette fonction doit retourner le nombre de portes présentes dans la liste de portes.
	int ListePortes::tailleListePortes() const
	{
		return 0;
	}

	//Cette fonction doit supprimer la porte dont l'indice dans la liste est spécifié
	//par porteASupprimer dans la liste. Par exemple, si porteASupprimer vaut 0, il faut
	//supprimer la première porte de la liste. Si l'indice de la porte à supprimer
	//est invalide, c'est-à-dire s'il est négatif ou plus grand ou égal au nombre
	//de portes présentes dans la liste, il faut lancer une exception invalid_argument.
	void ListePortes::supprimePorte(int porteASupprimer)
	{

	}

	//Retourne si la liste des portes est vide ?
	bool ListePortes::estVideListePortes() const
	{
		return true;
	}

	// elément dans la liste à une position donnée,  la première position est en position 1;
	// Lance une exception invalid_argument si la position n'est pas correcte.
	Porte ListePortes::elementAt(int pos) const
	{
		return acces->porte;
	}

}