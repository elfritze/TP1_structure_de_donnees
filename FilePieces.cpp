/**
 * \file FilePieces.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe FilePieces
 * \author Éric Guillemette, Mathieu L'Écuyer
 * \version 0.1
 * \date juin 2014
 */

#include "FilePieces.h"

/**
 * \namespace TP1
 *
 * Espace de nommage regroupant les définitions du TP1.
 */
namespace TP1
{

/**
 * \fn FilePieces::FilePieces()
 */
FilePieces::FilePieces() :
      ch(Chemin())
{

}

/**
 * \fn FilePieces::~FilePieces()
 */
FilePieces::~FilePieces()
{
   ch.~Chemin();
}

/**
 * \fn FilePieces::FilePieces(const FilePieces& f)
 *
 * \param[in] f : Un objet FilePieces existant.
 */
FilePieces::FilePieces(const FilePieces& f)
{
   ch = f.ch;
}

/**
 * \fn const FilePieces& FilePieces::operator =(const FilePieces& source)
 *
 * \param[in] source : Un objet FilePieces existant.
 *
 * \return L'objet courant contenant à présent les données de l'objet source.
 */
const FilePieces& FilePieces::operator =(const FilePieces& source)
{
   return source;
}

/**
 * \fn void FilePieces::enfilePiece(const std::string &nomPiece, int distanceDuDebut)
 *
 * \param[in] nomPiece : le nom de la pièce à ajouter à la file.
 * \param[in] distanceDuDebut : le nombre de déplacement depuis le début du labyrinthe.
 */
void FilePieces::enfilePiece(const std::string &nomPiece, int distanceDuDebut)
{
   // appel de la méthode ajoutePiece de la classe chemin
   ch.ajoutePiece(nomPiece, distanceDuDebut);
}

/**
 * \fn void FilePieces::defilePiece(std::string & nomPieceRetiree, int &distanceDuDebut)
 *
 * \param[in] nomPieceRetiree : le nom de la pièce à retirer de la file.
 * \param[in] distanceDuDebut : le nombre de déplacement depuis le début du labyrinthe.
 */
void FilePieces::defilePiece(std::string & nomPieceRetiree, int &distanceDuDebut)
{
   //Retire une pièce du début d'une file et place le nom de la pièce retirée dans nomPieceRetiree,
   //et sa distance du début dans distanceDuDebut. Puisqu'une file de pièces est définie par un chemin,
   //cette fonction fera un appel à la fonction retirePiece().
   //Une exception logic_error devra être levée si la file est vide.

   nomPieceRetiree = ch.getNomPiece();
   distanceDuDebut = ch.getDistanceDuDebut();
   ch.retirePiece(1);
}

/**
 * \fn bool FilePieces::estVideFile() const
 *
 * \return Un booléen VRAI si la file est vide, FAUX sinon.
 */
bool FilePieces::estVideFile() const
{
   return ch.tailleChemin() == 0;
}

} // namespace TP1
