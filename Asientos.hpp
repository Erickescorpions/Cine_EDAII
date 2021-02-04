#pragma once
#include<iostream>
#include<utility>
#include<vector>
#include <exception>
#include <limits>

// el numero de filas de asientos que hay
#define filas 8

// el numero de columnas de asientos 1que hay
#define colms 10

class Asientos{
private:
    
    std::pair< std::string, bool > pareja; ///< es un pair en donde se guarda la clave del asiento y un bool que dice si esta comprado o no.
    
    std::pair< std::string, bool > asientos[ filas ][ colms ]; ///< es una matriz que simboliza los asientos
    
    /**
     * @brief Crea la matriz
     * 
     */
    void create();

    /**
     * @brief Comprueba que un asiento no este ya comprado
     * 
     * @param asiento es la clave del asiento 
     * @return true si el asiento no esta comprado
     * @return false si el asiento esta comprado
     */
    bool seleccionarAsiento( std::string asiento );

    /**
     * @brief Imprime la matriz. 
     * 
     */
    void print();

public:

    /**
     * @brief Construye un nuevo objeto Asientos
     * 
     */
    Asientos();

    /**
     * @brief Permite comprar los asientos
     * 
     * @return std::vector< std::string > Una lista de los asientos comprados
     */
    std::vector< std::string > comprar_Asiento();

    /**
     * @brief Cuenta cuantos asientos disponibles hay
     * 
     * @return int el número de asientos disponibles
     */
    int contarAsientos();

    /**
     * @brief Obtiene las claves de los asientos comprados para guardar el estado del programa
     * 
     * @return std::vector< std::string > Una lista de los asientos comprados
     */
    std::vector< std::string > get_asientos_comprados();

    /**
     * @brief Inicializa el estado de los asientos comprados.
     * 
     * @param asiento la clave de un asiento
     */
    void load( std::string asiento );
};