
#include <stdio.h>

#define MAX_TAM 11

int main()
{
    char current_string[2];
	FILE *fileR, *fileW;
    fileR = fopen("fich1.txt", "r");

	if(fileR == NULL){

		printf("Hubo un error al abrir el archivo");

	} else {

        // llevar el "puntero" al final del archivo
        fseek(fileR, 0, SEEK_END);
        // así consigo el tamaño del archivo
        int file_size = ftell(fileR); // get current file pointer
        // vuelvo al inicio
        fseek(fileR, 0, SEEK_SET);
        // string con los carácteres justos.

        char real_string[file_size];
        char new_string[file_size];
        for (int x = 0; x < file_size-1; x++) new_string[x] = ' ';
        //printf("%i\n",file_size);
        fgets(&real_string, file_size, fileR);
        // vuelvo al inicio
        fseek(fileR, 0, SEEK_SET);

        int index = 0;
        while(fgets(current_string, 2, fileR) != NULL){

            char current_char = current_string[0];
            if(current_char!=32) {

                new_string[index] = current_char;
                index++;
            }
        }

        // eliminar los espacios sobrantes
        strtok(&new_string, " ");
        printf("De '%s' a '%s'", real_string, new_string);


        //fputs(&string, fileW);
        fileW = fopen("sinblancos.txt", "w");

        if(fileW!=NULL){

            fputs(&new_string, fileW);
        } else {
            printf("Hubo un error al abrir el archivo");
        }


	}
	// cierro el archivo
	fclose(fileR);

   return 0;
}
