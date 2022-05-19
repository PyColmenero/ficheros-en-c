#include <stdio.h>

#define TAM 5

typedef struct NOTA{
    int codigoNota;
    char nombreAlumno[50];
    char cursoAlumno[5];
    float nota;
};

int main()
{

	FILE *fileW, *fileR;
    struct NOTA notasW[TAM];


    fileW = fopen("notas.bin", "wb");
	if(fileW == NULL){
		printf("Hubo un error al abrir el archivo");
	} else {

        // ESCRIBIR
		printf("Escribe %i notas:\n", TAM);
		// pedimos cada uno de los atributos por consola
		for(int x = 0; x < TAM; x++){
            //fseek(stdin,0,SEEK_END);
            fseek(stdin,0,SEEK_END);
            printf("\nNOTA %i%c\n", x+1,-89);
            // código aleatorio
            notasW[x].nota = rand();

            // Otros atributos por consola
			printf("Nombre: ");
			// fgets para que no supere lo máximo
			fgets((void*)(&notasW[x].nombreAlumno),sizeof(notasW[x].nombreAlumno), stdin);
			// borramos el \n que se queda al final de la variable
            strtok(&notasW[x].nombreAlumno, "\n");
            // borramos el buffer para que no se quede el \n al final
            fseek(stdin,0,SEEK_END);

			printf("Curso: ");
			// fgets para que no supere lo máximo
			fgets((void*)(&notasW[x].cursoAlumno),sizeof(notasW[x].cursoAlumno), stdin);
			// borramos el \n que se queda al final de la variable
			strtok(&notasW[x].cursoAlumno, "\n");
			// borramos el buffer para que no se quede el \n al final
			fseek(stdin,0,SEEK_END);

			printf("Nota: ");
			scanf("%f", &notasW[x].nota);
		}

		// escribir las notas en binario
		fwrite(notasW, sizeof(notasW), 1, fileW);
        fclose(fileW);

        // LEER
        printf("\nLEYENDO BINARIO");
        struct NOTA notasR[TAM];
        fileR = fopen("notas.bin", "rb");
        if(fileR == NULL){
            printf("Hubo un error al abrir el archivo");
        } else {
            fread(&notasR,sizeof(notasR),1,fileR);
            for(int x = 0; x < TAM; x++){
                printf("\nNOTA %i%c\n", x+1,-89);
                printf("Código: %i\n", notasR[x].codigoNota);
                printf("Nombre: %s\n", notasR[x].nombreAlumno);
                printf("Curso: %s\n", notasR[x].cursoAlumno);
                printf("Nota: %f\n", notasR[x].nota);
            }
            fclose(fileR);
        }
	}

    return 0;
}
