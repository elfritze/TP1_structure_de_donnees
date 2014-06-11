/**
 * \file Principal.cpp
 * \brief Ce fichier contient un main pour tester le labyrinthe.
 * \author Admin, �ric Guillemette, Mathieu L'�cuyer
 * \version 0.1
 * \date mai 2014
 */

//Fichiers � compl�ter pour faire d'autres tests.

#include "Labyrinthe.h"

using namespace std;
using namespace TP1;

/**
 * \fn int main()
 * \brief Fonction principale pour tester le labyrinthe.
 *
 * \return 0 - Arr�t normal du programme.
 */
int main()
{
	try
	{
		Labyrinthe lab;

		ifstream entree("FichiersLabyrinthe/Lab2x3/rouge.txt");
		//Cette d�claration �quivaut � :
		//ifstream entree;
		//entree.open("nomFichier", ios::in);
		//On doit ��valuer le stream�, apr�s l�appel � la fonction open.
		//Si tout c�est bien pass�, le r�sultat de cette �valuation sera true,et il
		//sera false en cas de probl�me.

		if (!entree)
		{
			cout << "Fichier rouge introuvable.\n";
			return 1;
		}

		lab.chargeLabyrinthe(Rouge, entree);
		cout << "\nLabyrinthe rouge charg�.\n";
		entree.close(); //on ferme le fichier

		entree.open("FichiersLabyrinthe/Lab2x3/vert.txt", ios::in);
		if (!entree)
		{
			cout << "Fichier vert introuvable.\n";
			return 1;
		}

		lab.chargeLabyrinthe(Vert, entree);
		cout << "\nLabyrinthe vert charg�.\n";
		entree.close();

		entree.open("FichiersLabyrinthe/Lab2x3/bleu.txt", ios::in);
		if (!entree)
		{
			cout << "Fichier bleu introuvable.\n";
			return 1;
		}

		lab.chargeLabyrinthe(Bleu, entree);
		cout << "\nLabyrinthe bleu charg�.\n";
		entree.close();

		entree.open("FichiersLabyrinthe/Lab2x3/jaune.txt", ios::in);
		if (!entree)
		{
			cout << "Fichier jaune introuvable.\n\n";
			return 1;
		}

		lab.chargeLabyrinthe(Jaune, entree);
		cout << "\nLabyrinthe jaune charg�.\n";
		entree.close();

		int nbR = lab.solutionner(Rouge);
		int nbV = lab.solutionner(Vert);
		int nbB = lab.solutionner(Bleu);
		int nbJ = lab.solutionner(Jaune);

		nbR == -1 ? cout << "\nLe joueur rouge ne peut solutionner le labyrinthe" : cout << "\nLe joueur rouge peut solutionner le labyrinthe en " << nbR << " d�placements.\n";
		nbV == -1 ? cout << "\nLe joueur vert ne peut solutionner le labyrinthe" : cout << "\nLe joueur vert peut solutionner le labyrinthe en " << nbV << " d�placements.\n";
		nbB == -1 ? cout << "\nLe joueur bleu ne peut solutionner le labyrinthe" : cout << "\nLe joueur bleu peut solutionner le labyrinthe en " << nbB << " d�placements.\n";
		nbJ == -1 ? cout << "\nLe joueur jaune ne peut solutionner le labyrinthe" : cout << "\nLe joueur jaune peut solutionner le labyrinthe en " << nbJ << " d�placements.\n";

		Couleur LeGagnant = lab.trouveGagnant();
		switch (LeGagnant)
		{
		case 0:
			cout << endl << "\nLe joueur gagnant : Rouge" << endl << endl; break;
		case 1:
			cout << endl << "\nLe joueur gagnant : Vert" << endl << endl; break;
		case 2:
			cout << endl << "\nLe joueur gagnant : Bleu" << endl << endl; break;
		case 3:
			cout << endl << "\nLe joueur gagnant : Jaune" << endl << endl; break;
		default:
			cout << endl << "\nAucun joueur gagnant !" << endl << endl; break;
		}

		//Simulation de l'appel de la m�thode cheminLabyrinthe() puis affichage du chemin retourn�.
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
		//string str;
		//getline(cin, str);

	} catch (exception & e)
	{
		cerr << e.what() << endl;
	}

	return 0;
}
