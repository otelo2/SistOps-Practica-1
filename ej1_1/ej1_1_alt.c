#include <stdio.h>
#include <errno.h>

char *strerror(int errnum);

int  main()
{
        int i;
        //¿Qué número indica el final de la lista?
        for(i=0;i<134;i++)
        {
                printf("%d: %s\n", i, strerror(i));
        }
        return 0;
}