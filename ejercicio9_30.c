#include <stdio.h>

#define TAM 1

typedef struct LISTIN{
    char nombre[50];
    char direccion[100];
    int telefono;
};

int get_file_length(FILE *file);

int main()
{

    // ESCRIBIR ARCHIVO BINARIO;
    FILE *fileW1, *fileW2;
    char filename01[50];
    char filename02[50];


    printf("Escribe el primer archivo: ");
    scanf("%s",filename01);
    printf("Escribe el segundo archivo: ");
    scanf("%s",filename02);

    fileW1 = fopen(filename01,"rb");
    fileW2 = fopen(filename02,"rb");

    int length1 = get_file_length(fileW1);
    int length2 = get_file_length(fileW2);


    if(length1 == length2){

        char contenido01[length1];
        char contenido02[length2];

        if(fileW1 != NULL){

            if(fileW2 != NULL){

                // escribir
                fread(&contenido01,sizeof(contenido01),1,fileW1);
                fread(&contenido02,sizeof(contenido02),1,fileW2);

                if (strcmp(contenido01, contenido02) == 0) {
                    printf("El archivo %s y el archivo %s son iguales.\n", filename01, filename02);
                } else {
                    printf("El archivo %s y el archivo %s NO son iguales.\n", filename01, filename02);
                }


            } else {
                printf("Hubo un error al abrir el segundo archivo");
            }

        } else {
            printf("Hubo un error al abrir el primer archivo");
        }

    } else {
        printf("-El archivo %s y el archivo %s NO son iguales.\n", filename01, filename02);
    }

    return 0;
}

int get_file_length(FILE *file){

    fseek(file, 0, SEEK_END);
    // así consigo el tamaño del archivo
    int file_size = ftell(file); // get current file pointer
    // vuelvo al inicio
    fseek(file, 0, SEEK_SET);
    return file_size;

}

