#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

char *strerror(int errnum);
int j;

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

	//for(i=0;i<134;i++)
	//	printf("%d\t%s\n",i, errores[i]);

        //llenar con el archivo errores
        printf("%s (%d). ERROR: %s, ", nfichero, nro_linea, errores[j]);
        printf("%s. %s\n", strerror(j), mensaje);
}

int main()
{
	char x[150];
	for(j=1;j<134;j++)
	{
//		printf("%d", j);
		sprintf(x, "Error no. %d", j);
		error(__FILE__, __LINE__, x);
	}
}

