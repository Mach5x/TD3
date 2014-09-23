#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void messErr(char * mess, int cr){

	fprintf(stderr,"%s",mess);
	exit(cr);
}

int main(int argc,char * argv[])
{
	int cr;
	pid_t fils;	

	if(argc=!3)messErr("problème d'arguments",2);
	
	if(strcmp(argv[2],"aiguille") == 0) argv[2] = "-analog";
	else argv[2]="-d";
	
	fils = fork();
	if(fils == -1)messErr("echec du fork",3);

	if(fils == 0)
	{
		execlp("xclock","xclock","-bg",argv[1],argv[2],NULL);
		messErr("echec de l'execution du xclock",4);
		exit(2);
		
	}
	wait(&cr);	
	exit(0);
} 
