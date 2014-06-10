/**
 * \file FilePieces.h
 * \brief Ce fichier contient l'interface d'une file.
 * \author Admin
 * \version 0.1
 * \date mai 2014
 */

// Révision des commentaires avec balises Doxygen.
// Fichier mis à jour par : Éric Guillemette, Mathieu L'Écuyer

#ifndef FILEPIECES_H_
#define FILEPIECES_H_

#include <stdexcept>
#include <string>

#include "Chemin.h"

/**
 * \namespace TP1
 *
 * Espace de nommage regroupant les définitions du TP1.
 */
namespace TP1
{

/**
 * \class FilePieces
 * \brief Cette classe sert à définir une file de pièces.
 *
 * Une file de pièces est définie par un chemin et sert à résoudre la méthode solutionLabyrinthe()
 * de la classe Labyrinthe. Les fonctions qui permettent d'opérer la file seront implémentées tout
 * simplement par des appels aux fonctions permettant d'opérer sur un chemin.
 */
class FilePieces
{
public:
   /**
    * \brief Constructeur par défaut.
    *
    * \post Une instance de la classe FilePieces est initialisée.
    */
   FilePieces();

   /**
    * \brief Destructeur.
    *
    * \post L'instance de FilePieces est détruite.
    */
   virtual ~FilePieces();

   /**
    * \brief Constructeur de copie.
    *
    * \post Une copie profonde d'un objet FilePieces existant est initialisée.
    */
   FilePieces(const FilePieces&);

   /**
    * \brief Surcharge de l'opérateur d'assignation =
    *
    * \post Une copie de FilePieces est retournée.
    */
   const FilePieces& operator =(const FilePieces& source);

   /**
    * \brief Ajoute une pièce à la fin d'une file de pièces.
    *
    * \post Une pièce est ajoutée à la file de pièces.
    */
   void enfilePiece(const std::string &nomPiece, int distanceDuDebut);

   /**
    * \brief Retire une pièce du début d'une file.
    *
    * \pre La file de pièces ne doit pas être vide.
    *
    * \post Le nom de la pièce retirée est placé dans nomPieceRetiree et sa distance du début
    *       est placé dans distanceDuDebut.
    *
    * \exception logic_error : Si la file est vide.
    */
   void defilePiece(std::string & nomPieceRetiree, int &distanceDuDebut);

   /**
    * \brief Cette méthode vérifie si la file de pièces est vide.
    *
    * \post VRAI est retourné si la file est vide, FAUX sinon.
    */
   bool estVideFile() const;

private:
   Chemin ch; /*!< Une file est définie comme étant un chemin. Les fonctions implémentées font
                   tout simplement des appels aux fonctions permettant d'opérer un chemin. */
};

} // namespace TP1

#endif /* FILEPIECES_H_ */
