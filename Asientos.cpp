#include"Asientos.hpp"

static std::string mayusculas( std::string pal );
static std::string minusculas( std::string pal );

Asientos::Asientos() {
    create();
}

void Asientos::create() {

    char letra = 'A';
    for( size_t i = 0;i <filas; i++ ){
        for( size_t j = 0; j<colms; j++ ){

            char let = letra + j;
            char letrasig = letra+i;

            pareja.first = letrasig;
            pareja.first += let;

            pareja.second = true;

            asientos[ i ][ j ] = pareja;
            let++;
        }
    }
}

int Asientos::contarAsientos() {

    int asientos_dis = 0;

    for( int i = 0; i < filas; i++ ){
        for( int j = 0; j < colms; j++ ){

            if( asientos[ i ][ j ].second ) asientos_dis++;
        }
    }

    return asientos_dis;
}

void Asientos::print() {

    for( int i = 0; i < filas; i++ ){
        for( int j = 0; j < colms; j++ ){

            std::cout<<"\t"<<asientos[ i ][ j ].first;
            asientos[ i ][ j ].second == true ? std::cout<<"=>O" : std::cout<<"=>X";
        }

        std::cout<<"\n";
    }
}

bool Asientos::seleccionarAsiento( std::string asiento ) {

    for( size_t i = 0; i < filas; i++ ){
        for( size_t j = 0; j < colms; j++ ){
            if( minusculas( asientos[ i ][ j ].first ) == asiento || mayusculas( asientos[ i ][ j ].first ) == asiento ){
                
                asientos[ i ][ j ].second = false;
                return true;
            }
        }
    }

    return false;
}

std::vector< std::string > Asientos::comprar_Asiento() {

    std::vector< std::string > asientos_comprados;

    std::cout<<"¿Cuantos asientos desea comprar? ";

    size_t asientosComprar = 0;
    std::cin >> asientosComprar;

    if( std::cin.fail() && std::cin.rdstate() ) {
        
        asientosComprar = 0;
    }

    if( asientosComprar > 0 && asientosComprar <= ( colms * filas ) ) {

        for( size_t i = 0; i < asientosComprar; i++ ) {

            std::cout << "\nElija los asientos que desee comprar que tengan el simbolo \'O\'" << std::endl;
            print();

            std::cout << "¿Que asiento desea comprar? ";
            std::string asiento = "";
            std::cin >> asiento;

            if( seleccionarAsiento(asiento) == true ) {

                asientos_comprados.push_back( asiento );
            } else {
                
                std::cout << "Ocurrio un error. Vuelva a introducir el asiento\n";
                i--;     
            }  
        }

        std::cout << "Lugar(es) escogido(s): ";

        for( auto& asiento : asientos_comprados ) {

            std::cout << asiento << " - ";
        }

    } 

    return asientos_comprados;
}

std::vector< std::string > Asientos::get_asientos_comprados() {

    std::vector< std::string > list_asientos;

    for( int i = 0; i < filas; i++ ) {
        for( int j = 0; j < colms; j++ ) {

            if( !asientos[ i ][ j ].second ) list_asientos.push_back( asientos[ i ][ j ].first );
        }
    }

    return list_asientos;
}

void Asientos::load( std::string asiento ) {

    for( int i = 0; i < filas; i++ ) {
        for( int j = 0; j < colms; j++ ) {

            if( asientos[ i ][ j ].first.compare( asiento ) == 0 ) {

                asientos[ i ][ j ].second = false;
            }
        }
    }
}

static std::string mayusculas( std::string pal ) {

    std::string palConvertida="";

    for( size_t i = 0; i < pal.length(); i++ ){
        palConvertida += towupper( pal[ i ] );
    }

    return palConvertida;
}

static std::string minusculas( std::string pal ) {

    std::string palConvertida="";

    for( size_t i = 0; i < pal.length(); i++ ){
        palConvertida += tolower( pal[ i ] );
    }

    return palConvertida;
}