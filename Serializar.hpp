#pragma once

#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <cstring>
#include <map>

#include "Vertex.hpp"

class Serializar
{
public:

	/**
	 * @brief Construye un objeto Serializar
	 * 
	 */
	Serializar();

	/**
	 * @brief Serializa las peliculas
	 * 
	 * @param peliculas es un vector que incluye las peliculas disp en el cine 
	 */
	bool serializar_xml_Peliculas( std::vector<Pelicula> peliculas );

	/**
	 * @brief Serializa la estructura de las salas
	 * 
	 * @param list la lista de vértices
	 */
	bool serializar_xml_Sala( std::map<std::string, Vertex>* list );
};