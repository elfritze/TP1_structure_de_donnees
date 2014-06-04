/**
 * \file Labyrinthe.cpp
 * \brief Le code des méthodes membres et privés de la classe Labyrinthe.
 * \author Admin, Étudiant 1, étudiant 2
 * \version 0.1
 * \date juin 2014
 * 
 */

//Fichiers à compléter par les autres méthodes de la classe Labyrinthes demandées



#include "Labyrinthe.h"

namespace TP1
{
 using namespace std;


	//Constructeur par défaut
	Labyrinthe::Labyrinthe() : depart(0),arrivee(0),dernier(0){}

	//Destructeur
	Labyrinthe:: ~Labyrinthe()
	{
		_detruire();
	}

	//constructeur de copie
	Labyrinthe::Labyrinthe(const Labyrinthe& l)
	{
		if (l.dernier == 0)
			dernier = 0;
		else
			_copier(l.dernier);
	}

	//Surcharge de l'opérateur =
	const Labyrinthe& Labyrinthe::operator =(const Labyrinthe& source)
	{
		_detruire();
		if (source.dernier == 0)
			dernier = 0;
		else
			_copier(source.dernier);

		return (*this);
	}

// -------------------------------------------------------------------------------------------------
//	Chargement
// -------------------------------------------------------------------------------------------------

/**
 * \fn	void Labyrinthe::chargeLabyrinthe(Couleur couleur, std::ifstream &entree)
 * \param[in]	couleur, la couleur du jouer auquel le labyrinthe chargé s'applique
 * \param[in]	entree, fichier contenant la définition du labyrinthe
 */
void Labyrinthe::chargeLabyrinthe(Couleur couleur, std::ifstream &entree)
{
	int nbCols, nbRangs;

	entree >> nbCols >> nbRangs;
	entree.ignore(); //pour consommer le \n (le caractère fin de ligne)

	const int MAX_LIGNE = 1000;
	char ligne[MAX_LIGNE];

	entree.getline(ligne, MAX_LIGNE);
	entree.getline(ligne, MAX_LIGNE);

	std::ostringstream s; //Une chaîne pour écrire dedans, cette chaîne servira pour nommer les pièces du labyrinthe

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
		if (ligne[i * 4 + 1] == 'F' || ligne[i * 4 + 1] == 'f' || ligne[i * 4
				+ 1] == 'A' || ligne[i * 4 + 1] == 'a')
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
				if (j < nbRangs - 1 && (ligne[i * 4 + 1] == 'D' || ligne[i * 4
						+ 1] == 'd'))
				{
					std::string nom;
					s << i << "," << j + 1;
					nom = s.str();
					s.str("");
					placeDepart(nom);
				}
				if (j < nbRangs - 1 && (ligne[i * 4 + 1] == 'F' || ligne[i * 4
						+ 1] == 'f' || ligne[i * 4 + 1] == 'A' || ligne[i * 4
						+ 1] == 'a'))
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
				if (j < nbRangs - 1 && (ligne[i * 4 + 3] == 'D' || ligne[i * 4
						+ 3] == 'd'))
				{
					std::string nom;
					s << i << "," << j + 1;
					nom = s.str();
					s.str("");
					placeDepart(nom);
				}
				if (j < nbRangs - 1 && (ligne[i * 4 + 3] == 'F' || ligne[i * 4
						+ 3] == 'f' || ligne[i * 4 + 3] == 'A' || ligne[i * 4
						+ 3] == 'a'))
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
//	Modificateur privé
// -------------------------------------------------------------------------------------------------

/**
 * \fn	Labyrinthe::ajoutePassage(Couleur couleur, int i1, int j1, int i2, int j2)
 * \param[in]	Couleur couleur Couleur de la porte à ajouter
 * \param[in]	int i1
 * \param[in]	int j1
 * \param[in]	int i2
 * \param[in]	int j2
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

	
	//Cette fonction doit ajouter la pièce p à un labyrinthe. Dans le cas où
	//une pièce du labyrinthe porte déjà un même nom, la méthode ne doit
	//rien faire (faire un simple return, sans générer d'exception).
	void Labyrinthe::ajoutePieceLabyrinthe(Piece &p)
	{
		
		if(dernier ==0)
		{
			//Dans le cas ou la liste est vide
			dernier = new NoeudListePieces(p);
			dernier->suivant = dernier;
		}
		else{

			//On parcour la liste pour vérifier si une piece porte un même nom
			NoeudListePieces *courant = 0;
			courant = dernier;
			while(courant!=dernier)
			{
				if(courant->piece.getNom() == p.getNom())
					return;
				courant=courant->suivant;
			}

			//On ajoute la piece à la fin.
			NoeudListePieces *nouveau = new NoeudListePieces(p);
			nouveau->suivant=dernier->suivant;
			dernier->suivant = nouveau;
			dernier = nouveau;
		}
		return ;
	}

	
	//Méthode qui solutionnera le labyrinthe.
	//Retourne le nombre de dépalcements requis pour qu'un joueur traverse le labyrinthe.
	int Labyrinthe::solutionner(Couleur joueur)
	{
		//On reset le chemin pour qu'aucune piece ne soit parcourue
		dernier->piece.setParcourue(false);
		NoeudListePieces *videur = 0;
		videur = dernier->suivant;
		while(videur!=dernier)
		{
			videur->piece.setParcourue(false);
			videur=videur->suivant;
		}
		videur = 0;
		delete videur;
		
		//Début de l'algoritme de solution
		bool done = false;
		int distance = 0;
		string nomPiece = "";
		Piece * courant = depart;
		Piece * temp = 0;
		FilePieces pieces = FilePieces();
		pieces.enfilePiece(courant->getNom(),0);
		courant->setParcourue(true);
		do{
			//On enlever la premiere piece
			pieces.defilePiece(nomPiece,distance);
			courant =  &trouvePiece(nomPiece)->piece;

			//Si la piece dépilée est la fin du labyrinthe on a trouvé la sortie
			if(courant->getNom() == arrivee->getNom())
				done = true;

			//On parcoure toutes les portes de la pièce défilée pour trouver les destinations possibles
			for (int i = 1;i <= courant->getPortes().tailleListePortes(); i ++){

				//Destination possible
				temp  = courant->getPortes().elementAt(i).getDestination();

				//On s'assure que la porte soit de la même couleur que le joueur et qu'elle n'a pas été parcourue.
				if(!temp->getParcourue() && courant->getPortes().elementAt(i).getCouleur()==joueur)
				{
					temp->setParcourue(true);

					//Si la porte est valide on ajoute sa piece à la file
					pieces.enfilePiece(temp->getNom(),distance+1);
				}

			}

			// On parcoure toutes les pièces du labyrinthe à la recherche de portes qui mène à la pièce actuelle
			for (NoeudListePieces * i = dernier->suivant; i != dernier; i = i->suivant )
			{
				//On parcoure chacune des portes de la piece
				for (int j = 1;j <= i->piece.getPortes().tailleListePortes(); j ++){

					temp  = i->piece.getPortes().elementAt(j).getDestination();

					//On s'assure que la destionation n'est pas parcourue, que la piece est de la bonne couleur et que la piece liée à la porte est la pièce actuelle
					if(i->piece.getPortes().elementAt(j).getCouleur()==joueur && temp==courant && !i->piece.getParcourue())
					{
						temp->setParcourue(true);
						pieces.enfilePiece(i->piece.getNom(),distance+1);
					}

				}
			}
			
		}while(!pieces.estVideFile() && !done); // On arrête si la file est vide (aucune solution) ou si la fin a été trouvée

		if(done)
			return distance;
		else
			return 0; // On retourne 0 si aucune solution
	}

	
	//Méthode qui solutionnera le labyrinthe.
	//Retourne le chemin pris par le joueur.
	Chemin Labyrinthe::cheminLabyrinthe(Couleur joueur)
	{
		return Chemin();
	}

	
	//Appelle 4 fois la méthode solutionner pour trouver le joueur gagnant.
	Couleur Labyrinthe::trouveGagnant()
	{
		//On appelle la méthode solutionner 4 fois pour obtenir les scores de chacun des joueurs
		int nbR = solutionner(Rouge);
		int nbV = solutionner(Vert);
		int nbB = solutionner(Bleu);
		int nbJ = solutionner(Jaune);
		int min = 99999; // Plus petit nombre de déplacements

		// Chaque ligne vérifie si le minimum est plus petit que le nombre de déplacements du joueur et qu'on a bien une solution (différent de 0)
		nbR < min && nbR != 0 ? min= nbR : min = min;
		nbV < min && nbV != 0 ? min= nbV : min = min;
		nbB < min && nbB != 0 ? min= nbB : min = min;
		nbJ < min && nbJ != 0 ? min= nbJ : min = min;

		//On retourne le plus petit score, sinon on retourne une couleur vide
		if(min == nbR)
			return Rouge;
		else if(min==nbV)
			return Vert;
		else if(min==nbB)
			return Bleu;
		else if(min==nbJ)
			return Jaune;
		else
			return Couleur();
	}

	
	//Méthode privée. Retourne l'adresse du noeud de la liste de pièces contenue dans le labyrinthe lab
	//qui correspond à la pièce portant le nom nom, la méthode doit lancer une exception invalid_argument si le nom de
	//la pièce est vide. La méthode doit lancer également une exception logic_error si la pièce est introuvable.
	//Remarquez qu'il faut retourner l'adresse du noeud de la liste doublement chaînée de pièces,
	//et non l'adresse de la pièce.
	Labyrinthe::NoeudListePieces *Labyrinthe::trouvePiece(std::string &nom) const 
	{
		//Si le nom est vide on lance une exception
		if (nom == "")
			throw std::invalid_argument("trouvePiece: Le nom passé en paramètre est vide");

		//On parcour la liste pour vérifier si une piece porte un même nom
		NoeudListePieces *courant = 0;
		courant = dernier->suivant;

		//Si le dernier est la piece recherchée
		if(dernier->piece.getNom() == nom)
			return dernier;

		//On parcoure toutes les pièces à la recherche de la bonne.
		while(courant!=dernier)
		{
			if(courant->piece.getNom() == nom)
				return courant;
			// On passe au suivant
			courant=courant->suivant;
		}

		//Si la piece est introuvable on lance une exception
		throw std::logic_error("trouvePiece: La pièce n'a pas été trouvée");
	}

	
	//Méthode privée, elle sert pour charger un labyrinthe. Ajuste le pointeur depart d'un labyrinthe
	//pour qu'il contienne l'adresse de la pièce correspondant au nom spécifié par nom. Lancer une
	//exception logic_error si aucune pièce du labyrinthe ne porte le nom nom.
	void Labyrinthe::placeDepart(std::string& nom)
	{
		depart = &trouvePiece(nom)->piece;
	}

	
	//Méthode privée, elle sert pour charger un labyrinthe. Ajuste le pointeur arrivé d'un labyrinthe
	//pour qu'il contienne l'adresse de la pièce correspondant au nom spécifié par nom. Lancer une
	//exception logic_error si aucune pièce du labyrinthe ne porte le nom nom.
	void Labyrinthe::placeArrivee(std::string& nom)
	{
		arrivee = &trouvePiece(nom)->piece;
	}

	//Méthode appelée pour copier un labyrinthe (liste circulaire)
	void Labyrinthe:: _copier(NoeudListePieces * sn)
	{
		try{
			dernier = new NoeudListePieces(sn->piece);
			NoeudListePieces * nouveau = dernier;
			//On copie chaque noeud et on passe au suivant
			for (NoeudListePieces * temp = sn->suivant; temp != sn; temp = temp->suivant )
			{
				nouveau->suivant = new NoeudListePieces(temp->piece);
				nouveau = nouveau->suivant;
				nouveau->suivant = dernier;
			}
			nouveau->suivant = dernier;
		}
		catch(std::exception&)
		{
			_detruire();
			throw;
		}
	}

	//Méthode appelée pour supprimer un labyrinthe (liste circulaire)
	void Labyrinthe:: _detruire()
	{
		//Si le labyrinthe n'est pas déjà vide
		if(dernier !=0)
		{
			NoeudListePieces * courant = dernier->suivant;
			NoeudListePieces * autre = courant;
			while(courant!=dernier)
			{
				courant=courant->suivant;
				delete autre;
				autre=courant;
			}
			delete dernier;
		}
	}

}


//fin du namespace
