# include  <stdio.h>
# include  <stdlib.h>
# include  <conio.h>
# include  <math.h>

# define  NBNOTESMAX  30 

void  Echangeur(float* a, float* b) {
	float temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}
//#################################################################################################
int  main() {
	float note[NBNOTESMAX];
	int compteur = 0;
	float saisie;
	int absences = 0;
	int notesValides = 0;
	float somme = 0;
	float minimum;
	float maximum;
//#################################################################################################
	for(int compteur = 0; compteur < NBNOTESMAX; compteur++) { note[compteur] = -2; }

	for (int compteur = 0; compteur < NBNOTESMAX; compteur++) {
		printf("\nEntrez la note numero %d:\n", compteur + 1);
		scanf_s("%f", &saisie);
		if (saisie < 0 || saisie >20) { 
			char rep;
			_cputs("Elève absent ? ou voulez-vous arrêter la saisie des notes ? (A)/(O)/(N) \n ");
			rep = _getch();
			if (rep == 'A') {
				absences += 1;
				note[compteur] = -1;
			}
			else if (rep == 'O') {
				compteur = 31;
			}
			else if (rep == 'N') {
				compteur -= 1;
			}
			else {
				compteur -= 1;
			}
		}
		else {
			notesValides += 1;
			somme += saisie;
			note[compteur] = saisie;
		}
		printf("%.2f", note[compteur]);
	}
//#################################################################################################
	compteur = 0;
	float temp;
	minimum = note[0];
	maximum = note[0];
	for(compteur = 1; compteur < NBNOTESMAX; compteur++) {
		if (note[compteur] >= 0) {
			temp = note[compteur];
			if (temp > maximum) {
				maximum = temp;
			}
			else if(temp < minimum) {
				minimum = temp;
			}
		}
	}
	float moyenne = 0;
	moyenne = (somme / notesValides);
	printf(" \n Le nombre de notes valides est: %d ", notesValides);
	printf(" \n Le nombre d'abscences est: %d  ", absences);
	printf(" \n La moyenne est de: %.2f ", moyenne);
	printf(" \n Le plus petit nombre est: %.2f ", minimum);
	printf(" \n Le plus grand nombre est: %.2f ", maximum);
//#################################################################################################	

	float EcartMoyen = 0;
	for(compteur = 0; compteur < NBNOTESMAX; compteur++) {
		if (note[compteur] > 0) {
			EcartMoyen = (float)pow((note[compteur]- moyenne), 2);
		}
	}
	float EcartType = (float)sqrt(EcartMoyen / notesValides);
	printf(" \n L'Ecart Type est de: %.2f ", EcartType);
	
//#################################################################################################
	printf(" \n Numero de la Note ");
	int Affichage = 0;
	for(compteur = 0; compteur < NBNOTESMAX; compteur++) {
		if (note[compteur] > 0) {
			Affichage += 1;
			printf(" \n %d ", Affichage);
			printf(" \t\t   %.2f \n ", note[compteur]);
		}
	}

//#################################################################################################
	int TbIndex[30];
	for(int compteur = 0; compteur < NBNOTESMAX; compteur++) { TbIndex[compteur] = compteur; }
	for(int CompteurTri = 0; CompteurTri < NBNOTESMAX; CompteurTri++) {
		if(compteur = 0, compteur < NBNOTESMAX - CompteurTri, compteur++) {
			if (note[compteur] < note[compteur + 1]) {
				Echangeur(&note[compteur], &note[compteur + 1]);
				Echangeur(&(float)TbIndex[compteur], &(float)TbIndex[compteur + 1]);
			}
		}
	}
	printf(" \n Rang numero de la Note ");
	Affichage = 0;
	if(compteur = 0, compteur < NBNOTESMAX, compteur++) {
		if (note[compteur] > 0) {
			Affichage += 1;
			printf(" \n  % d ", Affichage);
			printf(" \t\t %d ", TbIndex[compteur] + 1);
			printf(" \t\t  %.2f \n ", note[compteur]);
		}
	}

	system(" break ");
	return (EXIT_SUCCESS);
}