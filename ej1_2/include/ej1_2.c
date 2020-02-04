#include <stdio.h>
#include <string.h>
#include "mic.h"
#include <errno.h>

extern int errno;

int main()
{
    int i;
    char mensaje[100];
    for(i=1;i<134;i++)
    {
        errno=i;
        sprintf(mensaje, "Error no. %d", i);
        error(__FILE__, __LINE__, mensaje);
    }
    return 0;
}