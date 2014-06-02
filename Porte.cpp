/**
 * \file Porte.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Porte
 * \author Étudiant 1, étudiant 2
 * \version 0.1
 * \date juin 2014
 *
 */

#include "Porte.h"

namespace TP1
{

	//Constructeur, en argument la couleur de la porte ainsi que la pièce de destination
	Porte::Porte(Couleur c, Piece * d)
	{

	}

	//constructeur par défaut
	Porte::Porte()
	{

	}

	//un destructeur qui ne fera rien
	Porte:: ~Porte()
	{

	}

	//Constructeur de copie
	Porte::Porte(const Porte&)
	{

	}

	//Surcharge de l'opérateur =
	const Porte& Porte::operator =(const Porte& source)
	{
		return source;
	}

	//accesseur de la couleur d'une porte
	Couleur Porte::getCouleur() const
	{
		return Jaune;
	}

	//Accesseur de la piece de destination
	Piece * Porte::getDestination() const
	{
		return destination;
	}
}