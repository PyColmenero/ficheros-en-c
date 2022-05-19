#include <stdio.h>

#define MAX_TAM 11

int main()
{

	char string[MAX_TAM];
	// cuando imprimo por pantalla el string, los espacios
	// no asignados los rellena con carácteres basura
	for (int x = 0; x < MAX_TAM-1; x++) string[x] = ' ';
    //string[MAX_TAM - 1] = '\0';

    // instanciar el archivo
	FILE *file = fopen("fich2.txt", "w");

	if(file == NULL){

		printf("Hubo un error al abrir el archivo");

	} else {

		printf("Escribe una caracteres de uno en uno, máximo %i:\n", MAX_TAM-1);

		// fGet porque sino da error en caso que el
		// usuario se pase de carácteres
		int index = 0;
		char current_char;

		do{
		    // para baciar el buffer porque pilla el ENTER
		    // de la anterior vez y sigue para alante sin preguntar
            fseek(stdin,0,SEEK_END);
            // carácter introducido por comando
            scanf("%c", &current_char);
            // no meter el * en el string
            if(current_char!='*') {
                // agregar el CHAR al CHAR[]
                if(current_char!='\n') string[index] = current_char;
                index++;
            }
		}
		while( (index<MAX_TAM-1) && (current_char!='*') );

        // introducimos el CHAR[] en el FILE
		fputs(string, file);

		printf("Contenido escrito correctamente: %s\n", string);

	}
	// cierro el archivo
	fclose(file);

   return 0;
}
