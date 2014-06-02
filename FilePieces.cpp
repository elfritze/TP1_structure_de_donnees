/**
 * \file FilePieces.cpp
 * \brief Ce fichier contient une implantation des m�thodes de la classe FilePieces
 * \author �tudiant 1, �tudiant 2
 * \version 0.1
 * \date juin 2014
 *
 */

#include "FilePieces.h"

namespace TP1
{

	//Constructeur par d�faut
	FilePieces::FilePieces()
	{
		ch = Chemin();
	}

	//Destructeur
	FilePieces:: ~FilePieces()
	{
		ch.~Chemin();
	}

	//constructeur de copie
	FilePieces::FilePieces(const FilePieces& f)
	{
		ch = f.ch;
	}

	//Surcharge de l'op�rateur =
	const FilePieces& FilePieces::operator =(const FilePieces& source)
	{
		return source;
	}

	//Ajoute une pi�ce � la fin d'une file de pi�ces. Puisqu'une file de pi�ces est d�finie
	//par un chemin, cette m�thode ne fera qu'un appel simple � la m�thode ajoutePiece().
	void FilePieces::enfilePiece(const std::string &nomPiece, int distanceDuDebut)
	{
		ch.ajoutePiece(nomPiece,distanceDuDebut);
	}

	//Retire une pi�ce du d�but d'une file et place le nom de la pi�ce retir�e dans nomPieceRetiree,
	//et sa distance du d�but dans distanceDuDebut. Puisqu'une file de pi�ces est d�finie par un chemin,
	//cette fonction fera un appel � la fonction retirePiece(). Une exception logic_error devra �tre lev�e si la file est vide.
	void FilePieces::defilePiece(std::string & nomPieceRetiree, int &distanceDuDebut)
	{
		nomPieceRetiree = ch.getNomPiece();
		distanceDuDebut = ch.getDistanceDuDebut();
		ch.retirePiece(1);
	}

	//V�rifie si une file de pi�ces est vide
	bool FilePieces::estVideFile() const
	{
		return ch.tailleChemin()==0;
	}

}