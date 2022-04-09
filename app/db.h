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
#include <string.h>
#include <postgresql/libpq-fe.h>


/**
 * Función que permite conectarse al motor de base de datos y retorna un puntero a la estructura adecuada.
 */
PGconn* conectar();

/**
 * Desconecta del servidor.
 *
 * @param conexion Estructura de conexión al motor de base de datos
 */
void desconectar(PGconn* conexion);


/**
 * @param PGconn* puntero a una conexión de base de datos.
 * @param consultaSQL Consulta a ejecutar contra el motor de base de datos.
 * @return Una estructura de resultados 
 */
PGresult* consultar(PGconn* conexion, char* consultaSQL);

/**
 * Libera la memoria usada por una consulta SQL.
 *
 * @param resultado Estructa con datos de una respuesta SQL
 */
void liberar(PGresult* resultado);

#ifdef __cplusplus
}
#endif

#endif /* DB_H */
 