/**
 * \file FilePieces.h
 * \brief Ce fichier contient l'interface d'une file.
 * \author Admin
 * \version 0.1
 * \date mai 2014
 * 
 */

#ifndef FILEPIECES_H_
#define FILEPIECES_H_

#include <stdexcept>
#include <string>

#include "Chemin.h"

namespace TP1
{

class FilePieces
{
public:
	//Constructeur par défaut
	FilePieces();

	//Destructeur
	virtual ~FilePieces();

	//constructeur de copie
	FilePieces(const FilePieces&);

	//Surcharge de l'opérateur =
	const FilePieces& operator =(const FilePieces& source);

	//Ajoute une pièce à la fin d'une file de pièces. Puisqu'une file de pièces est définie
	//par un chemin, cette méthode ne fera qu'un appel simple à la méthode ajoutePiece().
	void enfilePiece(const std::string &nomPiece, int distanceDuDebut);

	//Retire une pièce du début d'une file et place le nom de la pièce retirée dans nomPieceRetiree,
	//et sa distance du début dans distanceDuDebut. Puisqu'une file de pièces est définie par un chemin,
	//cette fonction fera un appel à la fonction retirePiece(). Une exception logic_error devra être levée si la file est vide.
	void defilePiece(std::string & nomPieceRetiree, int &distanceDuDebut);

	//Vérifie si une file de pièces est vide
	bool estVideFile() const;

private:
	// Une file est définie comme étant un chemin. Ainsi, les fonctions qui permettent d'opérer la file
	// seront implémentées tout simplement par des appels aux fonctions permettant d'opérer sur un chemin.
	Chemin ch;

};

}

#endif /* FILEPIECES_H_ */
