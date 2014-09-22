#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <wait.h>

#define NBMAXESSAIS 3

int main(int argc, char *argv[])
{
pid_t idproc;
int nbAlea, nbEssais=0;
int codeRetour=0, cr;

do{
srand(time(NULL));
idproc=fork();
if(idproc==-1)fprintf(stderr,"Erreur création processus fils.");
if(idproc==0)
{
nbAlea=rand()%100+1;
execlp("exo3","nbAlea",NULL);
fprintf(stderr,"Erreur d'exec");
exit(0);
}
codeRetour=wait(&cr);
nbEssais++;
if(WIFEXITED(cr)){
    printf("Execution normale avec code retour %d\n", WEXITSTATUS(cr));
}
else printf("Pb par signal: %d\n", WTERMSIG(cr));
}while(nbEssais<NBMAXESSAIS || codeRetour!=0);


}
