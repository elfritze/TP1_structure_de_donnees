/**
 * \file Labyrinthe.cpp
 * \brief Ce fichier contient l'implantation des méthodes membres et privés de la classe Labyrinthe.
 * \author Admin, Éric Guillemette, Mathieu L'Écuyer
 * \version 0.1
 * \date juin 2014
 */

#include "Labyrinthe.h"

using namespace std;

/**
 * \namespace TP1
 *
 * Espace de nommage regroupant les définitions du TP1.
 */
namespace TP1
{

/**
 * \fn Labyrinthe::Labyrinthe()
 */
Labyrinthe::Labyrinthe() :
      dernier(0), depart(0), arrivee(0)
{
}

/**
 * \fn Labyrinthe::~Labyrinthe()
 */
Labyrinthe::~Labyrinthe()
{
   _detruire();
}

/**
 * \fn Labyrinthe::Labyrinthe(const Labyrinthe& l)
 *
 * \param[in] l : Un objet Labyrinthe existant.
 */
Labyrinthe::Labyrinthe(const Labyrinthe& l)
{
   if (l.dernier == 0)
   {
      dernier = 0; // la liste originale est vide
   }
   else
   {
      _copier(l.dernier);
   }
}

/**
 * \fn const Labyrinthe& Labyrinthe::operator =(const Labyrinthe& source)
 *
 * \param[in] source : Un objet Labyrinthe existant.
 *
 * \return L'objet courant contenant à présent les données de l'objet source.
 */
const Labyrinthe& Labyrinthe::operator =(const Labyrinthe& source)
{
   if (this != &source)
   {
      // On détruit la liste originale
      _detruire();

      if (source.dernier == 0)
      {
         dernier = 0;  // la liste source est vide
      }
      else
      {
         _copier(source.dernier);
      }
   }

   return (*this);
}

// -------------------------------------------------------------------------------------------------
//	Chargement
// -------------------------------------------------------------------------------------------------

/**
 * \fn void Labyrinthe::chargeLabyrinthe(Couleur couleur, std::ifstream &entree)
 * \param[in] couleur : La couleur du joueur auquel le labyrinthe chargé s'applique
 * \param[in] entree : Fichier contenant la définition du labyrinthe
 */
void Labyrinthe::chargeLabyrinthe(Couleur couleur, std::ifstream &entree)
{
   //Voici comment un labyrinthe est mis en mémoire:
   //1- chargerLabyrinthe() appelle ajoutePieceLabyrinthe()
   //2- ajoutePieceLabyrinthe() ajoute la pièce si elle n'existe pas déjà.
   //3- Si la pièce existe déjà, ajoutePieceLabyrinthe() n'ajoute pas de pièce et
   //   laisse le programme rouler
   //4- On sort de ajoutePieceLabyrinthe() et chargerLabyrinthe() fait quelques opérations
   //   pour ensuite appeler ajoutePassage()
   //5- ajoutePassage() ajoute les portes à la pièce qui a été créée ou qui existait déjà
   //6- La pièce et les portes sont créées et on passe à une autre pièce

   int nbCols, nbRangs;

   entree >> nbCols >> nbRangs;
   entree.ignore(); //pour consommer le \n (le caractère fin de ligne)

   const int MAX_LIGNE = 1000;
   char ligne[MAX_LIGNE];

   entree.getline(ligne, MAX_LIGNE);
   entree.getline(ligne, MAX_LIGNE);

   std::ostringstream s; //Une chaîne pour écrire dedans,
                         //cette chaîne servira pour nommer les pièces du labyrinthe

   for (int i = 0; i < nbCols; i++)
   {
      for (int j = 0; j < nbRangs; j++)
      {
         s << i << "," << j;
         Piece p(s.str());
         s.str("");
         ajoutePieceLabyrinthe(p);
      }
   }

   for (int i = 0; i < nbCols; i++)
   {
      if (ligne[i * 4 + 1] == 'D' || ligne[i * 4 + 1] == 'd')
      {
         std::string nom;
         s << i << ",0";
         nom = s.str();
         s.str("");
         placeDepart(nom);
      }
      if (ligne[i * 4 + 1] == 'F' || ligne[i * 4 + 1] == 'f' || ligne[i * 4 + 1] == 'A'
            || ligne[i * 4 + 1] == 'a')
      {
         std::string nom;
         s << i << ",0";
         nom = s.str();
         s.str("");
         placeArrivee(nom);
      }
   }

   for (int j = 0; j < nbRangs; j++)
   {
      entree.getline(ligne, MAX_LIGNE);

      for (int i = (j == nbRangs - 1 && (j & 1)) ? 1 : 0; i < nbCols; i++)
      {
         if (j & 1)
         {
            if (j < nbRangs - 2 && ligne[i * 4 + 3] == ' ')
            {
               ajoutePassage(couleur, i, j, i, j + 2);
            }
            if (j < nbRangs - 1 && ligne[i * 4 + 2] == ' ')
            {
               ajoutePassage(couleur, i, j, i, j + 1);
            }
            if (j < nbRangs - 1 && ligne[i * 4 + 0] == ' ')
            {
               ajoutePassage(couleur, i - 1, j, i, j + 1);
            }
            if (j < nbRangs - 1 && (ligne[i * 4 + 1] == 'D' || ligne[i * 4 + 1] == 'd'))
            {
               std::string nom;
               s << i << "," << j + 1;
               nom = s.str();
               s.str("");
               placeDepart(nom);
            }
            if (j < nbRangs - 1
                  && (ligne[i * 4 + 1] == 'F' || ligne[i * 4 + 1] == 'f' || ligne[i * 4 + 1] == 'A'
                        || ligne[i * 4 + 1] == 'a'))
            {
               std::string nom;
               s << i << "," << j + 1;
               nom = s.str();
               s.str("");
               placeArrivee(nom);
            }
         }
         else
         {
            if (j < nbRangs - 1 && ligne[i * 4 + 0] == ' ')
            {
               ajoutePassage(couleur, i - 1, j + 1, i, j);
            }
            if (j < nbRangs - 2 && ligne[i * 4 + 1] == ' ')
            {
               ajoutePassage(couleur, i, j, i, j + 2);
            }
            if (j < nbRangs - 1 && ligne[i * 4 + 2] == ' ')
            {
               ajoutePassage(couleur, i, j, i, j + 1);
            }
            if (j < nbRangs - 1 && (ligne[i * 4 + 3] == 'D' || ligne[i * 4 + 3] == 'd'))
            {
               std::string nom;
               s << i << "," << j + 1;
               nom = s.str();
               s.str("");
               placeDepart(nom);
            }
            if (j < nbRangs - 1
                  && (ligne[i * 4 + 3] == 'F' || ligne[i * 4 + 3] == 'f' || ligne[i * 4 + 3] == 'A'
                        || ligne[i * 4 + 3] == 'a'))
            {
               std::string nom;
               s << i << "," << j + 1;
               nom = s.str();
               s.str("");
               placeArrivee(nom);
            }
         }
      }
   }
}

// -------------------------------------------------------------------------------------------------

/**
 * \fn void Labyrinthe::ajoutePieceLabyrinthe(Piece &p)
 *
 * \param[in] p : Un objet pièce à ajouter au labyrinthe.
 */
void Labyrinthe::ajoutePieceLabyrinthe(Piece &p)
{
   if (dernier == 0)
   {
      //Dans le cas où la liste est vide
      dernier = new NoeudListePieces(p);
      dernier->suivant = dernier;
   }
   else
   {
      //On parcourt la liste pour vérifier si une pièce porte un même nom
      NoeudListePieces *courant = 0;
      courant = dernier->suivant;
      while (courant != dernier)
      {
         if (courant->piece.getNom() == p.getNom())
            return;
         courant = courant->suivant;
      }

      //On ajoute la pièce à la fin.
      NoeudListePieces *nouveau = new NoeudListePieces(p);
      nouveau->suivant = dernier->suivant;
      dernier->suivant = nouveau;
      dernier = nouveau;
   }
   return;
}

/**
 * \fn int Labyrinthe::solutionner(Couleur joueur)
 *
 * \param[in] joueur : La couleur du joueur.
 *
 * \return Un entier représentant le nombre de déplacements requis pour que le joueur traverse
 *         le labyrinthe.
 */
int Labyrinthe::solutionner(Couleur joueur)
{
   // Si un labyrinthe ne peut pas être solutionné par le joueur, il faut retourner -1.
   // Dans ce cas, il ne s'agit pas d'un appel anormal de la méthode.

   // On réinitialise le chemin pour qu'aucune pièce ne soit parcourue
   dernier->piece.setParcourue(false);
   NoeudListePieces *videur = 0;
   videur = dernier->suivant;
   while (videur != dernier)
   {
      videur->piece.setParcourue(false);
      videur = videur->suivant;
   }
   videur = 0;
   delete videur;

   // Début de l'algorithme de solution
   bool done = false;
   int distance = 0;
   string nomPiece = "";
   Piece * courant = depart;
   Piece * temp = 0;
   FilePieces pieces = FilePieces();
   pieces.enfilePiece(courant->getNom(), 0);
   courant->setParcourue(true);

   do
   {
      // On enlève la première pièce
      pieces.defilePiece(nomPiece, distance);
      courant = &trouvePiece(nomPiece)->piece;

      // Si la pièce défilée est la fin du labyrinthe, on a trouvé la sortie
      if (courant->getNom() == arrivee->getNom())
         done = true;

      // On parcourt toutes les portes de la pièce défilée pour trouver les destinations possibles
      for (int i = 1; i <= courant->getPortes().tailleListePortes(); i++)
      {
         // Destination possible
         temp = courant->getPortes().elementAt(i).getDestination();

         // On s'assure que la porte est de la même couleur que le joueur et
         // qu'elle n'a pas été parcourue.
         if (!temp->getParcourue() && courant->getPortes().elementAt(i).getCouleur() == joueur)
         {
            temp->setParcourue(true);

            // Si la porte est valide, on ajoute sa pièce à la file
            pieces.enfilePiece(temp->getNom(), distance + 1);
         }
      }

      // On parcourt toutes les pièces du labyrinthe à la recherche de portes
      // qui mène à la pièce actuelle
      for (NoeudListePieces * i = dernier->suivant; i != dernier; i = i->suivant)
      {
         // On parcourt chacune des portes de la pièce
         for (int j = 1; j <= i->piece.getPortes().tailleListePortes(); j++)
         {
            temp = i->piece.getPortes().elementAt(j).getDestination();

            // On s'assure que la destination n'est pas parcourue, que la pièce est de la bonne
            // couleur et que la pièce liée à la porte est la pièce actuelle
            if (i->piece.getPortes().elementAt(j).getCouleur() == joueur && temp == courant
                  && !i->piece.getParcourue())
            {
               temp->setParcourue(true);
               pieces.enfilePiece(i->piece.getNom(), distance + 1);
            }
         }
      }

   } while (!pieces.estVideFile() && !done); // On arrête si la file est vide (aucune solution)
                                             // ou si la fin a été trouvée

   if (done)
      return distance;
   else
      return -1; // On retourne -1 si aucune solution
}

/**
 * \fn Couleur Labyrinthe::trouveGagnant()
 *
 * \return La couleur du joueur gagnant.
 */
Couleur Labyrinthe::trouveGagnant()
{
   // On appelle la méthode solutionner() 4 fois pour obtenir le résultat de chacun des joueurs

   int nbR = solutionner(Rouge);
   int nbV = solutionner(Vert);
   int nbB = solutionner(Bleu);
   int nbJ = solutionner(Jaune);
   int min = 99999; // Plus petit nombre de déplacements

   // On vérifie si le minimum est plus petit que le nombre de déplacements du joueur
   // et qu'on a bien une solution (différent de -1)

   if (nbR < min && nbR != -1)
      min = nbR;

   if (nbV < min && nbV != -1)
      min = nbV;

   if (nbB < min && nbB != -1)
      min = nbB;

   if (nbJ < min && nbJ != -1)
      min = nbJ;

   // On retourne le plus petit résultat, sinon on retourne Aucun

   if (min == nbR)
      return Rouge;
   else if (min == nbV)
      return Vert;
   else if (min == nbB)
      return Bleu;
   else if (min == nbJ)
      return Jaune;
   else
      return Aucun;
}

/**
 * \fn Chemin Labyrinthe::cheminLabyrinthe(Couleur joueur)
 *
 * \param[in] joueur : La couleur du joueur.
 *
 * \return Le chemin pris par le joueur pour solutionner le labyrinthe.
 */
Chemin Labyrinthe::cheminLabyrinthe(Couleur joueur)
{
   // On réinitialise le chemin pour qu'aucune pièce ne soit parcourue
   dernier->piece.setParcourue(false);
   NoeudListePieces *videur = 0;
   videur = dernier->suivant;
   while (videur != dernier)
   {
      videur->piece.setParcourue(false);
      videur = videur->suivant;
   }
   videur = 0;
   delete videur;

   // On crée un chemin pour stocker les informations
   Chemin ch;

   // Début de l'algorithme (semblable à celui de solutionnerLabyrinthe())
   bool done = false;
   int distance = 0;
   string nomPiece = "";
   Piece * courant = depart;
   Piece * temp = 0;
   FilePieces pieces = FilePieces();
   pieces.enfilePiece(courant->getNom(), 0);
   courant->setParcourue(true);

   do
   {
      // On enlève la première pièce
      pieces.defilePiece(nomPiece, distance);
      courant = &trouvePiece(nomPiece)->piece;

      // Si on avait déjà ajouté une pièce ayant la même distance, on la retire
      if (ch.tailleChemin() == distance + 1)
         ch.retirePiece(distance + 1); // retirePiece() commence à l'indice 1, donc on fait +1

      // On ajoute la pièce défilée au chemin
      ch.ajoutePiece(courant->getNom(), distance);

      // Si la pièce défilée est la fin du labyrinthe, on a trouvé la sortie
      if (courant->getNom() == arrivee->getNom())
         done = true;

      // On trouve ensuite les pièces suivantes à enfiler
      // On parcourt toutes les portes de la pièce défilée pour trouver les destinations possibles
      for (int i = 1; i <= courant->getPortes().tailleListePortes(); i++)
      {
         // Destination possible
         temp = courant->getPortes().elementAt(i).getDestination();

         // On s'assure que la porte est de la même couleur que le joueur et
         // qu'elle n'a pas été parcourue.
         if (!temp->getParcourue() && courant->getPortes().elementAt(i).getCouleur() == joueur)
         {
            temp->setParcourue(true);

            // Si la porte est valide, on ajoute sa pièce à la file
            pieces.enfilePiece(temp->getNom(), distance + 1);
         }
      }

      // On parcourt toutes les pièces du labyrinthe à la recherche de portes
      // qui mène à la pièce actuelle
      for (NoeudListePieces * i = dernier->suivant; i != dernier; i = i->suivant)
      {
         // On parcourt chacune des portes de la pièce
         for (int j = 1; j <= i->piece.getPortes().tailleListePortes(); j++)
         {
            temp = i->piece.getPortes().elementAt(j).getDestination();

            // On s'assure que la destination n'est pas parcourue, que la pièce est de la bonne
            // couleur et que la pièce liée à la porte est la pièce actuelle
            if (i->piece.getPortes().elementAt(j).getCouleur() == joueur && temp == courant
                  && !i->piece.getParcourue())
            {
               temp->setParcourue(true);
               pieces.enfilePiece(i->piece.getNom(), distance + 1);
            }
         }
      }

   } while (!pieces.estVideFile() && !done); // On arrête si la file est vide (aucune solution)
                                             // ou si la fin a été trouvée

   if (done)
      return ch; // On retourne le chemin
   else
      return Chemin(); // S'il n'y avait pas de solution, on retourne un chemin vide.
}



// -------------------------------------------------------------------------------------------------
//	Modificateur privé
// -------------------------------------------------------------------------------------------------

/**
 * \fn Labyrinthe::ajoutePassage(Couleur couleur, int i1, int j1, int i2, int j2)
 * \param[in] couleur : Couleur de la porte à ajouter
 * \param[in] i1 : Coordonnée de la pièce 1
 * \param[in] j1 : Coordonnée de la pièce 1
 * \param[in] i2 : Coordonnée de la pièce 2
 * \param[in] j2 : Coordonnée de la pièce 2
 */
void Labyrinthe::ajoutePassage(Couleur couleur, int i1, int j1, int i2, int j2)
{
   NoeudListePieces *piece1, *piece2;
   string nomPiece1, nomPiece2;
   ostringstream s;

   s << i1 << "," << j1;
   nomPiece1 = s.str();

   s.str("");

   s << i2 << "," << j2;
   nomPiece2 = s.str();

   s.str("");

   piece1 = trouvePiece(nomPiece1);
   piece2 = trouvePiece(nomPiece2);

   Porte nouvellePorte(couleur, &(piece2->piece));

   piece1->piece.ajoutePorte(nouvellePorte);
}

/**
 * \fn Labyrinthe::NoeudListePieces *Labyrinthe::trouvePiece(std::string &nom) const
 *
 * \param[in] nom : Le nom de la pièce à trouver.
 *
 * \return L'adresse du noeud de la liste de pièces qui correspond à la pièce portant le nom.
 */
Labyrinthe::NoeudListePieces *Labyrinthe::trouvePiece(std::string &nom) const
{
   // Si le nom est vide, on lance une exception
   if (nom == "")
      throw std::invalid_argument("trouvePiece: Le nom passé en paramètre est vide");

   // On parcourt la liste pour vérifier si une pièce porte un même nom
   NoeudListePieces *courant = 0;
   courant = dernier->suivant;

   // Si le dernier est la pièce recherchée
   if (dernier->piece.getNom() == nom)
      return dernier;

   // On parcourt toutes les pièces à la recherche de la bonne.
   while (courant != dernier)
   {
      if (courant->piece.getNom() == nom)
         return courant;
      // On passe au suivant
      courant = courant->suivant;
   }

   // Si la pièce est introuvable, on lance une exception
   throw std::logic_error("trouvePiece: La pièce n'a pas été trouvée");
}

/**
 * \fn void Labyrinthe::placeDepart(std::string& nom)
 *
 * \param[in] nom : Le nom de la pièce de départ.
 */
void Labyrinthe::placeDepart(std::string& nom)
{
   // logic_error si aucune pièce du labyrinthe ne porte le nom spécifié.
   // Exception lancée dans la méthode trouvePiece().

   depart = &trouvePiece(nom)->piece;
}

/**
 * \fn void Labyrinthe::placeArrivee(std::string& nom)
 *
 * \param[in] nom : Le nom de la pièce d'arrivée.
 */
void Labyrinthe::placeArrivee(std::string& nom)
{
   // logic_error si aucune pièce du labyrinthe ne porte le nom spécifié.
   // Exception lancée dans la méthode trouvePiece().

   arrivee = &trouvePiece(nom)->piece;
}

/**
 * \fn void Labyrinthe::_copier(NoeudListePieces * sn)
 *
 * \param[in] sn : Un pointeur sur le début de la liste source.
 */
void Labyrinthe::_copier(NoeudListePieces * sn)
{
   try
   {
      // On copie le dernier noeud
      dernier = new NoeudListePieces(sn->piece);

      // On copie chaque noeud et on passe au suivant
      NoeudListePieces * nouveau = dernier;
      for (NoeudListePieces * temp = sn->suivant; temp != sn; temp = temp->suivant)
      {
         nouveau->suivant = new NoeudListePieces(temp->piece);
         nouveau = nouveau->suivant;
         nouveau->suivant = dernier;
      }
      nouveau->suivant = dernier;
   }
   catch (std::exception&)
   {
      // Il y a une erreur d'allocation de mémoire
      // Il faut libérer la mémoire déjà allouée
      _detruire();

      // On relance alors l'exception pour indiquer qu'une erreur est survenue
      throw;
   }
}

/**
 * \fn void Labyrinthe::_detruire()
 */
void Labyrinthe::_detruire()
{
   //Si le labyrinthe n'est pas déjà vide
   if (dernier != 0)
   {
      NoeudListePieces * courant = dernier->suivant;
      NoeudListePieces * autre = courant;
      while (courant != dernier)
      {
         courant = courant->suivant;
         delete autre;
         autre = courant;
      }
      delete dernier;
   }
}

} // namespace TP1
