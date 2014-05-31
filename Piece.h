/**
 * \file Piece.h
 * \brief Ce fichier contient l'interface d'une pi�ce.
 * \author Admin
 * \version 0.1
 * \date mai 2014
 * 
 */

#ifndef PIECE_H_
#define PIECE_H_

#include <stdexcept>
#include <string>

#include "Porte.h"
#include "ListePortes.h"

namespace TP1
{

class Piece
{
public:
	//constructeur par d�faut
	Piece();

	//Surcharge du constructeur, le nom de la pi�ce en argument
	Piece(const std::string & s);

	//destructeur
	virtual ~Piece();

	//constructeur de copie
	Piece(const Piece&);

	//Surcharge de l'op�rateur =
	const Piece& operator =(const Piece& source);

	//Accesseur du nom d'une pi�ce
	std::string getNom() const;

	//Pour initialiser l'attibut parcourue � true ou false
	void setParcourue(bool p);

	//Acceder au membre parcourue
	bool getParcourue() const;

	//Acc�der � la liste des portes qui partent de la pi�ce
	const ListePortes & getPortes() const;

	//Ajouter une porte � la liste des portes qui partent de la pi�ce
	void ajoutePorte(Porte& p);

private:
	// Les portes qui partent de la pi�ce. Cette liste peut ne pas contenir toutes les portes qui
	// communiquent avec la pi�ce. Une partie de ces portes peut �tre plac�e dans la liste de portes
	// de l'autre pi�ce associ�e � la porte.
	ListePortes portes;

	// Le champ "parcourue" sert uniquement � la m�thode solutionner() d�crite plus bas, afin de ne pas passer
	// plusieurs fois par une m�me pi�ce et risquer de tourner en rond, et donc boucler sans fin.
	bool parcourue;

	// Le nom de la pi�ce. Il doit �tre unique pour un m�me labyrinthe.
	std::string nom;
};

}

#endif /* PIECE_H_ */
