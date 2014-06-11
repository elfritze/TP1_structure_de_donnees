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
   ch = f.ch; // surcharge de l'opérateur d'assignation de Chemin
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
   if (this != &source)
   {
      ch = source.ch; // surcharge de l'opérateur d'assignation de Chemin
   }

   return (*this);
}

/**
 * \fn void FilePieces::enfilePiece(const std::string &nomPiece, int distanceDuDebut)
 *
 * \param[in] nomPiece : Le nom de la pièce à ajouter à la file.
 * \param[in] distanceDuDebut : Le nombre de déplacement depuis le début du labyrinthe.
 */
void FilePieces::enfilePiece(const std::string &nomPiece, int distanceDuDebut)
{
   // appel de la méthode ajoutePiece() de la classe Chemin
   ch.ajoutePiece(nomPiece, distanceDuDebut);
}

/**
 * \fn void FilePieces::defilePiece(std::string & nomPieceRetiree, int &distanceDuDebut)
 *
 * \param[in] nomPieceRetiree : Un nom de pièce.
 * \param[in] distanceDuDebut : Un nombre de déplacement depuis le début du labyrinthe.
 */
void FilePieces::defilePiece(std::string & nomPieceRetiree, int &distanceDuDebut)
{
   // Si la file est vide, une exception sera lancée

   if (!estVideFile())
   {
      nomPieceRetiree = ch.getNomPiece();
      distanceDuDebut = ch.getDistanceDuDebut();
      ch.retirePiece(1);
   }
   else
   {
      throw std::logic_error("defilePiece: La file est vide");
   }
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
