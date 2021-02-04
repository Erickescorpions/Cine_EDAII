#pragma once 

#include <iostream>
#include <string.h>
#include<vector>
#include<stdlib.h>
#include <cstring>
#include <string>

#define PALABRAS 4

class Deserializar {

public: 
    
    std::vector< std::string > elementosExt; ///< es un vector en donde se guardan los datos leídos del archivo

    /**
     * @brief Construye un nuevo objeto Deserializar
     * 
     */
    Deserializar();

    /**
     * @brief Leé un archivo xml y extrae los datos
     * 
     * @param nombre es el nombre del archivo xml
     */
    bool xml_read(std::string nombre);
};