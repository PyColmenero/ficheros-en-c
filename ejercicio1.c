#include <stdio.h>

#define MAX_TAM 11

int main()
{

	char string[MAX_TAM];
	FILE *f;
	f = fopen("fich1.txt", "w");
    int errnum;

	if(f == NULL){

		printf("Hubo un error al abrir el archivo");

	} else {

		printf("Escribe una cadena de %i o menos caracteres:\n", MAX_TAM-1);

		// fGet porque sino da error en caso que el usuario se pase de carácteres
		fgets(string, MAX_TAM, stdin);

		fputs(string, f);

		printf("Contenido escrito correctamente.");

	}
	fclose(f);

   //system ("pause");
   return 0;
}
