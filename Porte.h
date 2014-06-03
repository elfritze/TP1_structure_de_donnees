/**
 * \file Porte.h
 * \brief Ce fichier contient l'interface d'une porte.
 * \author Admin
 * \version 0.1
 * \date mai 2014
 * 
 */

#ifndef PORTE_H_
#define PORTE_H_

#include <stdexcept>

namespace TP1
{
/* Couleur d'une porte ou d'un joueur.
 La valeur "Aucun" est une valeur spéciale utilisée dans la fonction "trouveGagnant".*/
typedef enum
{
   Rouge, Vert, Bleu, Jaune, Aucun
} Couleur;

// La ligne qui suit sert à signifier au compilateur que la classe "Piece" existe.
// Nous n'avons pas le choix de procéder de cette manière, car la structure "Porte"
// comporte des pointeurs vers la classe "Piece", et vice versa.
class Piece;

class Porte
{
public:
   //Constructeur, en argument la couleur de la porte ainsi que la pièce de destination
   Porte(Couleur c, Piece * d);

   //constructeur par défaut
   Porte();

   //un destructeur qui ne fera rien
   virtual ~Porte();

   //Constructeur de copie
   Porte(const Porte&);

   //Surcharge de l'opérateur =
   const Porte& operator =(const Porte& source);

   //accesseur de la couleur d'une porte
   Couleur getCouleur() const;

   //Accesseur de la piece de destination
   Piece * getDestination() const;

private:
   Piece * destination; // Vers où la porte mène.
   Couleur color; // Couleur de la porte. Cette couleur spécifie en même temps
   // quel est le joueur qui a le droit de franchir cette porte.
};

}

#endif /* PORTE_H_ */
