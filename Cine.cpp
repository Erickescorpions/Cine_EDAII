#include "Cine.hpp"

static void Sort( Sala list[], size_t first, size_t last, std::string nombre_pelicula );
static Sala* busqueda_Binaria( Sala salas_ordenadas[], int inf, int sup, std:: string sala );
static void imprimir_disponibilidad( Sala list[], int tam, std::string nombre_pelicula );

Cine::Cine() {

    this->salas = new Graph();
}

void Cine::Comprar() {

    std::cout << "\nSISTEMA DE COMPRA DE BOLETOS DEL CINE\n" << std::endl;
    imprimir_peliculas();

    std::cout << "Ingresa el nombre de la pelicula que desea ver: ";

    std::string nombre_pelicula = "";
    getline( std::cin, nombre_pelicula );
    
    std::vector<Sala> list = busqueda_pelicula( nombre_pelicula );

    int tam = list.size();

    if( tam > 0 ) {

        Sala salas_ordenadas[ tam ];

        for( int i = 0; i < tam; i++ ) {

            salas_ordenadas[ i ] = list[ i ];
        }

        if( tam > 1 ) Sort( salas_ordenadas, 0, tam - 1, nombre_pelicula );

        imprimir_disponibilidad( salas_ordenadas, tam, nombre_pelicula );

        if( comprar_boleto( salas_ordenadas, tam, nombre_pelicula ) ) {

            std::cout << "\n\nCompra exitosa, se imprimira su boleto en un archivo" << std::endl;
            //imprimir_boleto();
        } else {
            
            std::cout << "Ocurrió un problema"<< std::endl;
        }

    } else {

        std::cout << "NO hay peliculas con ese nombre" << std::endl;
    }
}

bool Cine::Save() {

    Serializar d;

    if( !d.serializar_xml_Peliculas( this->peliculas ) ) return false;
    if( !d.serializar_xml_Sala( this->salas->get_vertices() ) ) return false;

    return true;
}

// el numero de salas que abra en nuestro cine
#define NUM_SALAS 4

bool Cine::Load() {

    Deserializar d;    

    if( !d.xml_read("Datos_cine") ) return false;
    
    for( auto& s : d.elementosExt ) {

        this->peliculas.push_back( Pelicula( s ) );
    }

    if( !d.xml_read("Datos_salas") ) return false;

    Sala list[ NUM_SALAS ];

    int i = 0;
    std::string aux;

    for( auto& s : d.elementosExt ) {

        if( s.length() == 1 ) {

            list[ i ] = Sala( s );
            i++;
            continue;
        }

        if( s.length() > 2 ) {

            for( auto p : this->peliculas ) {

                if( p.nombre.compare( s ) == 0 ) {

                    list[ i - 1 ].add_pelicula( p );
                    aux = s;
                }
            }

            continue;
        }

        if( s.length() == 2 ) {

            list[ i - 1 ].get_pelicula( aux )->butaca.load( s );
        }
    }

    for( int i = 0; i < 4; i++ ) {
        
        this->salas->add_vertex( list[ i ].id , Vertex( &list[ i ] ) );
    }
    
    std::string edges[ 3 ] = {"AB", "BC", "CD" };

    for( auto& e : edges ) {

        this->salas->add_edge( e.substr( 0, 1 ), e.substr( 1, 1 ) );
    }

    return true;
}

void Cine::imprimir_peliculas() {

    std::cout << "\tPeliculas:" << std::endl;

    for( Pelicula p : this->peliculas ) {

        std::cout << " - " << p.nombre << std::endl;
    }

    std::cout << "\n";
}

std::vector<Sala> Cine::busqueda_pelicula( std::string nombre_pelicula ) {

    std::vector<Sala> salas;

    this->salas->bfs( "A" );
    this->salas->bfs_search( "D" , nombre_pelicula, &salas );

    return salas;
}

