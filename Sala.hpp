#pragma once 

#include <string>
#include <list>
#include <assert.h>
#include <iostream>
#include <string>

#include "Map.hpp"
#include "Pelicula.hpp"

#define TABLE_SIZE 10 ///< valor constante del número de películas por sala

class Sala {
public:

    std::string id; ///< es el nombre de la sala
    
    Map* m; ///< es una tabla dónde se almacenan las películas de la sala

    /**
     * @brief Construye un nuevo objeto Sala
     * 
     */
    Sala();

    /**
     * @brief Construye un nuevo objeto Sala
     * 
     * @param id es el nombre de la sala
     */
    Sala( std::string id );

    /**
     * @brief Destruye el objeto Sala
     * 
     */
    ~Sala();

    /**
     * @brief Añade una película a la sala
     * 
     * @param p el objeto que se va a añadir
     */
    void add_pelicula( Pelicula p );

    /**
     * @brief Obtiene una película
     * 
     * @param nombre es el nombre de la película
     * @return Pelicula* Regresa una referencia a la película dentro de la sala
     */
    Pelicula* get_pelicula( std::string nombre );
};
