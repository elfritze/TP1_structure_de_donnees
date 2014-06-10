/**
 * \file Labyrinthe.h
 * \brief Ce fichier contient l'interface d'un labyrinthe.
 * \author Admin
 * \version 0.1
 * \date mai 2014
 */

// Révision des commentaires avec balises Doxygen.
// Fichier mis à jour par : Éric Guillemette, Mathieu L'Écuyer

#ifndef LABYRINTHE_H_
#define LABYRINTHE_H_

#include <stdexcept>
#include <iostream>
#include <fstream> // pour les fichiers
#include <sstream> // lecture/écriture dans un string, voir la méthode chargeLabyrinthe() fournie
#include <string>

#include "Chemin.h"
#include "Porte.h"
#include "Piece.h"
#include "FilePieces.h"

/**
 * \namespace TP1
 *
 * Espace de nommage regroupant les définitions du TP1.
 */
namespace TP1
{

/**
 * \class Labyrinthe
 * \brief Cette classe sert à définir un labyrinthe utilisant une liste chaînée circulaire.
 *
 * Un labyrinthe utilise une liste chaînée circulaire de pièces. Il est décrit par un pointeur vers
 * la dernière pièce de la liste, un pointeur vers la pièce de départ et un pointeur vers la pièce
 * d'arrivée. La première pièce de cette liste n'est pas nécessairement la pièce de départ et la
 * dernière pièce n'est pas nécessairement la pièce d'arrivée du labyrinthe. Les pointeurs depart
 * et arrivee indique la pièce de départ et la pièce d'arrivée.
 */
class Labyrinthe
{
public:
   /**
    * \brief Constructeur par défaut.
    *
    * \post Une instance de la classe Labyrinthe est initialisée.
    */
	Labyrinthe();

   /**
    * \brief Destructeur.
    *
    * \post L'instance de Labyrinthe est détruite.
    */
	virtual ~Labyrinthe();

   /**
    * \brief Constructeur de copie.
    *
    * \post Une copie profonde d'un objet Labyrinthe existant est initialisée.
    */
	Labyrinthe(const Labyrinthe&);

   /**
    * \brief Surcharge de l'opérateur d'assignation =
    *
    * \post Une copie de Labyrinthe est retournée.
    */
	const Labyrinthe& operator =(const Labyrinthe& source);

	/**
    * \brief Cette méthode charge un fichier contenant un labyrinthe d'une certaine couleur.
    *
    * \post Les pièces et leurs portes sont créées dans le labyrinthe.
    */
	void chargeLabyrinthe(Couleur couleur, std::ifstream &entree);

	/**
    * \brief Cette méthode ajoute une pièce à un labyrinthe. Dans le cas où une pièce du labyrinthe
    *        porte déjà un même nom, la méthode ne fait rien.
    *
    * \post Une pièce est ajoutée au labyrinthe si elle n'était pas déjà présente.
    */
	void ajoutePieceLabyrinthe(Piece &p);

	/**
    * \brief Cette méthode solutionne un labyrinthe pour le joueur spécifié par joueur.
    *        Elle trouve ainsi en combien d'étapes au minimum le joueur spécifié peut solutionner
    *        le labyrinthe, en ne passant que par les portes qui correspondent à sa couleur.
    *
    * \post Le nombre d'étapes nécessaires pour solutionner le labyrinthe est retourné.
    */
	int solutionner(Couleur joueur);

	/**
    * \brief Cette méthode appelle quatre foiss la méthode solutionner(), une fois par couleur,
    *        pour déterminer quel est le joueur qui peut solutionner le labyrinthe en le moins
    *        de déplacement. Si aucun joueur ne peut solutionner un labyrinthe, Aucun est retourné.
    *
    * \post La couleur du joueur gagnant est retournée, ou Aucun s'il n'y a pas de gagnant.
    */
	Couleur trouveGagnant();

	/**
    * \brief Cette méthode retourne le chemin que doit prendre le joueur pour solutionner le
    *        labyrinthe. S'il n'y a aucun chemin possible, un chemin vide est retourné.
    *
    * \post Un chemin pour solutionner le labyrinthe est créé.
    */
	Chemin cheminLabyrinthe(Couleur joueur);

private:
	/**
    * \brief Cette méthode privée ajoute un passage dans le labyrinthe.
    *
    * \post Une porte de la couleur spécifiée est ajoutée à une pièce pour permettre de passer
    *       de la pièce à la suivante.
    */
	void ajoutePassage(Couleur couleur, int i1, int j1, int i2, int j2);

	/**
    * \brief Cette méthode privée ajuste le pointeur depart d'un labyrinthe pour qu'il contienne
    *        l'adresse de la pièce correspondant au nom spécifié par le paramètre nom.
    *
    * \post Le pointeur depart pointe à présent sur la pièce de départ.
    *
    * \exception logic_error Si aucune pièce du labyrinthe ne porte le nom spécifié.
    */
	void placeDepart(std::string& nom);

	/**
    * \brief Cette méthode privée ajuste le pointeur arrivee d'un labyrinthe pour qu'il contienne
    *        l'adresse de la pièce correspondant au nom spécifié par le paramètre nom.
    *
    * \post Le pointeur arrivee pointe à présent sur la pièce d'arrivée.
    *
    * \exception logic_error Si aucune pièce du labyrinthe ne porte le nom spécifié.
    */
	void placeArrivee(std::string& nom);

   /**
    * \class NoeudListePieces
    *
    * \brief Classe interne représentant un noeud typique.
    *
    * Cette classe représente un noeud typique pour implémenter une liste chaînée circulaire.
    */
	class NoeudListePieces
	{
		public:
			Piece piece; /*!< La piece contenue dans un noeud d'une liste chaînée circulaire. */

			NoeudListePieces *suivant; /*!< Le noeud suivant de la liste. */

         /**
          * \brief Constructeur de la classe NoeudListePieces.
          *
          * \post Un noeud typique est initialisé.
          */
			explicit NoeudListePieces (const Piece& data_item, NoeudListePieces * next_ptr = 0) :
										      piece(data_item), suivant(next_ptr) {}
	};

	/**
    * \brief Cette méthode privée retourne l'adresse du noeud de la liste de pièces contenue dans
    *        le labyrinthe qui correspond à la pièce portant le nom spécifié.
    *
    * \pre Le nom de la pièce ne doit pas être vide.
    *
    * \post L'adresse du noeud contenant la pièce trouvée est retournée.
    *
    * \exception invalid_argument Si le nom de la pièce est vide.
    * \exception logic_error Si la pièce est introuvable.
    */
	NoeudListePieces *trouvePiece(std::string &nom) const;

	NoeudListePieces *dernier; /*!< Le dernier noeud de la liste chaînée circulaire. Ce noeuds ne
	                                contient pas nécessairement les pièces de départ ou d'arrivée. */

	Piece *depart, *arrivee; /*!< Adresses des pièces de départ et d'arrivée. Ces adresses sont
	                              celles des pièces dans la liste de pièces. */

	// Méthodes privées

   /**
    * \brief Cette méthode privée sert à copier.
    *
    * \post Une copie profonde est créée.
    */
	void _copier( NoeudListePieces *);

   /**
    * \brief Cette méthode privée sert à détruire un labyrinthe.
    *
    * \post Le labyrinthe est détruit.
    */
	void _detruire();
};

} // namespace TP1

#endif /* LABYRINTHE_H_ */
