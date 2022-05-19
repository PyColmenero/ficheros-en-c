#include <stdio.h>

#define TAM 1

typedef struct LISTIN{
    char nombre[50];
    char direccion[100];
    int telefono;
};

int main()
{
    // GENERAR LISTINES VACIOS
    struct LISTIN listines[TAM];
    // 20 veces asignar un LISTIN "vacio"
    for(int x = 0; x < TAM; x++){

        // memcpy porque sino me da error al asignar implicitamente un array
        memcpy(listines[x].nombre, "", 1);
        memcpy(listines[x].direccion, "", 1);
        listines[x].telefono = 0;

    }
    printf("\nListines creados, pesan %i.\n", sizeof(listines));

    // ESCRIBIR ARCHIVO BINARIO;
    FILE *fileW;
    fileW = fopen("listines.bin","wb");

    if(fileW != NULL){
        // escribir
        fwrite(&listines, sizeof(listines), 1, fileW);
        fclose(fileW);
        printf("Archivo generado correctamente");

    } else {
        printf("Hubo un error al abrir el archivo");
    }

    return 0;
}
