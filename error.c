#include <stdio.h>

int main()
{

    FILE *fileW;
    fileW = fopen("listines.bin","wb");

    if(fileW != NULL){

        printf("Escribamos...\n");
        int a = 2;
        fwrite(a, sizeof(a), 1, fileW);
        fclose(fileW);
        printf("Archivo generado correctamente");

    } else {
        printf("Hubo un error al abrir el archivo");
    }

    return 0;
}
