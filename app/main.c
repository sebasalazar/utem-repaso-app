#include <stdio.h>
#include <stdlib.h>
#include "db.h"

/**
 * @param argc La cantidad de argumentos desde la línea de comandos.
 * @param argv La matriz asociativa con los argumentos de la línea de comandos.
 * @return el código de salida del sistema
 */
int main(int argc, char** argv) {
    
    PGconn* conexion = conectar();
    if (conexion!=NULL) {

        PGresult* respuesta = consultar(conexion,"SELECT VERSION()");
        if (respuesta != NULL) {
            char* version = obtieneString(respuesta, 0, 0);
            fprintf(stdout,"\n%s\n",version);
            liberar(respuesta);
        }

        desconectar(conexion);
    }

    return EXIT_SUCCESS;
}

