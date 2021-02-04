#pragma once 

#include <string>
#include "Asientos.hpp"

class Pelicula 
{   
public:
    
    std::string nombre; ///< nombre de la película
    
    Asientos butaca; ///< son los asientos que tiene la película
    
    /**
     * @brief Construye un nuevo objeto Pelicula
     * 
     */
    Pelicula();

    /**
     * @brief Construye un nuevo objeto Pelicula
     * 
     * @param _nombre nombre de la película
     * @param _hora la hora de inicio de la película
     * @param _duracion la duración de la película
     */
    Pelicula( std::string _nombre );
};
