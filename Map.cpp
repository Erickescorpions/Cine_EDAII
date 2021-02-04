#include "Map.hpp"

Map::Map( int _size ) {

    this->len = 0;
    this->size = _size;

    this->table = new Pelicula[ _size ]; //Asigna memoria dinamica

    for( int i = 0; i < _size; i++ ) {

        this->table[ i ] = Pelicula();
    }
}

Map::~Map() {}

size_t Map::h( std::string cadena, int size ) {

    size_t i = 0;

    for( char chr : cadena ) {

        i = 131 * i + chr;
    }

    return i % size;
}

size_t Map::probe( long int i ) {

   return i * i ;
}


bool Map::Insert( Pelicula key ) {

    assert( this->len < this->size );

    //std::cout << key.nombre << std::endl;

    size_t home = h( key.nombre, this->size );
    size_t pos = home;

    int i = 0;
   
    while( this->table[ pos ].nombre.compare("") != 0 ) {

        pos = ( home + probe( i ) ) % this->size;
        
        if( this->table[ pos ].nombre.compare( key.nombre ) != 0 ) { 
            
            //std::cout << "nombres iguales" << std::endl;   
            return false;
        }

        ++i;
    }

    this->table[ pos ] = key; 
    
    ++this->len;

    return true;
}

Pelicula* Map::Search( std::string key ) {

    assert( this->len > 0 );

    size_t home = h( key, this->size );
    size_t pos = home;
    int i = 0;

    while( this->table[ pos ].nombre.compare("") != 0 && this->table[ pos ].nombre.compare( key ) != 0 ) {
        
        pos = ( home + probe( i ) ) % this->size;
        ++i;
    }

    if( this->table[ pos ].nombre.compare( key ) == 0 ) {
    
        return &this->table[ pos ];

    } else return nullptr;   
}

bool Map::Remove( std::string key ) {
    
    assert( this->len > 0 );
    
    size_t home = h( key, this->size );
    size_t pos = home;
    int i = 0;

    while( this->table[ pos ].nombre.compare("") != 0 && this->table[ pos ].nombre.compare( key ) != 0 ){
        
        pos = ( home + probe( i ) ) % this->size;
        ++i;
    }


    if( this->table[ pos ].nombre.compare( key ) == 0 ) {

        this->len--;
        this->table[ pos ] = Pelicula();
        return true;

    } else return false;   
}

std::vector< Pelicula > Map::getPeliculas() {

    std::vector< Pelicula > list;

    for( size_t i = 0; i < (size_t)this->size; i++ ) {
        
        if( this->table[ i ].nombre.compare("") == 0 ) continue;
        list.push_back( table[ i ] );
    }

    return list;
}