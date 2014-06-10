/**
 * \file Piece.h
 * \brief Ce fichier contient l'interface d'une pièce.
 * \author Admin
 * \version 0.1
 * \date mai 2014
 */

// Révision des commentaires avec balises Doxygen.
// Fichier mis à jour par : Éric Guillemette, Mathieu L'Écuyer

#ifndef PIECE_H_
#define PIECE_H_

#include <stdexcept>
#include <string>

#include "Porte.h"
#include "ListePortes.h"

/**
 * \namespace TP1
 *
 * Espace de nommage regroupant les définitions du TP1.
 */
namespace TP1
{

/**
 * \class Piece
 * \brief Cette classe sert à définir une piece.
 *
 * Une pièce est décrite par une liste de portes, un nom (chaîne de caractères) qui doit être
 * unique pour chaque pièce et un booléen pour indiquer si la pièce a déjà été parcourue ou non.
 */
class Piece
{
public:
   /**
    * \brief Constructeur par défaut.
    *
    * \post Une instance de la classe Piece est initialisée.
    */
   Piece();

   /**
    * \brief Surcharge du constructeur avec le nom de la pièce en argument.
    *
    * \post Une instance de la classe Piece est initialisée.
    */
   Piece(const std::string& s);

   /**
    * \brief Destructeur.
    *
    * \post L'instance de la Piece est détruite.
    */
   virtual ~Piece();

   /**
    * \brief Constructeur de copie.
    *
    * \post Une copie profonde d'un objet Piece existant est initialisée.
    */
   Piece(const Piece&);

   /**
    * \brief Surcharge de l'opérateur d'assignation =
    *
    * \post Une copie d'une Piece est retournée.
    */
   const Piece& operator =(const Piece& source);

   /**
    * \brief Méthode accesseur du nom d'une pièce.
    *
    * \post Le nom de la pièce est retourné.
    */
   std::string getNom() const;

   /**
    * \brief Cette méthode initialise l'attribut parcourue à vrai ou faux.
    *
    * \post La valeur de parcourue a été changée pour vrai si la pièce a été parcourue, faux sinon.
    */
   void setParcourue(bool p);

   /**
    * \brief Méthode accesseur du membre parcourue.
    *
    * \post La valeur de l'attribut parcourue est retournée.
    */
   bool getParcourue() const;

   /**
    * \brief Méthode pour accéder à la liste de portes de la pièce.
    *
    * \post La liste de portes est retournée.
    */
   const ListePortes& getPortes() const;

   /**
    * \brief Cette méthode permet d'ajouter une porte à la liste de portes.
    *
    * \post La porte est ajoutée à la liste de portes.
    */
   void ajoutePorte(Porte& p);

private:
   ListePortes portes; /*!< La liste de portes contenant les portes qui partent de la pièce.
                            Cette liste peut ne pas contenir toutes les portes qui communiquent
                            avec la pièce. Une partie de ces portes peut être placée dans la liste
                            de portes de l'autre pièce associée à la porte. */

   bool parcourue; /*!< L'attribut parcourue sert uniquement à la méthode solutionner() afin de
                        ne pas passer plusieurs fois par une même pièce et risquer de tourner en
                        rond, et donc boucler sans fin. */

   std::string nom; /*!< Le nom de la pièce. Il doit être unique pour un même labyrinthe. */
};

} // namespace TP1

#endif /* PIECE_H_ */
