#include <stdio.h>

#define TAM 10

int main()
{
    FILE *file1, *file2;
	float current_number = 0;
    float list[TAM];

    file1 = fopen("tabla3.dat", "wb");

	if(file1 == NULL){
		printf("Hubo un error al abrir el archivo");
	} else {

        // ESCRIBIR
        // Leemos por consola los números
		printf("Escribe %i numeros:\n", TAM);
		for(int x = 0; x < TAM; x++){
            // limpio el buffer, pq si el usuario introduce una letra
            // este dejará de escanera
            fseek(stdin,0,SEEK_END);
            // pido el float
			printf("Numero %02i: ", x+1);
			scanf("%f", &current_number);
			// guardo el valor en la lista
			list[x] = current_number;

		}
		// escribirmos la lista como binario
		fwrite(&list, sizeof list, 1, file1);
        fclose(file1);

        // LEER
        if(file2 == NULL){
            printf("Hubo un error al abrir el archivo");
        } else {

            file2 = fopen("tabla3.dat", "rb");
            float buffer[TAM];

            fread((void*)(&buffer),sizeof(buffer),1,file2);
            // itramos el resultado y lo imprimimos por pantalla
            for(int x = 0; x < TAM; x++){
                printf("\n%f", buffer[x]);
            }
            fclose(file2);
        }
	}

    return 0;
}
