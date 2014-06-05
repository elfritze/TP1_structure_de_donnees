/**
 * \file Piece.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Piece
 * \author Étudiant 1, étudiant 2
 * \version 0.1
 * \date juin 2014
 *
 */

#include "Piece.h"

namespace TP1
{

	//constructeur par défaut
	Piece::Piece() : portes(ListePortes()), parcourue(false)
	{

	}

	//Surcharge du constructeur, le nom de la pièce en argument
	Piece::Piece(const std::string& s) : portes(ListePortes()), parcourue(false), nom(s)
	{

	}

	//destructeur
	Piece:: ~Piece()
	{
		portes.~ListePortes();
	}

	//constructeur de copie
	Piece::Piece(const Piece& p)
	{
	   portes = p.portes;
	   parcourue = p.parcourue;
	   nom = p.nom;
	}

	//Surcharge de l'opérateur =
	const Piece& Piece::operator =(const Piece& source)
	{
	   if (this != &source)
	   {
	      portes = source.portes;
	      parcourue = source.parcourue;
         nom = source.nom;
	   }

		return (*this);
	}

	//Accesseur du nom d'une pièce
	std::string Piece::getNom() const
	{
		return nom;
	}

	//Pour initialiser l'attibut parcourue à true ou false
	void Piece::setParcourue(bool p)
	{
		parcourue = p;
	}

	//Acceder au membre parcourue
	bool Piece::getParcourue() const
	{
		return parcourue;
	}

	//Accéder à la liste des portes qui partent de la pièce
	const ListePortes & Piece::getPortes() const
	{
		return portes;
	}

	//Ajouter une porte à la liste des portes qui partent de la pièce
	void  Piece::ajoutePorte(Porte& p)
	{
		portes.ajoutePorte(p);
	}

}
