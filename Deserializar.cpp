#include "Deserializar.hpp"

static bool vacio( char* palabra );
static char* datos( char* palabras[] );
static bool comparar( char* palabras[] );

Deserializar::Deserializar() {}

bool Deserializar::xml_read( std::string nombre ) {

	//vaciamos el vector de lecturas anteriores
	while( this->elementosExt.size() != 0 ) {

		this->elementosExt.pop_back();
	}

	std::string datos_xml = nombre + ".xml";

	char separador[] = ",\n\"\r;:_-+=/\()<>";
	
	char* almacen = NULL;
	char* almacen2 = NULL;
	char* almacen3[ PALABRAS ];

	int elementos = 0;
	
	FILE* entrada = fopen(datos_xml.c_str(),"r");
	
	if(entrada==NULL) {

		std::cout<<"El archivo no existe\n";
		return false;
	}

	char input[80];
	int cont = 0, num;

	while( !feof( entrada ) ) {

		fgets( input, 80, entrada );

		if( cont > 1 ) {

			almacen = strtok( input, separador );
			num = ( strlen( almacen ) ) + 1;
			while( almacen != NULL ) {
				if( elementos >= PALABRAS ) {
					if( comparar( almacen3 ) ) {
						char* data1 = datos( almacen3 );
						elementosExt.push_back( data1 );
					}

					elementos = 0;
				}

				almacen2 = (char *)malloc(num * sizeof(char));
				strcpy(almacen2, almacen);
				almacen = strtok(NULL, separador);
				almacen3[elementos] = almacen2;
				elementos++;
			}

			free(almacen2);
		}

		cont++; 
	}

	fclose(entrada);

	return true;	
}

static bool vacio( char* palabra ) {
	
	char res1 = palabra[0];
	char res2 = ' ';
	if(res1 == res2){
		return true;
	}
	return false;
}

static char* datos( char* palabras[] ) {

	return palabras[2];
}
	
static bool comparar( char* palabras[] ) {
	
	int res = strncmp( palabras[1], palabras[3], 2 );
	
	if( res >= 0 ) {
		if(vacio(palabras[2])!=true){
			return true;
		}
	}

	return false;
}