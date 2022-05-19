#include <stdio.h>

#define TAM 5

typedef struct NOTA{
    int codigoNota;
    char nombreAlumno[50];
    char cursoAlumno[3];
    float nota;
};


int main()
{

	FILE *fileW, *fileR;
    struct NOTA notas[TAM];
    struct NOTA current_nota;

    fileR = fopen("notas.bin", "rb");
	if(fileR == NULL){
		printf("Hubo un error al abrir el archivo");
	} else {

        // LEER
        fread(&notas,sizeof(notas),1,fileR);

        // mostrar antes de ordenar
        for(int x = 0; x < TAM; x++){
            printf("\nNOTA %i%c\n", x+1,-89);
            printf("Código: %i\n", notas[x].codigoNota);
            printf("Nombre: %s\n", notas[x].nombreAlumno);
            printf("Curso: %s\n", notas[x].cursoAlumno);
            printf("Nota: %f\n", notas[x].nota);
        }

        // tipical metetodo de ordenación no copiado de google
        for (int x = 0; x < TAM; x++){
            for (int y = x + 1; y <TAM; y++){
                if (notas[x].nota < notas[y].nota){
                    current_nota = notas[x];
                    notas[x] = notas[y];
                    notas[y] = current_nota;
                }
            }
        }

        // mostrar despues de ordenar
        for(int x = 0; x < TAM; x++){
            printf("\nNOTA %i%c\n", x+1,-89);
            printf("Código: %i\n", notas[x].codigoNota);
            printf("Nombre: %s\n", notas[x].nombreAlumno);
            printf("Curso: %s\n", notas[x].cursoAlumno);
            printf("Nota: %f\n", notas[x].nota);
        }
        fclose(fileR);

        // ESCRIBIR
        fileW = fopen("notas.ord","wb");
        if(fileW!=NULL){
            printf("Hubo un error al abrir el archivo");
        } else {
            fwrite(notas, sizeof(notas), 1, fileW);
            fclose(fileW);
            printf("Escrito correctamente y ordenado");
        }

	}

    return 0;
}
