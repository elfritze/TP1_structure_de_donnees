/**
 * \file Principal.cpp
 * \brief Ce fichier contient un main pour tester le labyrinthe.
 * \author Admin, Éric Guillemette, Mathieu L'Écuyer
 * \version 0.1
 * \date mai 2014
 */

//Fichiers à compléter pour faire d'autres tests.

#include "Labyrinthe.h"

using namespace std;
using namespace TP1;

/**
 * \fn int main()
 * \brief Fonction principale pour tester le labyrinthe.
 *
 * \return 0 - Arrêt normal du programme.
 */
int main()
{
	try
	{
		Labyrinthe lab;

		ifstream entree("FichiersLabyrinthe/Lab2x3/Rouge.txt");
		//Cette déclaration équivaut à :
		//ifstream entree;
		//entree.open("nomFichier", ios::in);
		//On doit «évaluer le stream», après l’appel à la fonction open.
		//Si tout c’est bien passé, le résultat de cette évaluation sera true,et il
		//sera false en cas de problème.

		if (!entree)
		{
			cerr << "Fichier Rouge introuvable.\n";
			return 1;
		}

		lab.chargeLabyrinthe(Rouge, entree);
		cout << "Labyrinthe Rouge chargé.\n" << endl;
		entree.close(); //on ferme le fichier

		entree.open("FichiersLabyrinthe/Lab2x3/Vert.txt", ios::in);
		if (!entree)
		{
			cerr << "Fichier Vert introuvable.\n";
			return 1;
		}

		lab.chargeLabyrinthe(Vert, entree);
		cout << "Labyrinthe Vert chargé.\n" << endl;
		entree.close();

		entree.open("FichiersLabyrinthe/Lab2x3/Bleu.txt", ios::in);
		if (!entree)
		{
			cerr << "Fichier Bleu introuvable.\n";
			return 1;
		}

		lab.chargeLabyrinthe(Bleu, entree);
		cout << "Labyrinthe Bleu chargé.\n" << endl;
		entree.close();

		entree.open("FichiersLabyrinthe/Lab2x3/Jaune.txt", ios::in);
		if (!entree)
		{
			cerr << "Fichier Jaune introuvable.\n";
			return 1;
		}

		lab.chargeLabyrinthe(Jaune, entree);
		cout << "Labyrinthe Jaune chargé.\n" << endl << endl;
		entree.close();


		// Test pour la méthode solutionner() de la classe Labyrinthe
		int nbR = lab.solutionner(Rouge);
		int nbV = lab.solutionner(Vert);
		int nbB = lab.solutionner(Bleu);
		int nbJ = lab.solutionner(Jaune);

		nbR == -1 ? cout << "Le joueur Rouge ne peut solutionner le labyrinthe.\n" << endl :
		            cout << "Le joueur Rouge peut solutionner le labyrinthe en "
		            << nbR << " déplacements.\n" << endl;

		nbV == -1 ? cout << "Le joueur Vert ne peut solutionner le labyrinthe.\n" << endl :
		            cout << "Le joueur Vert peut solutionner le labyrinthe en "
		            << nbV << " déplacements.\n" << endl;

		nbB == -1 ? cout << "Le joueur Bleu ne peut solutionner le labyrinthe.\n" << endl :
		            cout << "Le joueur Bleu peut solutionner le labyrinthe en "
		            << nbB << " déplacements.\n" << endl;

		nbJ == -1 ? cout << "Le joueur Jaune ne peut solutionner le labyrinthe.\n" << endl :
		            cout << "Le joueur Jaune peut solutionner le labyrinthe en "
		            << nbJ << " déplacements.\n" << endl;


		// Test de la méthode trouveGagnant() de la classe Labyrinthe
		Couleur LeGagnant = lab.trouveGagnant();
		switch (LeGagnant)
		{
		case 0:
			cout << endl << "Le joueur gagnant: Rouge\n" << endl << endl; break;
		case 1:
			cout << endl << "Le joueur gagnant: Vert\n" << endl << endl; break;
		case 2:
			cout << endl << "Le joueur gagnant: Bleu\n" << endl << endl; break;
		case 3:
			cout << endl << "Le joueur gagnant: Jaune\n" << endl << endl; break;
		default:
			cout << endl << "Le joueur gagnant: aucun!!\n" << endl << endl; break;
		}


		//Simulation de l'appel de la méthode cheminLabyrinthe() puis affichage du chemin retourné.
		TP1::Chemin nomduchemin;
		std::cout << "Chemin Rouge : " << std::endl;
		nomduchemin = lab.cheminLabyrinthe(TP1::Rouge);
		nomduchemin.afficheChemin();

		std::cout << std::endl << "Chemin Vert : " << std::endl;
		nomduchemin = lab.cheminLabyrinthe(TP1::Vert);
		nomduchemin.afficheChemin();

		std::cout << std::endl << "Chemin Bleu : " << std::endl;
		nomduchemin = lab.cheminLabyrinthe(TP1::Bleu);
		nomduchemin.afficheChemin();

		std::cout << std::endl << "Chemin Jaune : " << std::endl;
		nomduchemin = lab.cheminLabyrinthe(TP1::Jaune);
		nomduchemin.afficheChemin();


	} catch (exception & e)
	{
		cerr << e.what() << endl;
	}

	return 0;
}
