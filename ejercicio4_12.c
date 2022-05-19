#include <stdio.h>

int main()
{
    int numero = 0;
	char string[100];
	FILE *file1;
	FILE *file2;
    file2 = fopen("uno.bin", "rb");
    file1 = fopen("uno.bin", "wb");


	if(file1 == NULL){

		printf("Hubo un error al abrir el archivo");

	} else {

        // ESCRIBIR EN EL ARCHIVO
		// escanea el INT

		printf("Escribe un numero entero: ");
		scanf("%d", &numero);
		// escribimos en binario el número
		fwrite(&numero, sizeof numero, 1, file1);
		fclose(file1);

        // LEER EL INTERIOR DEL ARCHIVO
        numero = 0; // reinicio la variable
		// abro el archivo de nuevo, pero esta vez indico que es lectura

		if(file2 == NULL){
            printf("Hubo un error al abrir el archivo");
        } else {
            // lo leo y lo meto en la variable
            fread(&numero, sizeof numero, 1, file2);
            printf("\nContenido: %i \n", numero);
            fclose(file2);
        }






	}

   return 0;
}
