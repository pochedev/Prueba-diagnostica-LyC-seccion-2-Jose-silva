#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Estructura para el diccionario de traducción
typedef struct {
    char *ingles;
    char *espanol;
} PalabraReservada;

PalabraReservada diccionario[] = {
    {"int", "entero"}, {"float", "flotante"}, {"char", "caracter"},
    {"if", "si"}, {"else", "sino"}, {"while", "mientras"},
    {"for", "para"}, {"return", "retornar"}, {"void", "vacio"},
    {"switch", "cambiar"}, {"case", "caso"}, {"default", "defecto"},
    {"break", "romper"}, {"double", "doble"}, {"struct", "estructura"}
};

const int TOTAL_PALABRAS = sizeof(diccionario) / sizeof(diccionario[0]);

// Función para buscar la traducción
const char* traducir(char *token) {
    for (int i = 0; i < TOTAL_PALABRAS; i++) {
        if (strcmp(token, diccionario[i].ingles) == 0) {
            return diccionario[i].espanol;
        }
    }
    return token; // Si no es reservada, devuelve el original
}

int main() {
     char *palabra = "hola";
    printf("%s", traducir(palabra));
    return 0;
}