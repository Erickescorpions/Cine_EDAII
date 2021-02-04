#include "Pelicula.hpp"

Pelicula::Pelicula() {
    
    this->nombre = "";
}

Pelicula::Pelicula( std::string _nombre ) {

    this->nombre = _nombre;
    this->butaca = Asientos();
}