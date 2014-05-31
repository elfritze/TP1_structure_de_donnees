/**
 * \file Piece.h
 * \brief Ce fichier contient l'interface d'une pièce.
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
	//constructeur par défaut
	Piece();

	//Surcharge du constructeur, le nom de la pièce en argument
	Piece(const std::string & s);

	//destructeur
	virtual ~Piece();

	//constructeur de copie
	Piece(const Piece&);

	//Surcharge de l'opérateur =
	const Piece& operator =(const Piece& source);

	//Accesseur du nom d'une pièce
	std::string getNom() const;

	//Pour initialiser l'attibut parcourue à true ou false
	void setParcourue(bool p);

	//Acceder au membre parcourue
	bool getParcourue() const;

	//Accéder à la liste des portes qui partent de la pièce
	const ListePortes & getPortes() const;

	//Ajouter une porte à la liste des portes qui partent de la pièce
	void ajoutePorte(Porte& p);

private:
	// Les portes qui partent de la pièce. Cette liste peut ne pas contenir toutes les portes qui
	// communiquent avec la pièce. Une partie de ces portes peut être placée dans la liste de portes
	// de l'autre pièce associée à la porte.
	ListePortes portes;

	// Le champ "parcourue" sert uniquement à la méthode solutionner() décrite plus bas, afin de ne pas passer
	// plusieurs fois par une même pièce et risquer de tourner en rond, et donc boucler sans fin.
	bool parcourue;

	// Le nom de la pièce. Il doit être unique pour un même labyrinthe.
	std::string nom;
};

}

#endif /* PIECE_H_ */
