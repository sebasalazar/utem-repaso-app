#include "db.h"

PGconn* conectar() {
    PGconn* conexion = NULL;
    
    char* info = (char *) calloc(128, sizeof(char));
    snprintf(info,128,"host='%s' port='%d' dbname='%s' user='%s' password='%s'",SERVIDOR,PUERTO,NOMBREDB,USUARIODB,PASSDB);
    conexion = PQconnectdb(info);
    if (PQstatus(conexion) == CONNECTION_BAD) {
        fprintf(stderr,"\nNO fue posible conectarse al servidor: %s\n",SERVIDOR);
        conexion = NULL;
    }
    free(info);

    return conexion;
}


void desconectar(PGconn* conexion) {
    if (conexion != NULL) {
        PQfinish(conexion);
    }
}

PGresult* consultar(PGconn* conexion, char* consultaSQL) {
    PGresult* resultado = NULL;

    if (strlen(consultaSQL) > 10) {
        resultado = PQexec(conexion,consultaSQL);
    }

    return resultado;
}

void liberar(PGresult* resultado) {
    if (resultado != NULL) {
        PQclear(resultado);
    }
}

long contarResultados(PGresult* resultado) {
    long total = 0;
    if (resultado!=NULL) {
        char* tuplas = PQcmdTuples(resultado);
        sscanf(tuplas,"%ld",&total);
    }
    return total;
}

char* obtieneString(PGresult* resultado, int fila, int columna) {
    char* texto = NULL;
    if (resultado!=NULL) {
        texto = PQgetvalue(resultado,fila,columna);
    }
    return texto;
}
