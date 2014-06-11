/**
 * \file FilePieces.cpp
 * \brief Ce fichier contient une implantation des m�thodes de la classe FilePieces
 * \author �ric Guillemette, Mathieu L'�cuyer
 * \version 0.1
 * \date juin 2014
 */

#include "FilePieces.h"

/**
 * \namespace TP1
 *
 * Espace de nommage regroupant les d�finitions du TP1.
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
   ch = f.ch; // surcharge de l'op�rateur d'assignation de Chemin
}

/**
 * \fn const FilePieces& FilePieces::operator =(const FilePieces& source)
 *
 * \param[in] source : Un objet FilePieces existant.
 *
 * \return L'objet courant contenant � pr�sent les donn�es de l'objet source.
 */
const FilePieces& FilePieces::operator =(const FilePieces& source)
{
   if (this != &source)
   {
      ch = source.ch; // surcharge de l'op�rateur d'assignation de Chemin
   }

   return (*this);
}

/**
 * \fn void FilePieces::enfilePiece(const std::string &nomPiece, int distanceDuDebut)
 *
 * \param[in] nomPiece : Le nom de la pi�ce � ajouter � la file.
 * \param[in] distanceDuDebut : Le nombre de d�placement depuis le d�but du labyrinthe.
 */
void FilePieces::enfilePiece(const std::string &nomPiece, int distanceDuDebut)
{
   // appel de la m�thode ajoutePiece() de la classe Chemin
   ch.ajoutePiece(nomPiece, distanceDuDebut);
}

/**
 * \fn void FilePieces::defilePiece(std::string & nomPieceRetiree, int &distanceDuDebut)
 *
 * \param[in] nomPieceRetiree : Un nom de pi�ce.
 * \param[in] distanceDuDebut : Un nombre de d�placement depuis le d�but du labyrinthe.
 */
void FilePieces::defilePiece(std::string & nomPieceRetiree, int &distanceDuDebut)
{
   // Si la file est vide, une exception sera lanc�e

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
 * \return Un bool�en VRAI si la file est vide, FAUX sinon.
 */
bool FilePieces::estVideFile() const
{
   return ch.tailleChemin() == 0;
}

} // namespace TP1
