#pragma once 

#include <string>
#include <assert.h>
#include <iostream>
#include <list>
// para los arreglos []

#include "Pelicula.hpp"

class Map 
{
public:
    
    int  size; ///< Es el número máximo de elementos en la tabla
    
    int  len; ///< Es el número actual de elementos en la tabla      
    
    Pelicula* table; ///< Es la tabla hash

    /**
     * @brief Construye un nuevo objeto Map
     * 
     * @param size es el número máximo de elementos en la tabla
     */
    Map( int size );

    /**
     * @brief Destruye el objeto Map
     * 
     */
    ~Map();

    /**
     * @brief Inserta un nuevo valor al tabla
     * 
     * @param key el valor que se va a insertar
     * @return true sí se inserto correctamente el valor 'key'
     * @return false 'no' se inserto el valor 'key'
     */
    bool Insert( Pelicula key );

    /**
     * @brief Busca un valor dentro del tabla
     * 
     * @param key la clave del valor que se esta buscando
     * @return Pelicula* apuntador al valor
     */
    Pelicula* Search( std::string key ); 

    /**
     * @brief Remueve un valor del tabla
     * 
     * @param key la clave del valor a remover.
     * @return true sí se removió correctamente el valor.
     * @return false sí no se removio el valor.
     */
    bool Remove( std::string key );

    std::vector< Pelicula > getPeliculas();

private:
    
    /**
     * @brief Función hash
     * 
     * @param cadena es la clave a calcular.
     * @param size es el número máximo de elementos en la tabla
     * @return size_t la posicion de la 'clave' en la tabla  
     */
    size_t h( std::string cadena, int size );

    /**
     * @brief Es la función de resolución de colisiones
     * 
     * @param i un valor entero
     * @return size_t el valor 'i' al cuadrado
     */
    size_t probe( long int i );
};