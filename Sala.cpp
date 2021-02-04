#include "Sala.hpp"

Sala::Sala() {}

Sala::Sala( std::string id ) { 

    this->m = new Map( TABLE_SIZE );
    this->id = id;
}

Sala::~Sala() {}

void Sala::add_pelicula( Pelicula p ) {

    this->m->Insert( p );
}

Pelicula* Sala::get_pelicula( std::string nombre ) {

    return this->m->Search( nombre );
}