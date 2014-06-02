/**
 * \file ListePortes.cpp
 * \brief Ce fichier contient une implantation des m�thodes de la classe ListePortes
 * \author �tudiant 1, �tudiant 2
 * \version 0.1
 * \date juin 2014
 *
 */

#include "ListePortes.h"

namespace TP1
{

	//constructeur par d�faut
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

	//Surcharge de l'op�rateur =
	const ListePortes& ListePortes::operator =(const ListePortes& source)
	{
		return source;
	}

	//Cette fonction doit ajouter la porte p � la liste donn�e.
	//Dans une liste de portes, plusieurs portes de couleurs diff�rentes peuvent
	//donner acc�s � la m�me autre pi�ce. Par contre, deux portes de m�me couleur
	//ne peuvent pas relier deux m�mes pi�ces. Si une tentative d'ajouter une porte
	//menant � la m�me pi�ce et ayant la m�me couleur qu'une porte d�j� pr�sente
	//dans la liste est effectu�e, il faut lancer une exception logic_error (doublon).
	void ListePortes::ajoutePorte(Porte &p)
	{

	}

	//Cette fonction doit retourner le nombre de portes pr�sentes dans la liste de portes.
	int ListePortes::tailleListePortes() const
	{
		return 0;
	}

	//Cette fonction doit supprimer la porte dont l'indice dans la liste est sp�cifi�
	//par porteASupprimer dans la liste. Par exemple, si porteASupprimer vaut 0, il faut
	//supprimer la premi�re porte de la liste. Si l'indice de la porte � supprimer
	//est invalide, c'est-�-dire s'il est n�gatif ou plus grand ou �gal au nombre
	//de portes pr�sentes dans la liste, il faut lancer une exception invalid_argument.
	void ListePortes::supprimePorte(int porteASupprimer)
	{

	}

	//Retourne si la liste des portes est vide ?
	bool ListePortes::estVideListePortes() const
	{
		return true;
	}

	// el�ment dans la liste � une position donn�e,  la premi�re position est en position 1;
	// Lance une exception invalid_argument si la position n'est pas correcte.
	Porte ListePortes::elementAt(int pos) const
	{
		return acces->porte;
	}

}