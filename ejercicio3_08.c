#include <stdio.h>

#define VOWELS "aeiou"
#define CONSONANTS "bcdfghjklmnpqrstvwxyz"
#define NUMBERS "0123456789"
#define MAX_TAM 2

int main()
{

	char filename[50];
	FILE *file;

	int vowels = 0;
	int consonants = 0;
	int numbers = 0;
	int signs = 0;

	// get filename and file
	printf("Escribe el nombre del archivo: ");
	// fgets por si el nombre del archivo es superior
	// a MAX_TAM, que no de error
	gets(filename);
	file = fopen(filename, "r");
	//file = fopen("bibliografia.txt", "r");


	// "catch" error
	if(file == NULL){

		printf("Hubo un error al abrir el archivo\n");

	} else { // si existe el archivo

		// recorremos el archivo ede CHAR en CHAR
		char string[2];
		while(fgets(string, MAX_TAM, file) != NULL){

            // cojo el CHAR y lo pongo en minúsculas
            char current_char = string[0];
            current_char = tolower(current_char);

            // si el carácter no es NULO
            if( current_char != 0 ){

                // comprobamos para cada uno de los grupos de carácteres
                int isvowel = strchr(VOWELS, current_char);
                int isconsonant = strchr(CONSONANTS, current_char);
                int isnumber = strchr(NUMBERS, current_char);

                // comprobamos cual es el afortunado
                if(isvowel != 0) {
                    vowels++;
                } else if(isconsonant != 0) {
                    consonants++;
                } else if(isnumber != 0) {
                    numbers++;
                } else if(current_char != "\n") { // si no es ninguno, pero tampoco un salto de linea.
                    signs++;
                }
            }
		}

		// imprimir los datos
        printf("\nDatos del archivo %s:", filename);
        printf("\nVOCALES: %i", vowels);
        printf("\nCONSONANTES: %i", consonants);
        printf("\nNUMEROS: %i", numbers);
        printf("\nSIGNOS: %i\n", signs);

	}
	// cerrar archivo
    fclose(file);

    return 0;
}
