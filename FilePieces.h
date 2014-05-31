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
	//Constructeur par d�faut
	FilePieces();

	//Destructeur
	virtual ~FilePieces();

	//constructeur de copie
	FilePieces(const FilePieces&);

	//Surcharge de l'op�rateur =
	const FilePieces& operator =(const FilePieces& source);

	//Ajoute une pi�ce � la fin d'une file de pi�ces. Puisqu'une file de pi�ces est d�finie
	//par un chemin, cette m�thode ne fera qu'un appel simple � la m�thode ajoutePiece().
	void enfilePiece(const std::string &nomPiece, int distanceDuDebut);

	//Retire une pi�ce du d�but d'une file et place le nom de la pi�ce retir�e dans nomPieceRetiree,
	//et sa distance du d�but dans distanceDuDebut. Puisqu'une file de pi�ces est d�finie par un chemin,
	//cette fonction fera un appel � la fonction retirePiece(). Une exception logic_error devra �tre lev�e si la file est vide.
	void defilePiece(std::string & nomPieceRetiree, int &distanceDuDebut);

	//V�rifie si une file de pi�ces est vide
	bool estVideFile() const;

private:
	// Une file est d�finie comme �tant un chemin. Ainsi, les fonctions qui permettent d'op�rer la file
	// seront impl�ment�es tout simplement par des appels aux fonctions permettant d'op�rer sur un chemin.
	Chemin ch;

};

}

#endif /* FILEPIECES_H_ */
