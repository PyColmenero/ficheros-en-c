#include <stdio.h>
#include <stdlib.h>

typedef struct FACTURA{
    int codigo;
    int dia;
    int mes;
    int anyo;
    int importe;
};


int FACTURA_LENGTH;

int get_file_length(FILE *file);
int get_factura_size();

void show_menu();
void delete_factura();
void show_facturas();
void addup_factura();

const char FILENAME[] = "facturas.bin";

int main(){

    FACTURA_LENGTH = get_factura_struct_size();

    show_menu();

    return 0;
}

void create_factura(){

    FILE *fileW;
    struct FACTURA current_factura;
    fileW = fopen(FILENAME, "ab");

	if(fileW == NULL){
		printf("Hubo un error al abrir el archivo");
	} else {

		printf("ESCRIBE LA FACTURA:\n");

        // Otros atributos por consola
        // CODIGO
        int codigo = time(0);

        // FECHA
        int dia = 0, mes = 0, anyo = 2021;
        printf("Fecha:\n");
        printf("  Dia: ");
        scanf("%i", &dia);
        printf("  Mes: ");
        scanf("%i", &mes);
        printf(" Anyo: ");
        scanf("%i", &anyo);

        // IMPORTE
        int importe = 0;
        printf("Importe: ");
        scanf("%i", &importe);

        // ESCRIBIR LOS DATOS
        current_factura.codigo = codigo;
        current_factura.dia = dia;
        current_factura.mes = mes;
        current_factura.anyo = anyo;
        current_factura.importe = importe;

        // GUARDAR Y CERRAR
        fwrite(&current_factura,sizeof(current_factura),1,fileW);
        fclose(fileW);

        // TERMINAR
        system("cls");
        printf("\nDatos escritos correctamente.\n\n");
        show_menu();
	}
}
void delete_factura(){

    // LEEMOS Y GUARDAMOS TODAS LAS FACTURAS ANTES DE ESCRIBIR Y PERDERLAS
    FILE *fileR;
    fileR = fopen(FILENAME, "rb");

    int file_length = 0;
    int facturas_ammount = 0;

	if(fileR == NULL){
		printf("Hubo un error al abrir el archivo");
	} else {

        // get informacion del archivo
        file_length = get_file_length(fileR);
        facturas_ammount = file_length/FACTURA_LENGTH;

        // GUARDAMOS LAS FACTURAS
        struct FACTURA last_facturas[facturas_ammount];
        fread(&last_facturas,sizeof(last_facturas),1,fileR);

        // ESTRUCTURA SIN LA FACTURA CORRESPONDIENTE
        struct FACTURA new_facturas[facturas_ammount-1];

        int factura_index = 0;
        printf("\nQue factura quieres borrar? ");
        for(int x = 0; x < facturas_ammount; x++){
            printf("\nFACTURA %i: ", x+1);
            printf("Codigo: %i, ", last_facturas[x].codigo);
            printf("Fecha: %02i/%02i/%04i, ", last_facturas[x].dia, last_facturas[x].mes, last_facturas[x].anyo);
            printf("Importe: %i\$", last_facturas[x].importe);
        }

        // PREGUNTAR FACTURA A BORRAR
        printf("\n: ");
        scanf("%i", &factura_index);


        if(factura_index > 0 && factura_index <= facturas_ammount){ // si la factura existe

            char confirm = ' ';
            printf("\nSeguro que quieres borrar esta factura?(Y/N)");
            do{
                // borramos el buffer para que no se quede el \n al final
                fseek(stdin,0,SEEK_END);
                printf(": ");
                scanf("%c", &confirm);
                if(confirm == 'Y' || confirm == 'y'){
                    // borrar

                    // CREAR NUEVA LISTA DE FACTURAS SIN LA SELECCIONADA
                    int index = 0;
                    for(int x = 0; x < facturas_ammount; x++){
                        if((factura_index-1) != x){
                            new_facturas[index] = last_facturas[x];
                            index++;
                        }
                    }

                    // ESCRIBIMOS EN EL ARCHIVO BINARIO
                    FILE *fileW;
                    fileW = fopen(FILENAME, "wb");

                    if(fileW != NULL){
                        fwrite(new_facturas, sizeof new_facturas, 1, fileW);
                        fclose(fileW);

                        system("cls");
                        printf("\nFactura borrada correctamente.\n");
                        show_menu();

                    } else {
                        printf("Hubo un error al abrir el archivo");
                    }


                } else if(confirm == 'N' || confirm == 'n'){
                    system("cls");
                    printf("\nFactura intancata.\n");
                    show_menu();
                } else {
                    printf("\nNo te he entendido, escribe Y o N");
                }
            } while(confirm != 'Y' && confirm != 'N' && confirm != 'y' && confirm != 'n');

        } else {
            printf("\nFactura no encontrada.\n");
            show_menu();
        }
	}
}
void show_facturas(){

    FILE *fileR;
    fileR = fopen(FILENAME, "rb");

    int file_length = 0;
    int facturas_ammount = 0;

	if(fileR == NULL){
		printf("Hubo un error al abrir el archivo");
	} else {

        // get informacion del archivo
        file_length = get_file_length(fileR);
        facturas_ammount = file_length/FACTURA_LENGTH;

        // crear STRUCT y guardar datos
        struct FACTURA facturas[facturas_ammount];
        fread(&facturas,sizeof(facturas),1,fileR);

        // sacar por pantalla los datos
        printf("\nHay %i facturas guardadas: \n", facturas_ammount);
        for(int x = 0; x < facturas_ammount; x++){
            printf("\nFACTURA %i: ========================================================\n", x+1);
            printf("  Codigo: %i\n", facturas[x].codigo);
            printf("  Fecha: %02i/%02i/%04i\n", facturas[x].dia, facturas[x].mes, facturas[x].anyo);
            printf("  Importe: %i\$\n", facturas[x].importe);
            printf("===================================================================\n");
        }
	}
    printf("\n");
    show_menu();

}
void addup_factura(){

    FILE *fileR;
    fileR = fopen(FILENAME, "rb");

    int file_length = 0;
    int facturas_ammount = 0;

    int suma = 0;

    if(fileR!=NULL){

        // get informacion del archivo
        file_length = get_file_length(fileR);
        facturas_ammount = file_length/FACTURA_LENGTH;

        // GUARDAMOS LAS FACTURAS
        struct FACTURA facturas[facturas_ammount];
        fread(&facturas,sizeof(facturas),1,fileR);

        for(int x = 0; x < facturas_ammount; x++) {
            suma += facturas[x].importe;
            printf("FACTURA %i:\t%i$\t%i$\n", x,facturas[x].importe,suma);
        }
        printf("----------------------------\n");
        printf("TOTAL: \t\t\t%i$\n\n",suma);

        show_menu();

    } else {
        printf("Hubo un error al abrir el archivo");
    }
}

