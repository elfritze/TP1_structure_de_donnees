/**
 * \file FilePieces.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe FilePieces
 * \author Étudiant 1, étudiant 2
 * \version 0.1
 * \date juin 2014
 *
 */

#include "FilePieces.h"

namespace TP1
{

	//Constructeur par défaut
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

	//Surcharge de l'opérateur =
	const FilePieces& FilePieces::operator =(const FilePieces& source)
	{
		return source;
	}

	//Ajoute une pièce à la fin d'une file de pièces. Puisqu'une file de pièces est définie
	//par un chemin, cette méthode ne fera qu'un appel simple à la méthode ajoutePiece().
	void FilePieces::enfilePiece(const std::string &nomPiece, int distanceDuDebut)
	{
		ch.ajoutePiece(nomPiece,distanceDuDebut);
	}

	//Retire une pièce du début d'une file et place le nom de la pièce retirée dans nomPieceRetiree,
	//et sa distance du début dans distanceDuDebut. Puisqu'une file de pièces est définie par un chemin,
	//cette fonction fera un appel à la fonction retirePiece(). Une exception logic_error devra être levée si la file est vide.
	void FilePieces::defilePiece(std::string & nomPieceRetiree, int &distanceDuDebut)
	{
		nomPieceRetiree = ch.getNomPiece();
		distanceDuDebut = ch.getDistanceDuDebut();
		ch.retirePiece(1);
	}

	//Vérifie si une file de pièces est vide
	bool FilePieces::estVideFile() const
	{
		return ch.tailleChemin()==0;
	}

}