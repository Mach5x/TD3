#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void messErr(char* mes, int cr){
        fprintf(stderr,"%s\n",mes);
        exit(cr);
}

int main(){
        int i,cr,retour;
        pid_t idproc;

        for(i=0; i<3;i++){
                idproc = fork();
                if(idproc == -1){
                        messErr("Echec fork()",1);
                }
                if(idproc == 0){
                        execlp("xclock","xclock",NULL);
                        messErr("Echec de l'execution de xclock",2);
                        exit(2);
                }
        }

        wait(&cr);
        if(WIFEXITED(cr)){
                printf("Processus termni?? normalement\n");

        }
        else{
                messErr("Processus termin?? anormalement",3);
        }

        if(WIFSIGNALED(cr)){
                messErr("Processus arreter par un signal",4);
        }

        exit(0);
}