void show_menu(){

    int index = 0;

    // borramos el buffer para que no haga buble infinito
    fseek(stdin,0,SEEK_END);

    //printf("Elije qu� quieres hacer: \n");
    printf("\nEscribe 1 si quieres MOSTRAR UNA FACTURA.\n");
    printf("Escribe 2 si quieres CREAR UNA FACTURA.\n");
    printf("Escribe 3 si quieres BORRAR FACTURAS.\n");
    printf("Escribe 4 si quieres CALCULAR SUMA DE FACTURAS.\n");
    printf("Escribe 5 si quieres SALIR DEL PROGRAMA.\n");
    printf(": ");
    scanf("%i", &index);

    switch(index){
        case 2:
            system("cls");
            create_factura();
            break;
        case 3:
            system("cls");
            delete_factura();
            break;
        case 1:
            system("cls");
            show_facturas();
            break;
        case 4:
            system("cls");
            addup_factura();
            break;
        case 5:
            printf("Bye :)\n");
            break;
        default:

            system("cls");

            printf("\nNo te he entendido.\n\n");
            show_menu();
    }

}

int get_file_length(FILE *file){

    fseek(file, 0, SEEK_END);
    // as� consigo el tama�o del archivo
    int file_size = ftell(file);
    // vuelvo al inicio
    fseek(file, 0, SEEK_SET);
    return file_size;

}
int get_factura_struct_size(){

    struct FACTURA factura;
    return sizeof factura;

}

