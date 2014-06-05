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
	Piece::Piece() : portes(ListePortes()), parcourue(false)
	{

	}

	//Surcharge du constructeur, le nom de la pi�ce en argument
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

	//Surcharge de l'op�rateur =
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

	//Accesseur du nom d'une pi�ce
	std::string Piece::getNom() const
	{
		return nom;
	}

	//Pour initialiser l'attibut parcourue � true ou false
	void Piece::setParcourue(bool p)
	{
		parcourue = p;
	}

	//Acceder au membre parcourue
	bool Piece::getParcourue() const
	{
		return parcourue;
	}

	//Acc�der � la liste des portes qui partent de la pi�ce
	const ListePortes & Piece::getPortes() const
	{
		return portes;
	}

	//Ajouter une porte � la liste des portes qui partent de la pi�ce
	void  Piece::ajoutePorte(Porte& p)
	{
		portes.ajoutePorte(p);
	}

}
