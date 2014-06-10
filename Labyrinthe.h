/**
 * \file Labyrinthe.h
 * \brief Ce fichier contient l'interface d'un labyrinthe.
 * \author Admin
 * \version 0.1
 * \date mai 2014
 */

// R�vision des commentaires avec balises Doxygen.
// Fichier mis � jour par : �ric Guillemette, Mathieu L'�cuyer

#ifndef LABYRINTHE_H_
#define LABYRINTHE_H_

#include <stdexcept>
#include <iostream>
#include <fstream> // pour les fichiers
#include <sstream> // lecture/�criture dans un string, voir la m�thode chargeLabyrinthe() fournie
#include <string>

#include "Chemin.h"
#include "Porte.h"
#include "Piece.h"
#include "FilePieces.h"

/**
 * \namespace TP1
 *
 * Espace de nommage regroupant les d�finitions du TP1.
 */
namespace TP1
{

/**
 * \class Labyrinthe
 * \brief Cette classe sert � d�finir un labyrinthe utilisant une liste cha�n�e circulaire.
 *
 * Un labyrinthe utilise une liste cha�n�e circulaire de pi�ces. Il est d�crit par un pointeur vers
 * la derni�re pi�ce de la liste, un pointeur vers la pi�ce de d�part et un pointeur vers la pi�ce
 * d'arriv�e. La premi�re pi�ce de cette liste n'est pas n�cessairement la pi�ce de d�part et la
 * derni�re pi�ce n'est pas n�cessairement la pi�ce d'arriv�e du labyrinthe. Les pointeurs depart
 * et arrivee indique la pi�ce de d�part et la pi�ce d'arriv�e.
 */
class Labyrinthe
{
public:
   /**
    * \brief Constructeur par d�faut.
    *
    * \post Une instance de la classe Labyrinthe est initialis�e.
    */
	Labyrinthe();

   /**
    * \brief Destructeur.
    *
    * \post L'instance de Labyrinthe est d�truite.
    */
	virtual ~Labyrinthe();

   /**
    * \brief Constructeur de copie.
    *
    * \post Une copie profonde d'un objet Labyrinthe existant est initialis�e.
    */
	Labyrinthe(const Labyrinthe&);

   /**
    * \brief Surcharge de l'op�rateur d'assignation =
    *
    * \post Une copie de Labyrinthe est retourn�e.
    */
	const Labyrinthe& operator =(const Labyrinthe& source);

	/**
    * \brief Cette m�thode charge un fichier contenant un labyrinthe d'une certaine couleur.
    *
    * \post Les pi�ces et leurs portes sont cr��es dans le labyrinthe.
    */
	void chargeLabyrinthe(Couleur couleur, std::ifstream &entree);

	/**
    * \brief Cette m�thode ajoute une pi�ce � un labyrinthe. Dans le cas o� une pi�ce du labyrinthe
    *        porte d�j� un m�me nom, la m�thode ne fait rien.
    *
    * \post Une pi�ce est ajout�e au labyrinthe si elle n'�tait pas d�j� pr�sente.
    */
	void ajoutePieceLabyrinthe(Piece &p);

	/**
    * \brief Cette m�thode solutionne un labyrinthe pour le joueur sp�cifi� par joueur.
    *        Elle trouve ainsi en combien d'�tapes au minimum le joueur sp�cifi� peut solutionner
    *        le labyrinthe, en ne passant que par les portes qui correspondent � sa couleur.
    *
    * \post Le nombre d'�tapes n�cessaires pour solutionner le labyrinthe est retourn�.
    */
	int solutionner(Couleur joueur);

	/**
    * \brief Cette m�thode appelle quatre foiss la m�thode solutionner(), une fois par couleur,
    *        pour d�terminer quel est le joueur qui peut solutionner le labyrinthe en le moins
    *        de d�placement. Si aucun joueur ne peut solutionner un labyrinthe, Aucun est retourn�.
    *
    * \post La couleur du joueur gagnant est retourn�e, ou Aucun s'il n'y a pas de gagnant.
    */
	Couleur trouveGagnant();

