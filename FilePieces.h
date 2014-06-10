/**
 * \file FilePieces.h
 * \brief Ce fichier contient l'interface d'une file.
 * \author Admin
 * \version 0.1
 * \date mai 2014
 */

// R�vision des commentaires avec balises Doxygen.
// Fichier mis � jour par : �ric Guillemette, Mathieu L'�cuyer

#ifndef FILEPIECES_H_
#define FILEPIECES_H_

#include <stdexcept>
#include <string>

#include "Chemin.h"

/**
 * \namespace TP1
 *
 * Espace de nommage regroupant les d�finitions du TP1.
 */
namespace TP1
{

/**
 * \class FilePieces
 * \brief Cette classe sert � d�finir une file de pi�ces.
 *
 * Une file de pi�ces est d�finie par un chemin et sert � r�soudre la m�thode solutionLabyrinthe()
 * de la classe Labyrinthe. Les fonctions qui permettent d'op�rer la file seront impl�ment�es tout
 * simplement par des appels aux fonctions permettant d'op�rer sur un chemin.
 */
class FilePieces
{
public:
   /**
    * \brief Constructeur par d�faut.
    *
    * \post Une instance de la classe FilePieces est initialis�e.
    */
   FilePieces();

   /**
    * \brief Destructeur.
    *
    * \post L'instance de FilePieces est d�truite.
    */
   virtual ~FilePieces();

   /**
    * \brief Constructeur de copie.
    *
    * \post Une copie profonde d'un objet FilePieces existant est initialis�e.
    */
   FilePieces(const FilePieces&);

   /**
    * \brief Surcharge de l'op�rateur d'assignation =
    *
    * \post Une copie de FilePieces est retourn�e.
    */
   const FilePieces& operator =(const FilePieces& source);

   /**
    * \brief Ajoute une pi�ce � la fin d'une file de pi�ces.
    *
    * \post Une pi�ce est ajout�e � la file de pi�ces.
    */
   void enfilePiece(const std::string &nomPiece, int distanceDuDebut);

   /**
    * \brief Retire une pi�ce du d�but d'une file.
    *
    * \pre La file de pi�ces ne doit pas �tre vide.
    *
    * \post Le nom de la pi�ce retir�e est plac� dans nomPieceRetiree et sa distance du d�but
    *       est plac� dans distanceDuDebut.
    *
    * \exception logic_error : Si la file est vide.
    */
   void defilePiece(std::string & nomPieceRetiree, int &distanceDuDebut);

   /**
    * \brief Cette m�thode v�rifie si la file de pi�ces est vide.
    *
    * \post VRAI est retourn� si la file est vide, FAUX sinon.
    */
   bool estVideFile() const;

private:
   Chemin ch; /*!< Une file est d�finie comme �tant un chemin. Les fonctions impl�ment�es font
                   tout simplement des appels aux fonctions permettant d'op�rer un chemin. */
};

} // namespace TP1

#endif /* FILEPIECES_H_ */
