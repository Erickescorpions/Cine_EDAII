#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <deque>

#include "Vertex.hpp"

class Graph
{
private:
	
	mutable std::map<std::string, Vertex> vertices;  ///< Es un mapa qie contiene los vertices del grafo

public:
	/**
	 * @brief Construye un nuevo objeto Graph
	 * 
	 */
	Graph();
	
	/**
	 * @brief Añade un nuevo vértice al grafo 
	 * 
	 * @param name es el nombre con el que vamos a identificar al vertice
	 * @param v un objeto de tipo Vertex
	 * @return true sí se añadió correctamente.
	 * @return false sí no se añadió correctamente.
	 */
	bool add_vertex( std::string name, Vertex v );

	/**
	 * @brief Conecta dos vértices
	 * 
	 * @param edge1 nombre para identicar uno de los vertices que va a conectar la arista
	 * @param edge2 nombre para identicar el otro vertice que va a conectar la arista
	 * @return true sí se añadió correctamente la arista
	 * @return false sí no se añadió correctamente arista
	 */
	bool add_edge( std::string edge1, std::string edge2 );

	std::map<std::string, Vertex>* get_vertices();
	// devuelve la "lista" de vértices (en realidad es una tabla hash, pero la podemos pensar de esa manera)

	/**
	 * @brief Obtiene un vértice del grafo
	 * 
	 * @param name es la clave para buscar el vertice en cuestion.
	 * @return Vertex* devuelve el valor asociado a la clave 'name'
	 */
	Vertex* get_vertex( std::string name );
	
	/**
	 * @brief Busqueda en profundidad del grafo
	 * 
	 * @param start clave del vértice de inicio
	 */
	void bfs( std::string start );

	/**
	 * @brief Recorre el grafo para buscar el valor asociado a 'nombre_pelicula' 
	 * dentro de cada vértice y posteriormente devolver un vector con estos vértices
	 * que contienen dicho valor
	 * 
	 * @param start clave del vértice de inicio
	 * @param nombre_pelicula clave del valor a buscar
	 * @param salas vector en donde se almacenaran los vértices que contengan 'nombre_pelicula'
	 */
	void bfs_search( std::string start, std::string nombre_pelicula, std::vector<Sala>* salas );
};