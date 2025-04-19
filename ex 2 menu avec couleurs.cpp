#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define max_chaine 56
#define nmax 50

typedef enum {C,M,D} etat_civil;



typedef struct {
	char matricule[max_chaine] ;
	char nom[max_chaine] ;
    etat_civil etat;
    float salaire;
}employe;

typedef struct {
	employe t[nmax];
    int nb;
}service;

void ajout(employe E,service *s);
void afficher(service s);
int recherche_employe(service s, char mat[]);
void saisie_emp(employe *E);

void ajout(employe E,service *s)
{if(s->nb<nmax){
	s->t[s->nb]=E;
	(s->nb)++;
}else{printf(RED "vous avez depasse la taille max" RESET);
}}

void afficher(service s)
{for(int i=0;i<s.nb;i++){
	printf("martricule=\t %s \n nom=\t %s \n",s.t[i].matricule,s.t[i].nom);
	switch(s.t[i].etat){
		case M : printf("Etat:\t Marie \n");break;
		case C : printf("Etat:\t Celibataire \n");break;
		case D : printf("Etat:\t Divorce \n");break;
	}
	printf("salaire:\t %2f",s.t[i].salaire);
}
}

int recherche_employe(service s, char mat[])
{int i=0;
while ((i<s.nb)&&(strcmp(mat,s.t[i].matricule)!=0)){
	i++;
}
return(i!=s.nb);
}

void saisie_emp(employe *E)
{printf(CYAN "donnez la matricule" RESET);
scanf("%s",E->matricule);
printf(CYAN "donner le nom" RESET);
scanf("%s",E->nom);
char c;
do{printf(CYAN "donner l etat civil C/M/D" RESET);
scanf(" %c",&c);
}while(c!='C' && c!='M' && c!='D');
switch (c)
{case 'C' : E->etat=C;break;
case 'M' : E->etat=M;break;
case 'D' : E->etat=D;break;
}
do{printf(CYAN "donnez le salaire" RESET);
scanf("%f",&E->salaire);
}while(E->salaire<=0);
}

int main()
{service s;
printf(YELLOW "\n========= MENU =========\n" RESET);
printf(GREEN "1.Ajouter un employe \n" RESET);
printf(GREEN "2.Afficher tout les employes \n" RESET);
printf(GREEN "3.Chercher un employe par matricule \n" RESET);
printf(RED "4.Quitter \n" RESET);
 printf(YELLOW "========================\n" RESET);
int reponse;
do{printf(CYAN "reponse:" RESET);
scanf("%d",&reponse);
}while(reponse<0 || reponse>4);
switch(reponse){
	case 1 : employe E; saisie_emp(&E); ajout(E,&s);break;
	case 2 : afficher(s); break;
	case 3 : char mat[max_chaine]; printf("matricule a chercher :");scanf("%s",mat); if(recherche_employe(s,mat)){
printf(GREEN "l employe existe" RESET);}else{printf(RED "l employe n existe pas" RESET);};break;
    case 4 : return 0;
  
	}
}

