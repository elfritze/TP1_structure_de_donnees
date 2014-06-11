/**
 * \file Labyrinthe.cpp
 * \brief Ce fichier contient l'implantation des m�thodes membres et priv�s de la classe Labyrinthe.
 * \author Admin, �ric Guillemette, Mathieu L'�cuyer
 * \version 0.1
 * \date juin 2014
 */

#include "Labyrinthe.h"

using namespace std;

/**
 * \namespace TP1
 *
 * Espace de nommage regroupant les d�finitions du TP1.
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
 * \return L'objet courant contenant � pr�sent les donn�es de l'objet source.
 */
const Labyrinthe& Labyrinthe::operator =(const Labyrinthe& source)
{
   if (this != &source)
   {
      // On d�truit la liste originale
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
 * \param[in] couleur : La couleur du joueur auquel le labyrinthe charg� s'applique
 * \param[in] entree : Fichier contenant la d�finition du labyrinthe
 */
void Labyrinthe::chargeLabyrinthe(Couleur couleur, std::ifstream &entree)
{
   //Voici comment un labyrinthe est mis en m�moire:
   //1- chargerLabyrinthe() appelle ajoutePieceLabyrinthe()
   //2- ajoutePieceLabyrinthe() ajoute la pi�ce si elle n'existe pas d�j�.
   //3- Si la pi�ce existe d�j�, ajoutePieceLabyrinthe() n'ajoute pas de pi�ce et
   //   laisse le programme rouler
   //4- On sort de ajoutePieceLabyrinthe() et chargerLabyrinthe() fait quelques op�rations
   //   pour ensuite appeler ajoutePassage()
   //5- ajoutePassage() ajoute les portes � la pi�ce qui a �t� cr��e ou qui existait d�j�
   //6- La pi�ce et les portes sont cr��es et on passe � une autre pi�ce

   int nbCols, nbRangs;

   entree >> nbCols >> nbRangs;
   entree.ignore(); //pour consommer le \n (le caract�re fin de ligne)

   const int MAX_LIGNE = 1000;
   char ligne[MAX_LIGNE];

   entree.getline(ligne, MAX_LIGNE);
   entree.getline(ligne, MAX_LIGNE);

   std::ostringstream s; //Une cha�ne pour �crire dedans,
                         //cette cha�ne servira pour nommer les pi�ces du labyrinthe

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
 * \param[in] p : Un objet pi�ce � ajouter au labyrinthe.
 */
void Labyrinthe::ajoutePieceLabyrinthe(Piece &p)
{
   if (dernier == 0)
   {
      //Dans le cas o� la liste est vide
      dernier = new NoeudListePieces(p);
      dernier->suivant = dernier;
   }
   else
   {
      //On parcourt la liste pour v�rifier si une pi�ce porte un m�me nom
      NoeudListePieces *courant = 0;
      courant = dernier->suivant;
      while (courant != dernier)
      {
         if (courant->piece.getNom() == p.getNom())
            return;
         courant = courant->suivant;
      }

      //On ajoute la pi�ce � la fin.
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
 * \return Un entier repr�sentant le nombre de d�placements requis pour que le joueur traverse
 *         le labyrinthe.
 */
int Labyrinthe::solutionner(Couleur joueur)
{
   // Si un labyrinthe ne peut pas �tre solutionn� par le joueur, il faut retourner -1.
   // Dans ce cas, il ne s'agit pas d'un appel anormal de la m�thode.

   // On r�initialise le chemin pour qu'aucune pi�ce ne soit parcourue
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

   // D�but de l'algorithme de solution
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
      // On enl�ve la premi�re pi�ce
      pieces.defilePiece(nomPiece, distance);
      courant = &trouvePiece(nomPiece)->piece;

      // Si la pi�ce d�fil�e est la fin du labyrinthe, on a trouv� la sortie
      if (courant->getNom() == arrivee->getNom())
         done = true;

      // On parcourt toutes les portes de la pi�ce d�fil�e pour trouver les destinations possibles
      for (int i = 1; i <= courant->getPortes().tailleListePortes(); i++)
      {
         // Destination possible
         temp = courant->getPortes().elementAt(i).getDestination();

         // On s'assure que la porte est de la m�me couleur que le joueur et
         // qu'elle n'a pas �t� parcourue.
         if (!temp->getParcourue() && courant->getPortes().elementAt(i).getCouleur() == joueur)
         {
            temp->setParcourue(true);

            // Si la porte est valide, on ajoute sa pi�ce � la file
            pieces.enfilePiece(temp->getNom(), distance + 1);
         }
      }

      // On parcourt toutes les pi�ces du labyrinthe � la recherche de portes
      // qui m�ne � la pi�ce actuelle
      for (NoeudListePieces * i = dernier->suivant; i != dernier; i = i->suivant)
      {
         // On parcourt chacune des portes de la pi�ce
         for (int j = 1; j <= i->piece.getPortes().tailleListePortes(); j++)
         {
            temp = i->piece.getPortes().elementAt(j).getDestination();

            // On s'assure que la destination n'est pas parcourue, que la pi�ce est de la bonne
            // couleur et que la pi�ce li�e � la porte est la pi�ce actuelle
            if (i->piece.getPortes().elementAt(j).getCouleur() == joueur && temp == courant
                  && !i->piece.getParcourue())
            {
               temp->setParcourue(true);
               pieces.enfilePiece(i->piece.getNom(), distance + 1);
            }
         }
      }

   } while (!pieces.estVideFile() && !done); // On arr�te si la file est vide (aucune solution)
                                             // ou si la fin a �t� trouv�e

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
   // On appelle la m�thode solutionner() 4 fois pour obtenir le r�sultat de chacun des joueurs

   int nbR = solutionner(Rouge);
   int nbV = solutionner(Vert);
   int nbB = solutionner(Bleu);
   int nbJ = solutionner(Jaune);
   int min = 99999; // Plus petit nombre de d�placements

   // On v�rifie si le minimum est plus petit que le nombre de d�placements du joueur
   // et qu'on a bien une solution (diff�rent de -1)

   if (nbR < min && nbR != -1)
      min = nbR;

   if (nbV < min && nbV != -1)
      min = nbV;

   if (nbB < min && nbB != -1)
      min = nbB;

   if (nbJ < min && nbJ != -1)
      min = nbJ;

   // On retourne le plus petit r�sultat, sinon on retourne Aucun

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
   // On r�initialise le chemin pour qu'aucune pi�ce ne soit parcourue
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

   // On cr�e un chemin pour stocker les informations
   Chemin ch;

   // D�but de l'algorithme (semblable � celui de solutionnerLabyrinthe())
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
      // On enl�ve la premi�re pi�ce
      pieces.defilePiece(nomPiece, distance);
      courant = &trouvePiece(nomPiece)->piece;

      // Si on avait d�j� ajout� une pi�ce ayant la m�me distance, on la retire
      if (ch.tailleChemin() == distance + 1)
         ch.retirePiece(distance + 1); // retirePiece() commence � l'indice 1, donc on fait +1

      // On ajoute la pi�ce d�fil�e au chemin
      ch.ajoutePiece(courant->getNom(), distance);

      // Si la pi�ce d�fil�e est la fin du labyrinthe, on a trouv� la sortie
      if (courant->getNom() == arrivee->getNom())
         done = true;

      // On trouve ensuite les pi�ces suivantes � enfiler
      // On parcourt toutes les portes de la pi�ce d�fil�e pour trouver les destinations possibles
      for (int i = 1; i <= courant->getPortes().tailleListePortes(); i++)
      {
         // Destination possible
         temp = courant->getPortes().elementAt(i).getDestination();

         // On s'assure que la porte est de la m�me couleur que le joueur et
         // qu'elle n'a pas �t� parcourue.
         if (!temp->getParcourue() && courant->getPortes().elementAt(i).getCouleur() == joueur)
         {
            temp->setParcourue(true);

            // Si la porte est valide, on ajoute sa pi�ce � la file
            pieces.enfilePiece(temp->getNom(), distance + 1);
         }
      }

      // On parcourt toutes les pi�ces du labyrinthe � la recherche de portes
      // qui m�ne � la pi�ce actuelle
      for (NoeudListePieces * i = dernier->suivant; i != dernier; i = i->suivant)
      {
         // On parcourt chacune des portes de la pi�ce
         for (int j = 1; j <= i->piece.getPortes().tailleListePortes(); j++)
         {
            temp = i->piece.getPortes().elementAt(j).getDestination();

            // On s'assure que la destination n'est pas parcourue, que la pi�ce est de la bonne
            // couleur et que la pi�ce li�e � la porte est la pi�ce actuelle
            if (i->piece.getPortes().elementAt(j).getCouleur() == joueur && temp == courant
                  && !i->piece.getParcourue())
            {
               temp->setParcourue(true);
               pieces.enfilePiece(i->piece.getNom(), distance + 1);
            }
         }
      }

   } while (!pieces.estVideFile() && !done); // On arr�te si la file est vide (aucune solution)
                                             // ou si la fin a �t� trouv�e

   if (done)
      return ch; // On retourne le chemin
   else
      return Chemin(); // S'il n'y avait pas de solution, on retourne un chemin vide.
}



// -------------------------------------------------------------------------------------------------
//	Modificateur priv�
// -------------------------------------------------------------------------------------------------

/**
 * \fn Labyrinthe::ajoutePassage(Couleur couleur, int i1, int j1, int i2, int j2)
 * \param[in] couleur : Couleur de la porte � ajouter
 * \param[in] i1 : Coordonn�e de la pi�ce 1
 * \param[in] j1 : Coordonn�e de la pi�ce 1
 * \param[in] i2 : Coordonn�e de la pi�ce 2
 * \param[in] j2 : Coordonn�e de la pi�ce 2
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
 * \param[in] nom : Le nom de la pi�ce � trouver.
 *
 * \return L'adresse du noeud de la liste de pi�ces qui correspond � la pi�ce portant le nom.
 */
Labyrinthe::NoeudListePieces *Labyrinthe::trouvePiece(std::string &nom) const
{
   // Si le nom est vide, on lance une exception
   if (nom == "")
      throw std::invalid_argument("trouvePiece: Le nom pass� en param�tre est vide");

   // On parcourt la liste pour v�rifier si une pi�ce porte un m�me nom
   NoeudListePieces *courant = 0;
   courant = dernier->suivant;

   // Si le dernier est la pi�ce recherch�e
   if (dernier->piece.getNom() == nom)
      return dernier;

   // On parcourt toutes les pi�ces � la recherche de la bonne.
   while (courant != dernier)
   {
      if (courant->piece.getNom() == nom)
         return courant;
      // On passe au suivant
      courant = courant->suivant;
   }

   // Si la pi�ce est introuvable, on lance une exception
   throw std::logic_error("trouvePiece: La pi�ce n'a pas �t� trouv�e");
}

/**
 * \fn void Labyrinthe::placeDepart(std::string& nom)
 *
 * \param[in] nom : Le nom de la pi�ce de d�part.
 */
void Labyrinthe::placeDepart(std::string& nom)
{
   // logic_error si aucune pi�ce du labyrinthe ne porte le nom sp�cifi�.
   // Exception lanc�e dans la m�thode trouvePiece().

   depart = &trouvePiece(nom)->piece;
}

/**
 * \fn void Labyrinthe::placeArrivee(std::string& nom)
 *
 * \param[in] nom : Le nom de la pi�ce d'arriv�e.
 */
void Labyrinthe::placeArrivee(std::string& nom)
{
   // logic_error si aucune pi�ce du labyrinthe ne porte le nom sp�cifi�.
   // Exception lanc�e dans la m�thode trouvePiece().

   arrivee = &trouvePiece(nom)->piece;
}

/**
 * \fn void Labyrinthe::_copier(NoeudListePieces * sn)
 *
 * \param[in] sn : Un pointeur sur le d�but de la liste source.
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
      // Il y a une erreur d'allocation de m�moire
      // Il faut lib�rer la m�moire d�j� allou�e
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
   //Si le labyrinthe n'est pas d�j� vide
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
