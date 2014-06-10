/**
 * \file Piece.h
 * \brief Ce fichier contient l'interface d'une pi�ce.
 * \author Admin
 * \version 0.1
 * \date mai 2014
 */

// R�vision des commentaires avec balises Doxygen.
// Fichier mis � jour par : �ric Guillemette, Mathieu L'�cuyer

#ifndef PIECE_H_
#define PIECE_H_

#include <stdexcept>
#include <string>

#include "Porte.h"
#include "ListePortes.h"

/**
 * \namespace TP1
 *
 * Espace de nommage regroupant les d�finitions du TP1.
 */
namespace TP1
{

/**
 * \class Piece
 * \brief Cette classe sert � d�finir une piece.
 *
 * Une pi�ce est d�crite par une liste de portes, un nom (cha�ne de caract�res) qui doit �tre
 * unique pour chaque pi�ce et un bool�en pour indiquer si la pi�ce a d�j� �t� parcourue ou non.
 */
class Piece
{
public:
   /**
    * \brief Constructeur par d�faut.
    *
    * \post Une instance de la classe Piece est initialis�e.
    */
   Piece();

   /**
    * \brief Surcharge du constructeur avec le nom de la pi�ce en argument.
    *
    * \post Une instance de la classe Piece est initialis�e.
    */
   Piece(const std::string& s);

   /**
    * \brief Destructeur.
    *
    * \post L'instance de la Piece est d�truite.
    */
   virtual ~Piece();

   /**
    * \brief Constructeur de copie.
    *
    * \post Une copie profonde d'un objet Piece existant est initialis�e.
    */
   Piece(const Piece&);

   /**
    * \brief Surcharge de l'op�rateur d'assignation =
    *
    * \post Une copie d'une Piece est retourn�e.
    */
   const Piece& operator =(const Piece& source);

   /**
    * \brief M�thode accesseur du nom d'une pi�ce.
    *
    * \post Le nom de la pi�ce est retourn�.
    */
   std::string getNom() const;

   /**
    * \brief Cette m�thode initialise l'attribut parcourue � vrai ou faux.
    *
    * \post La valeur de parcourue a �t� chang�e pour vrai si la pi�ce a �t� parcourue, faux sinon.
    */
   void setParcourue(bool p);

   /**
    * \brief M�thode accesseur du membre parcourue.
    *
    * \post La valeur de l'attribut parcourue est retourn�e.
    */
   bool getParcourue() const;

   /**
    * \brief M�thode pour acc�der � la liste de portes de la pi�ce.
    *
    * \post La liste de portes est retourn�e.
    */
   const ListePortes& getPortes() const;

   /**
    * \brief Cette m�thode permet d'ajouter une porte � la liste de portes.
    *
    * \post La porte est ajout�e � la liste de portes.
    */
   void ajoutePorte(Porte& p);

private:
   ListePortes portes; /*!< La liste de portes contenant les portes qui partent de la pi�ce.
                            Cette liste peut ne pas contenir toutes les portes qui communiquent
                            avec la pi�ce. Une partie de ces portes peut �tre plac�e dans la liste
                            de portes de l'autre pi�ce associ�e � la porte. */

   bool parcourue; /*!< L'attribut parcourue sert uniquement � la m�thode solutionner() afin de
                        ne pas passer plusieurs fois par une m�me pi�ce et risquer de tourner en
                        rond, et donc boucler sans fin. */

   std::string nom; /*!< Le nom de la pi�ce. Il doit �tre unique pour un m�me labyrinthe. */
};

} // namespace TP1

#endif /* PIECE_H_ */
