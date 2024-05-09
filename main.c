#include <stdio.h>
#include <string.h>


struct Date {
    int jour;
    int mois;
    int annee;
};

struct Livre {
    signed char titre[50];
    signed char auteur[30];
    struct Date dateParution;
    int prix;
};

void affichLivre(struct Livre livre[],int i);
void ajoutLivre(struct Livre biblioteque[], int i, signed char t[50], signed char a[30], int p, int j, int m, int ann);

int main(void) {

    printf("TD/TP Revisions 1\n\n");
    signed char t[50],a[30];
    int p = 0, j=0, m=0, ann =0, nbLivre = 0, quit = 0;

    printf("[Vos livres]\n");
    printf("Nombre de Livres : %d\n\n", nbLivre);

    do {
        printf("Combien de livre souhaitez vous ajoutez ? : " );
        scanf("%d", &nbLivre);

        if(nbLivre == 0){
            printf("Vous devez ajouter au moins 1 livre.");
        }

    } while (nbLivre == 0);

    struct Livre biblioteque[nbLivre];


        for (int i = 0; i < nbLivre; ++i) {
            printf("Veuillez indiquez les informations de votre livre numero %d.\n\n", i+1);
            ajoutLivre(biblioteque, i, t, a, p, j, m, ann);
        }

        printf("Nombre de Livres : %d\n\n", nbLivre);
        for (int i = 1; i <= nbLivre; ++i) {
            affichLivre(biblioteque,i);
        }

    while (quit != 1){
        printf("[Menu]\n");
        int i = 0, c = 0 ;
        for (; i < nbLivre; ++i) {
            printf("%d. %s\n",i+1,biblioteque[i].titre);
        }
        printf("%d. Ajouter un livre\n\n",i+1);
        printf("%d. Quitter\n\n",i+2);
        printf("Votre choix : ");
        scanf("%d",&c);
        printf("\n");

        if(c < i+1 && c > 0){
            affichLivre(biblioteque,c);
        }else if(c == i+1){
            ++nbLivre;
            printf("Veuillez indiquez les informations de votre livre numero %d.\n\n", nbLivre);
            ajoutLivre(biblioteque, nbLivre-1, t, a, p, j, m, ann);
        }else if(c == i+2){
            printf("Merci, Aurevoir\n");
            quit = 1;
        } else{
            printf("La valeur saisie n'est pas reconnue !! \n\n");
        }
    }


    return 0;
}
void affichLivre(struct Livre biblioteque[],int i){
    printf("[Livre %d]\n",i);
    printf("Titre --> %s\n", biblioteque[i-1].titre);
    printf("Auteur --> %s\n", biblioteque[i-1].auteur);
    printf("Date de parution --> %d/%d/%d\n", biblioteque[i-1].dateParution.jour, biblioteque[i-1].dateParution.mois, biblioteque[i-1].dateParution.annee);
    printf("Prix indicatif --> %d Euros", biblioteque[i-1].prix);
    printf("\n\n");
}

void ajoutLivre(struct Livre biblioteque[], int i, signed char t[50], signed char a[30], int p, int j, int m, int ann){
    //Titre
    printf("Titre : ");
    scanf(" %49[^\n]", t);
    printf("\n");
    //Auteur
    printf("Auteur : ");
    scanf(" %49[^\n]", a);
    //Date
    printf("\n Date de parution :\n");
    printf("Jour : ");
    scanf("%d", &j);
    printf("\n");

    printf("Mois : ");
    scanf("%d", &m);
    printf("\n");

    printf("Annee : ");
    scanf("%d", &ann);
    printf("\n");
    //Prix
    printf("\n Prix indicatif : ");
    scanf("%d", &p);
    printf("\n\n");


    strcpy(biblioteque[i].titre, t);
    strcpy(biblioteque[i].auteur, a);
    biblioteque[i].dateParution.jour = j;
    biblioteque[i].dateParution.mois = m;
    biblioteque[i].dateParution.annee = ann;
    biblioteque[i].prix = p;
}