	/**
    * \brief Cette m�thode retourne le chemin que doit prendre le joueur pour solutionner le
    *        labyrinthe. S'il n'y a aucun chemin possible, un chemin vide est retourn�.
    *
    * \post Un chemin pour solutionner le labyrinthe est cr��.
    */
	Chemin cheminLabyrinthe(Couleur joueur);

private:
	/**
    * \brief Cette m�thode priv�e ajoute un passage dans le labyrinthe.
    *
    * \post Une porte de la couleur sp�cifi�e est ajout�e � une pi�ce pour permettre de passer
    *       de la pi�ce � la suivante.
    */
	void ajoutePassage(Couleur couleur, int i1, int j1, int i2, int j2);

	/**
    * \brief Cette m�thode priv�e ajuste le pointeur depart d'un labyrinthe pour qu'il contienne
    *        l'adresse de la pi�ce correspondant au nom sp�cifi� par le param�tre nom.
    *
    * \post Le pointeur depart pointe � pr�sent sur la pi�ce de d�part.
    *
    * \exception logic_error Si aucune pi�ce du labyrinthe ne porte le nom sp�cifi�.
    */
	void placeDepart(std::string& nom);

	/**
    * \brief Cette m�thode priv�e ajuste le pointeur arrivee d'un labyrinthe pour qu'il contienne
    *        l'adresse de la pi�ce correspondant au nom sp�cifi� par le param�tre nom.
    *
    * \post Le pointeur arrivee pointe � pr�sent sur la pi�ce d'arriv�e.
    *
    * \exception logic_error Si aucune pi�ce du labyrinthe ne porte le nom sp�cifi�.
    */
	void placeArrivee(std::string& nom);

   /**
    * \class NoeudListePieces
    *
    * \brief Classe interne repr�sentant un noeud typique.
    *
    * Cette classe repr�sente un noeud typique pour impl�menter une liste cha�n�e circulaire.
    */
	class NoeudListePieces
	{
		public:
			Piece piece; /*!< La piece contenue dans un noeud d'une liste cha�n�e circulaire. */

			NoeudListePieces *suivant; /*!< Le noeud suivant de la liste. */

         /**
          * \brief Constructeur de la classe NoeudListePieces.
          *
          * \post Un noeud typique est initialis�.
          */
			explicit NoeudListePieces (const Piece& data_item, NoeudListePieces * next_ptr = 0) :
										      piece(data_item), suivant(next_ptr) {}
	};

	/**
    * \brief Cette m�thode priv�e retourne l'adresse du noeud de la liste de pi�ces contenue dans
    *        le labyrinthe qui correspond � la pi�ce portant le nom sp�cifi�.
    *
    * \pre Le nom de la pi�ce ne doit pas �tre vide.
    *
    * \post L'adresse du noeud contenant la pi�ce trouv�e est retourn�e.
    *
    * \exception invalid_argument Si le nom de la pi�ce est vide.
    * \exception logic_error Si la pi�ce est introuvable.
    */
	NoeudListePieces *trouvePiece(std::string &nom) const;

	NoeudListePieces *dernier; /*!< Le dernier noeud de la liste cha�n�e circulaire. Ce noeuds ne
	                                contient pas n�cessairement les pi�ces de d�part ou d'arriv�e. */

	Piece *depart, *arrivee; /*!< Adresses des pi�ces de d�part et d'arriv�e. Ces adresses sont
	                              celles des pi�ces dans la liste de pi�ces. */

	// M�thodes priv�es

   /**
    * \brief Cette m�thode priv�e sert � copier.
    *
    * \post Une copie profonde est cr��e.
    */
	void _copier( NoeudListePieces *);

   /**
    * \brief Cette m�thode priv�e sert � d�truire un labyrinthe.
    *
    * \post Le labyrinthe est d�truit.
    */
	void _detruire();
};

} // namespace TP1

#endif /* LABYRINTHE_H_ */
