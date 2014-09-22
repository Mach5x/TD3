#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void messErr(char* mes, int cr){
        fprintf(stderr,"%s\n",mes);
        exit(cr);}

int main(int argc, char* argv[]){
pid_t idproc;
int i,cr;

        if(argc < 3 || argc > 10 ){
                messErr("Erreur arguments",1);
        }
        for(i = 0; i< argc - 2; i++){

                idproc = fork();
                if(idproc == -1){
                        messErr("Echec fork()",2);
                }
                if(idproc == 0){
                        execl("/media/tp/s2/systeme_reseau/An1112/TP4","existe.sh",argv[1],argv[i+2]);
                        messErr("Echec execution du programme",3);
                }
        }
        wait(&cr);
        if(WIFEXITED(cr)){
            if(WEXITSTATUS(cr) == 0){
                printf("Recherche aboutit dans le fichier : %s \n",argv[i+2]);
                exit(0);
            }
            printf("Recherche non aboutit dans les fichier : %s \n",argv[i+2]);
        }
        messErr("Chaine non trouvé \n",4);
}
