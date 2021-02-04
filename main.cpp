/**
 * @file main.cpp
 * @author
 * 
 * Bautista GOnzales Ericka Maytte 
 * Fuerte Martinez Nestor Enrique
 * Tafolla Rosales Esteban
 * Vazquez SAnchez Erick Alejandro
 * 
 * @brief Simular un sistema de compra de boletos de cine
 * @version 0.1
 * @date 2021-02-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Cine.hpp"
#include "Sala.hpp"
#include "Vertex.hpp"
#define TAM 6
#define NUM_SALAS 4

int main() {

    Cine c;
    
    if( !c.Load() ) {

        std::cout << "Ocurrió un problema al cargar el estado del programa" << std::endl;
        exit( 1 );
    }

    char res = 'N';
    
    do {

        c.Comprar();

        std::cout << "\nDesea salir del sistema? [S/N] ";

        std::cin >> res;
        res = towupper( res );
        std::cin.ignore();

    } while( res != 'S' );

    if( !c.Save() ) {

        std::cout << "Ocurrió un problema al guardar el estado del programa" << std::endl;
        exit( 1 );
    }

}
