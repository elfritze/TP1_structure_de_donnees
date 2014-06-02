/**
 * \file Piece.cpp
 * \brief Ce fichier contient une implantation des m�thodes de la classe Piece
 * \author �tudiant 1, �tudiant 2
 * \version 0.1
 * \date juin 2014
 *
 */

#include "Piece.h"

namespace TP1
{

	//constructeur par d�faut
	Piece::Piece()
	{

	}

	//Surcharge du constructeur, le nom de la pi�ce en argument
	Piece::Piece(const std::string & s)
	{

	}

	//destructeur
	Piece:: ~Piece()
	{

	}

	//constructeur de copie
	Piece::Piece(const Piece&)
	{

	}

	//Surcharge de l'op�rateur =
	const Piece& Piece::operator =(const Piece& source)
	{
		return source;
	}

	//Accesseur du nom d'une pi�ce
	std::string Piece::getNom() const
	{
		return "";
	}

	//Pour initialiser l'attibut parcourue � true ou false
	void Piece::setParcourue(bool p)
	{

	}

	//Acceder au membre parcourue
	bool Piece::getParcourue() const
	{
		return false;
	}

	//Acc�der � la liste des portes qui partent de la pi�ce
	const ListePortes & Piece::getPortes() const
	{
		return portes;
	}

	//Ajouter une porte � la liste des portes qui partent de la pi�ce
	void  Piece::ajoutePorte(Porte& p)
	{

	}

}