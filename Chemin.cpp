/**
 * \file Chemin.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Chemin
 * \author Étudiant 1, étudiant 2
 * \version 0.1
 * \date juin 2014
 *
 */

#include "Chemin.h"

namespace TP1
{

	//Constructeur par défaut
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

	//Surcharge de l'opérateur =
	const Chemin& Chemin::operator= (const Chemin& source)
	{
		return source;
	}

	//Ajoute le nom d'une pièce avec sa distance au début, spécifiés par nomPiece et distanceDuDebut,
	//à un chemin. Il n'y a pas de vérification particulière de doublons à faire.
	void Chemin::ajoutePiece(const std::string &nomPiece, int distanceDuDebut)
	{

	}

	//Supprime une pièce d'un chemin, dont l'indice dans la liste chaînée,commençant par 1,
	//est spécifié par numPiece. La méthode doit lancer une exception invalid_argument si l'indice est invalide.
	void Chemin::retirePiece(int numPiece)
	{

	}

	/**
	 * \brief obtenir le nom de la pièce du début d'un chemin
	 */
	const std::string & Chemin::getNomPiece() const
	{
		const std::string &str = "";
		return str;
	}

	/**
	 * \brief obtenir la distance du début de la pièce au début d'un chemin
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

	//Affiche le chemin c en affichant, ligne par ligne, chaque nom de case suivi d'une espace puis de la distance du début.
	//Par exemple :
	//  PremierePiece 0
	//  CaseACote 1
	//  AutreCase 2
	//  Blabla 3
	void Chemin::afficheChemin() const
	{

	}

}