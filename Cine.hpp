#pragma once

#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <omp.h>
#include <stdlib.h>

#include "Graph.hpp"
#include "Pelicula.hpp"
#include "Serializar.hpp"
#include "Deserializar.hpp"

class Cine
{
public:
    
    Graph* salas; ///< es el grafo
    
    std::vector<Pelicula> peliculas; ///< es un vector que almacena las peliculas disponibles en el cine

    /**
     * @brief Construye un objeto Cine
     * 
     */
    Cine();

    /**
     * @brief Sistema de compra de boletos
     * 
     */
    void Comprar();
    
    /**
     * @brief Cargar el estado del programa
     * 
     * @return true sí se realizao correctamente la operación
     * @return false ocurrió un problema 
     */
    bool Load();

    /**
     * @brief Guarda el estado del programa
     * 
     * @return true sí se realizao correctamente la operación
     * @return false ocurrió un problema
     */
    bool Save();

private:

    /**
     * @brief IMprime las peliculas disponibles en el cine
     * 
     */
    void imprimir_peliculas();

    /**
     * @brief Busca una película en las salas
     * 
     * @param nombre_pelicula 
     * @return std::vector<Sala> 
     */
    std::vector<Sala> busqueda_pelicula( std::string nombre_pelicula );

    /**
     * @brief Compra boletos
     * 
     * @param salas_ordenadas es un arreglo de las salas en orden segun el numero de asientos 
     * @param tam es el tamaño del arreglo
     * @param nombre_pelicula es el nombre de la película que el usuario quiere ver
     * @return true se hizo la compra correctamente
     * @return false no se hizo la compra
     */
    bool comprar_boleto( Sala salas_ordenadas[], int tam, std::string nombre_pelicula );

    /**
     * @brief Imprime los datos de la compra en un archivo nombrado con
     *el nombre de la pelicula, la sala y los asientos comprados
     * 
     * @param nombre_pelicula nombre de la pelicula
     * @param sala id de la sala
     * @param asientos_comprados los asientos que se compraron 
     */
    void imprimir_boleto(std::string nombre_pelicula, std::string sala, std::vector< std::string > asientos_comprados );
};