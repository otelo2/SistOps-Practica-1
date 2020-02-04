#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

char *strerror(int errnum);
extern errno;

void error(char* nfichero,  int nro_linea, char* mensaje)
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
	printf("%d", errno);

	//for(i=0;i<134;i++)
	//	printf("%d\t%s\n",i, errores[i]);

        //llenar con el archivo errores
        printf("%s (%d). ERROR: %s, ", nfichero, nro_linea, errores[errno]);
        printf("%s. %s\n", strerror(errno), mensaje);
}
