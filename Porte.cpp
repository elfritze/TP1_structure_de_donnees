/**
 * \file Porte.cpp
 * \brief Ce fichier contient une implantation des m�thodes de la classe Porte
 * \author �tudiant 1, �tudiant 2
 * \version 0.1
 * \date juin 2014
 *
 */

#include "Porte.h"

namespace TP1
{

	//Constructeur, en argument la couleur de la porte ainsi que la pi�ce de destination
	Porte::Porte(Couleur c, Piece * d)
	{

	}

	//constructeur par d�faut
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

	//Surcharge de l'op�rateur =
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