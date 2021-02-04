#include "Serializar.hpp"

static void serializarAtributoS_xml(std::string atributo, std::string valor, FILE* salida);
static void serializarAsientos(std::string atributo, std::string valor, FILE* salida );

Serializar::Serializar() {}

bool Serializar::serializar_xml_Peliculas( std::vector<Pelicula> peliculas ) {

    std::string datos_xml = "Datos_cine.xml";
    
    FILE* salida = fopen( datos_xml.c_str(),"w");
    if ( salida == NULL ) return false; 


    fputs( "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n", salida);
    fputs(" <Peliculas>\n", salida);

    for ( auto& p : peliculas ){

        std::string nombre = p.nombre;
        
		serializarAtributoS_xml("nombre", nombre,salida);  
    }

    fputs(" </Peliculas>",salida );

    fclose( salida );    

    return true;
}

bool Serializar::serializar_xml_Sala( std::map<std::string, Vertex>* list ) {

	std::string datos_xml = "Datos_salas.xml";
    
    FILE* salida = fopen( datos_xml.c_str(),"w");
    if ( salida == NULL ) return false;

    fputs( "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n", salida);
    fputs(" <Salas>\n", salida);

    for ( auto v = list->begin(); v != list->end(); v++  ) {

		serializarAtributoS_xml("id", v->first, salida );

        std::vector< Pelicula > peliculas = v->second.s->m->getPeliculas();

		for( auto p : peliculas ) {
			serializarAtributoS_xml("nombre", p.nombre, salida );
			
			std::vector< std::string > asientos_comprados = p.butaca.get_asientos_comprados();
			
			for( auto a : asientos_comprados ) {

				serializarAsientos("butaca", a, salida );
			}
		}
    }

    fputs(" </Salas>",salida );

    fclose( salida );

    return true;
}

static void serializarAtributoS_xml(std::string atributo, std::string valor, FILE* salida) {
	fputs(" <", salida);
	fputs(atributo.c_str(), salida);
    fputs(">",salida);
	fputs( valor.c_str() , salida );
    fputs("</",salida);
	fputs(atributo.c_str(), salida);
    fputs(">\n",salida);
}

static void serializarAsientos(std::string atributo, std::string valor, FILE* salida ) {

	fputs(" <", salida);
	fputs(atributo.c_str(), salida);
    fputs(">",salida);
	
	fputs( valor.c_str(), salida);
	
	fputs("</",salida);
	fputs(atributo.c_str(), salida);
    fputs(">\n",salida);
}