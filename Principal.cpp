/**
 * \file Principal.cpp
 * \brief Ce fichier contient un main pour tester le labyrinthe.
 * \author Admin, �tudiant 1, �tudiant 2
 * \version 0.1
 * \date mai 2014
 * 
 */

//Fichiers � compl�ter pour faire d'autres tests.

#include "Labyrinthe.h"

using namespace std;
using namespace TP1;

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

		cout << "\nLe joueur rouge peut solutionner le labyrinthe en "
				<< lab.solutionner(Rouge) << " d�placements.\n";
		cout << "\nLe joueur vert peut solutionner le labyrinthe en "
				<< lab.solutionner(Vert) << " d�placements.\n";
		cout << "\nLe joueur bleu peut solutionner le labyrinthe en "
				<< lab.solutionner(Bleu) << " d�placements.\n";
		cout << "\nLe joueur jaune peut solutionner le labyrinthe en "
				<< lab.solutionner(Jaune) << " d�placements.\n";

		Couleur LeGagnant = lab.trouveGagnant();
		switch (LeGagnant)
		{
		case 0:
			cout << endl << "Le joureur gagnant: Rouge" << endl << endl; break;
		case 1:
			cout << endl << "Le joureur gagnant: Vert" << endl << endl; break;
		case 2:
			cout << endl << "Le joureur gagnant: Bleu" << endl << endl; break;
		case 3:
			cout << endl << "Le joureur gagnant: Jaune" << endl << endl; break;
		default:
			cout << endl << "Le joureur gagnant: aucun!!" << endl << endl; break;
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

	} catch (exception & e)
	{
		cerr << e.what() << endl;
	}

	return 0;
}
