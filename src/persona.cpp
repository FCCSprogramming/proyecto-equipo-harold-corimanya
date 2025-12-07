#include "../include/persona.h"
#include <cstring>
#include <iostream>

using namespace std;

Persona :: Persona() {

    this->id = 0;
    this->nombre[0] = '\0';

}

Persona :: Persona(int id, const char* nombre) {

    this->id = id;
    strncpy(this->nombre, nombre, 49);
    this->nombre[49] = '\0';

}

Persona :: Persona(const Persona& nuevo) {

    this->id = nuevo.id;

    strncpy(this->nombre, nuevo.nombre, 49);
    this->nombre[49] = '\0';

}

Persona :: ~Persona() {

    // Destructor

}

int Persona :: obtenerId() const { 

    return this->id; 

}
const char* Persona::obtenerNombre() const { 
    return this->nombre; 
}


float Persona::calcularDesempeno() const {
    return 0.0f;
}