/**
 * \file Porte.h
 * \brief Ce fichier contient l'interface d'une porte.
 * \author Admin
 * \version 0.1
 * \date mai 2014
 */

// Révision des commentaires avec balises Doxygen.
// Fichier mis à jour par : Éric Guillemette, Mathieu L'Écuyer

#ifndef PORTE_H_
#define PORTE_H_

#include <stdexcept>

/**
 * \namespace TP1
 *
 * Espace de nommage regroupant les définitions du TP1.
 */
namespace TP1
{

/**
 * \enum Couleur
 * \brief Couleur d'une porte ou d'un joueur.
 */
typedef enum
{
   Rouge,
   Vert,
   Bleu,
   Jaune,
   Aucun /*!< Valeur spéciale utilisée dans la fonction "trouveGagnant". */
} Couleur;

// La ligne qui suit sert à signifier au compilateur que la classe Piece existe.
// Nous n'avons pas le choix de procéder de cette manière, car la structure Porte
// comporte des pointeurs vers la classe Piece, et vice versa.
class Piece;

/**
 * \class Porte
 * \brief Cette classe sert à définir une porte.
 *
 * Une porte est décrite par une couleur (rouge, vert, bleu ou jaune) et un pointeur
 * vers une pièce du labyrinthe.
 */
class Porte
{
public:
   /**
    * \brief Construteur par défaut.
    *
    * \post Une instance de la classe Porte est initialisée.
    */
   Porte();

   /**
    * \brief Constructeur avec paramètres.
    *
    * \post Une instance de la classe Porte est initialisée.
    */
   Porte(Couleur c, Piece* d);

   /**
    * \brief Destructeur.
    *
    * \post L'instance de la Porte est détruite.
    */
   virtual ~Porte();

   /**
    * \brief Constructeur de copie.
    *
    * \post Une copie profonde d'un objet Porte existant est initialisée.
    */
   Porte(const Porte&);

   /**
    * \brief Surcharge de l'opérateur d'assignation =
    *
    * \post Une copie d'une Porte est retournée.
    */
   const Porte& operator =(const Porte& source);

   /**
    * \brief Méthode accesseur pour la couleur d'une porte.
    *
    * \post La couleur de la porte est retournée.
    */
   Couleur getCouleur() const;

   /**
    * \brief Méthode accesseur pour la pièce de destination d'une porte.
    *
    * \post Le pointeur vers la pièce de destination est retourné.
    */
   Piece* getDestination() const;

private:
   Piece* destination; /*!< Vers où la porte mène. */
   Couleur color; /*!< Couleur de la porte. Cette couleur spécifie en même temps quel est le
                       joueur qui a le droit de franchir cette porte. */
};

} // namespace TP1

#endif /* PORTE_H_ */
