#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

char *strerror(int ernum);

void error_fatal(char* mensaje, int codigo_salida)
{
        char  errores[134][30];
        strcpy(errores[0],"");
        int i=1;
        FILE *name;
        name=fopen("errores", "r");
        if(name!=NULL)
        {
                while((fscanf(name, "%s", errores[i])!=EOF)&&(i<134))
                {
                        i++;
                }
                fclose(name);
                if(i<134)
                {
                        while(i<134)
                        {
                                strcpy(errores[i],"");
                                i++;
                        }
                }
        }
        else
        {
                printf("No FILE");
        }      
	char message[100]; 
	sprintf(message, "ERROR FATAL: %s, %s. %s", errores[errno], strerror(errno), mensaje);

        printf("%s", message);
	exit(codigo_salida);
}
