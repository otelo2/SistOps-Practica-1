#include <stdio.h>
#include <errno.h>
#include <mic.h>

void error(char* nfichero, int nro_linea, char* mensaje)
{

}

int main()
{
    extern int sys_nerr;
    int i;
    char mensaje[50];
    
    for(i=0;i<=sys_nerr;i++)
    {
        sprintf(mensaje,"Error nro. %d",i);
        errno=i;
        error(__FILE__,__LINE__, mensaje);
        printf("a");
    }    
    printf("fin");
}