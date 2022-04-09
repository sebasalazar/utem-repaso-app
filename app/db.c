#include "db.h"

PGconn* dbconnect() {
    PGconn* conexion = NULL;
    
    char* info = (char *) calloc(128, sizeof(char));
    snprintf(info,128,"host='%s' port='%d' dbname='%s' user='%s' password='%s'",SERVIDOR,PUERTO,NOMBREDB,USUARIODB,PASSDB);
    
    conexion = PQconnectdb(info);
    if (PQstatus(conexion) == CONNECTION_BAD) {
        fprintf(stderr,"\nNO fue posible conectarse al servidor: %s\n",SERVIDOR);
        conexion = NULL;
    }

    return conexion;
}
