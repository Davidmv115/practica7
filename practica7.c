#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leerPalabrasDeArchivo(char *nombreArchivo, char *arreglo) {
    FILE *archivo;
    char buffer[256];
    char palabra[256];
    int i = 0;

    archivo = fopen(nombreArchivo, "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo %s\n", nombreArchivo);
        exit(1);
    }

    while (fgets(buffer, 256, archivo) != NULL) {
        sscanf(buffer, "%s", palabra);
        strcpy(&arreglo[i*256], palabra);
        i++;
    }

    fclose(archivo);
}

void despliegaAhorcado(char *nombreArchivoFigura) {
    FILE *archivo;
    char buffer[256];

    archivo = fopen(nombreArchivoFigura, "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo %s\n", nombreArchivoFigura);
        exit(1);
    }

    while (fgets(buffer, 256, archivo) != NULL) {
        printf("%s", buffer);
    }

    fclose(archivo);
}

int main() {
    char palabras[256*10];
    leerPalabrasDeArchivo("palabras.txt", palabras);

    for (int i = 0; i < 10; i++) {
        printf("%s\n", &palabras[i*256]);
    }

    despliegaAhorcado("ahorcado5.txt");

    return 0;
}
