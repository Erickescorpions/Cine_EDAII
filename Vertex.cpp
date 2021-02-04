#include "Vertex.hpp"

Vertex::Vertex( Sala* s )
{
	this->s = s;
}

void Vertex::add_neighbor( Vertex v )
{
	this->neighbors.push_back( v );
}

std::list<Vertex>* Vertex::get_neighbors()
{
	return &(this->neighbors);
}

Sala* Vertex::get_sala()
{
	return this->s;
}

void Vertex::set_distance( int distance )
{
	this->distance = distance;
}

void Vertex::set_color( Vertex::Colors color )
{
	this->color = color;
}

void Vertex::set_predecesor( std::string predecesor )
{
	this->predecesor = predecesor;
}

int Vertex::get_distance()
{
	return this->distance;
}

Vertex::Colors Vertex::get_color()
{
	return this->color;
}

std::string Vertex::get_predecesor()
{
	return this->predecesor;
}

