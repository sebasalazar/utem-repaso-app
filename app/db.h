/**
 * File: db.h
 * Archivo de funciones para interactuar con el motor de base de datos.
 */
#ifndef DB_H
#define DB_H

#ifdef __cplusplus
extern "C" {
#endif


#define SERVIDOR "db.sebastian.cl"
#define PUERTO 6432
#define NOMBREDB "utemdb"
#define USUARIODB "utem"
#define PASSDB "utem"

#include <stdio.h>
#include <stdlib.h>
#include <postgresql/libpq-fe.h>


/**
 * Función que permite conectarse al motor de base de datos y retorna un puntero a la estructura adecuada.
 */
PGconn* dbconnect();


#ifdef __cplusplus
}
#endif

#endif /* DB_H */
 