bool Cine::comprar_boleto( Sala salas_ordenadas[], int tam, std::string nombre_pelicula ) {
    
    std::cout << "\nEn que sala desea ver la pelicula? (Ingrese solo la letra Ej. \'A\') ";
    std::string sala = "";
    std::cin >> sala;
    sala = towupper( sala[ 0 ] );

    Sala* s;

    #pragma omp parallel default( none ) shared( s, salas_ordenadas, tam, sala)
    {
        #pragma omp single
        s = busqueda_Binaria( salas_ordenadas, 0, tam - 1, sala );
    }
    
    if( s != nullptr ) {

        std::vector< std::string > asientos_comprados = s->get_pelicula( nombre_pelicula )->butaca.comprar_Asiento();
        
        if( asientos_comprados.size() == 0 ) return false;
        imprimir_boleto( nombre_pelicula, sala, asientos_comprados );

        return true;

    } else return false;
}

void Cine::imprimir_boleto(std::string nombre_pelicula, std::string sala, std::vector< std::string > asientos_comprados ) {

    std::string nombre_archivo = nombre_pelicula + " - " + sala;

    for( auto& s : asientos_comprados ) {

        nombre_archivo += "; " + s;
    }

    nombre_archivo += ".txt";

    FILE* salida = fopen( nombre_archivo.c_str(), "w");

    if ( salida == NULL ) { exit( -1 ); }

    for( auto& s : asientos_comprados ) {

        fputs( "Sala:\t", salida );
        fputs( sala.c_str(), salida );
        fputs( "\nPelicula:\t", salida );
        fputs( nombre_pelicula.c_str(), salida );
        fputs( "\n", salida );
        fputs( "Asiento:\t", salida );
        fputs( s.c_str(), salida );
        fputs( "\n\n", salida );
        fputs( "---------------", salida );
        fputs( "\n\n", salida );
    }

    fclose( salida );
}

static void imprimir_disponibilidad( Sala list[], int tam, std::string nombre_pelicula ) {

    for( int i = 0; i < tam; i++ ) {

        std::cout << "\nSala " << list[ i ].id <<
                    "\nPelicula: " << nombre_pelicula <<
                    "\n# asientos disponibles: " << 
                    list[ i ].get_pelicula( nombre_pelicula )->butaca.contarAsientos() <<
                    std::endl;
    }
}

static void Sort( Sala list[], size_t first, size_t last, std::string nombre_pelicula ) {

    size_t x0 = first;
	size_t x1 = last;
	size_t mid = (first + last) / 2;
	int piv = list[ mid ].get_pelicula( nombre_pelicula )->butaca.contarAsientos();

	while( x0 <= x1 ) {

        int val1 = list[ x0 ].get_pelicula( nombre_pelicula )->butaca.contarAsientos();
		while( val1 < piv ) {
			x0++;
		}

        int val2 = list[ x1 ].get_pelicula( nombre_pelicula )->butaca.contarAsientos();
		while( piv < val2 ) {
			x1--;
		}

		if( x0 <= x1 ) {

            Sala tmp = list[ x0 ];
	        list[ x0 ] = list[ x1 ];
	        list[ x1 ] = tmp;

			x0++;
			x1--;
		}
	}

	if( first < x1 ) Sort( list, first, x1, nombre_pelicula );

	if( x0 < last ) Sort( list, x0, last, nombre_pelicula );
}

static Sala* busqueda_Binaria( Sala salas_ordenadas[], int inf, int sup, std:: string sala ) {
    
    int centro = ( ( sup + inf ) / 2 );
    Sala* s;

    #pragma omp task shared( inf, sup, s, sala, salas_ordenadas ) firstprivate( centro )
    {
        if( salas_ordenadas[ centro ].id.compare( sala ) == 0 ) {
            s = &salas_ordenadas[ centro ];
        } else if( sup == inf ) {
            s = nullptr;
        } else if( sala < salas_ordenadas[ centro ].id ) {
            s = busqueda_Binaria( salas_ordenadas, inf, centro, sala );
        } else {
            s = busqueda_Binaria( salas_ordenadas, centro + 1, sup, sala );   
        }
    }

    #pragma omp taskwait 
    return s;
}