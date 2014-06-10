/**
 * \file Porte.h
 * \brief Ce fichier contient l'interface d'une porte.
 * \author Admin
 * \version 0.1
 * \date mai 2014
 */

// R�vision des commentaires avec balises Doxygen.
// Fichier mis � jour par : �ric Guillemette, Mathieu L'�cuyer

#ifndef PORTE_H_
#define PORTE_H_

#include <stdexcept>

/**
 * \namespace TP1
 *
 * Espace de nommage regroupant les d�finitions du TP1.
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
   Aucun /*!< Valeur sp�ciale utilis�e dans la fonction "trouveGagnant". */
} Couleur;

// La ligne qui suit sert � signifier au compilateur que la classe Piece existe.
// Nous n'avons pas le choix de proc�der de cette mani�re, car la structure Porte
// comporte des pointeurs vers la classe Piece, et vice versa.
class Piece;

/**
 * \class Porte
 * \brief Cette classe sert � d�finir une porte.
 *
 * Une porte est d�crite par une couleur (rouge, vert, bleu ou jaune) et un pointeur
 * vers une pi�ce du labyrinthe.
 */
class Porte
{
public:
   /**
    * \brief Construteur par d�faut.
    *
    * \post Une instance de la classe Porte est initialis�e.
    */
   Porte();

   /**
    * \brief Constructeur avec param�tres.
    *
    * \post Une instance de la classe Porte est initialis�e.
    */
   Porte(Couleur c, Piece* d);

   /**
    * \brief Destructeur.
    *
    * \post L'instance de la Porte est d�truite.
    */
   virtual ~Porte();

   /**
    * \brief Constructeur de copie.
    *
    * \post Une copie profonde d'un objet Porte existant est initialis�e.
    */
   Porte(const Porte&);

   /**
    * \brief Surcharge de l'op�rateur d'assignation =
    *
    * \post Une copie d'une Porte est retourn�e.
    */
   const Porte& operator =(const Porte& source);

   /**
    * \brief M�thode accesseur pour la couleur d'une porte.
    *
    * \post La couleur de la porte est retourn�e.
    */
   Couleur getCouleur() const;

   /**
    * \brief M�thode accesseur pour la pi�ce de destination d'une porte.
    *
    * \post Le pointeur vers la pi�ce de destination est retourn�.
    */
   Piece* getDestination() const;

private:
   Piece* destination; /*!< Vers o� la porte m�ne. */
   Couleur color; /*!< Couleur de la porte. Cette couleur sp�cifie en m�me temps quel est le
                       joueur qui a le droit de franchir cette porte. */
};

} // namespace TP1

#endif /* PORTE_H_ */
