/*Copyright (C) 
 * 2019 - eda1 dot fiunam at yahoo dot com dot mx
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 */


#include "Graph.hpp"
#include <string.h>

Graph::Graph() {}

bool Graph::add_vertex( std::string name, Vertex v )
{
	auto ret = vertices.insert( { name, v } );
	// 'map' no permite duplicados, así que no hay necesidad de buscarlos
	
	return ret.second;
}

bool Graph::add_edge( std::string edge1, std::string edge2 )
{
	bool res = false;
	// uno, o ambos nodos, no existen
	
	auto v1 = this->vertices.find( edge1 );
	auto v2 = this->vertices.find( edge2 );

	if( v1 != this->vertices.end() and v2 != this->vertices.end() ){

		v1->second.add_neighbor( v2->second );
		v2->second.add_neighbor( v1->second );

		return true;
	}

	return res;
}

std::map<std::string, Vertex>* Graph::get_vertices()
{
	return &(this->vertices);
}

Vertex* Graph::get_vertex( std::string name )
{
	auto v = this->vertices.find( name );
	// .find() devuelve un iterador (apuntador) a la posición donde haya 
	// encontrado la coincidencia con la clave 'name'
	
	return &(v->second);
}

void Graph::bfs( std::string start )
{
	for( auto it = this->vertices.begin(); it != this->vertices.end(); ++it ){ 

		(it->second).set_color( Vertex::Colors::BLACK );
		(it->second).set_distance( 0 );
		(it->second).set_predecesor( "Nil" );
	}

   get_vertex( start )->set_color( Vertex::Colors::GRAY );

   std::deque<std::string> queue;
   queue.push_back( start );

   while( not queue.empty() ){

      std::string next_vertex = queue.front(); queue.pop_front();

      Vertex* vertex = get_vertex( next_vertex );

      std::list<Vertex>* v = vertex->get_neighbors();

      for( auto w = v->begin(); w != v->end(); ++w ){ 

         Vertex* neighbor = get_vertex( w->get_sala()->id );

         if( neighbor->get_color() == Vertex::Colors::BLACK ){

            neighbor->set_color( Vertex::Colors::GRAY );
            neighbor->set_distance( vertex->get_distance() + 1 );
            neighbor->set_predecesor( vertex->get_sala()->id );
            queue.push_back( neighbor->get_sala()->id );
         }
      }
      
      	vertex->set_color( Vertex::Colors::WHITE );
   }
}

void Graph::bfs_search( std::string start, std::string nombre_pelicula, std::vector<Sala>* salas ) {

	auto v = get_vertex( start );

	auto sala = v->get_sala();
	auto predecesor = v->get_predecesor();

	while( 1 ) {

		if( sala->get_pelicula( nombre_pelicula ) != nullptr ) {

			salas->push_back( *sala ); 
		}
		
		if( predecesor == "Nil" ) break;
		else v = get_vertex( predecesor );

		sala = v->get_sala();
		predecesor = v->get_predecesor();
	}
} 
