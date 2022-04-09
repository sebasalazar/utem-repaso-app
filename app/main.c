#include <stdio.h>
#include <stdlib.h>

/**
 * @param argc La cantidad de argumentos desde la línea de comandos.
 * @param argv La matriz asociativa con los argumentos de la línea de comandos.
 * @return el código de salida del sistema
 */
int main(int argc, char** argv) {
    if (argc > 1) {
        fprintf(stdout, "La cantidad de argumentos recibidos es de %d argumentos\n", argc);
    } else {
        fprintf(stderr, "NO hay argumentos en la invocación del programa %s\n", argv[0]);
    }

    return EXIT_SUCCESS;
}

