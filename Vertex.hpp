#pragma once

#include <iostream>
#include <string>
#include <utility>
#include <map>

#include "Sala.hpp"

class Vertex
{
public:
	enum class Colors { BLACK, GRAY, WHITE };

private:
	
	mutable std::list<Vertex> neighbors; ///< lista de vértices adyacentes (vecinos)
	
	int distance{ 0 }; ///< es la distancia de un vértice al punto de inicio
	
	Colors color{ Colors::BLACK }; ///< es el estado del vértice
	
	mutable std::string predecesor{ "Nil" }; ///< es el predecesor del vértice

public:

	mutable Sala* s; ///< es una sala que se guarda en cada vertice
	
	/**
	 * @brief Construye un nuevo objeto Sala
	 * 
	 * @param s 
	 */
	Vertex( Sala* s );

	/**
	 * @brief Obtiene la sala
	 * 
	 * @return Sala* una referencia a el objeto
	 */
	Sala* get_sala();

	void        add_neighbor( Vertex s );
	void        print_neighbors();
	void        print();

	std::list<Vertex>* get_neighbors();

	void        set_distance( int distance );
	void		set_weight(int w);
	void        set_color( Vertex::Colors color );
	void        set_predecesor( std::string predecesor );
	int         get_distance();
	int			get_weight();
	Colors      get_color();
	std::string get_predecesor();
};

