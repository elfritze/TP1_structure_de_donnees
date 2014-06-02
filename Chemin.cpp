/**
 * \file Chemin.cpp
 * \brief Ce fichier contient une implantation des m�thodes de la classe Chemin
 * \author �tudiant 1, �tudiant 2
 * \version 0.1
 * \date juin 2014
 *
 */

#include "Chemin.h"

namespace TP1
{

	//Constructeur par d�faut
	Chemin::Chemin()
	{

	}

	//Destructeur
	Chemin:: ~Chemin()
	{
		
	}

	//constructeur de copie
	Chemin::Chemin(const Chemin&)
	{

	}

	//Surcharge de l'op�rateur =
	const Chemin& Chemin::operator= (const Chemin& source)
	{
		return source;
	}

	//Ajoute le nom d'une pi�ce avec sa distance au d�but, sp�cifi�s par nomPiece et distanceDuDebut,
	//� un chemin. Il n'y a pas de v�rification particuli�re de doublons � faire.
	void Chemin::ajoutePiece(const std::string &nomPiece, int distanceDuDebut)
	{

	}

	//Supprime une pi�ce d'un chemin, dont l'indice dans la liste cha�n�e,commen�ant par 1,
	//est sp�cifi� par numPiece. La m�thode doit lancer une exception invalid_argument si l'indice est invalide.
	void Chemin::retirePiece(int numPiece)
	{

	}

	/**
	 * \brief obtenir le nom de la pi�ce du d�but d'un chemin
	 */
	const std::string & Chemin::getNomPiece() const
	{
		const std::string &str = "";
		return str;
	}

	/**
	 * \brief obtenir la distance du d�but de la pi�ce au d�but d'un chemin
	 */
	int Chemin::getDistanceDuDebut() const
	{
		return 0;
	}

	//Retourne la taille d'un chemin.
	int Chemin::tailleChemin() const
	{
		return 0;
	}

	//Affiche le chemin c en affichant, ligne par ligne, chaque nom de case suivi d'une espace puis de la distance du d�but.
	//Par exemple :
	//  PremierePiece 0
	//  CaseACote 1
	//  AutreCase 2
	//  Blabla 3
	void Chemin::afficheChemin() const
	{

	}

}