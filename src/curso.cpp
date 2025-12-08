#include "../include/curso.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

Curso :: Curso() {
    codigo[0] = '\0';
    nombre[0] = '\0';
    creditos = 0;
}

Curso :: Curso(const char* codigo, const char* nombre, int creditos) {

    strncpy(this->codigo, codigo, sizeof(this->codigo) - 1); 
    this->codigo[sizeof(this->codigo) - 1] = '\0'; 

    strncpy(this->nombre, nombre, sizeof(this->nombre) - 1); 
    this->nombre[sizeof(this->nombre) - 1] = '\0';

    this->creditos = creditos;

}


Curso :: Curso(const Curso& nuevo) {

    strncpy(this->codigo, nuevo.codigo, sizeof(this->codigo) - 1); 
    this->codigo[sizeof(this->codigo) - 1] = '\0';

    strncpy(this->nombre, nuevo.nombre, sizeof(this->nombre) - 1); 
    this->nombre[sizeof(this->nombre) - 1] = '\0';

    this->creditos = nuevo.creditos;
    this->notas = nuevo.notas; 

}

Curso :: ~Curso() {

    // Destructor

}

const char* Curso :: obtenerCodigo() const { 
    return codigo; 
}

const char* Curso :: obtenerNombre() const { 
    return nombre; 
}

int Curso :: obtenerCreditos() const { 
    return creditos; 
}

float Curso :: obtenerEP() const { 
    return notas.EP; 
}

float Curso :: obtenerEF() const { 
    return notas.EF; 
}

float Curso :: obtenerPP() const { 
    return notas.PP; 
}

void Curso :: GuardarNotas(float ep, float ef, float pp) {

    notas.EP = ep;
    notas.EF = ef;
    notas.PP = pp;

}

float Curso :: calcularPromedio() const {
    return (notas.EP * 0.3f) + (notas.EF * 0.5f) + (notas.PP * 0.2f);
}

const char* Curso :: obtenerEstado() const {
    return (calcularPromedio() >= 10.5f) ? "Aprobado" : "Desaprobado";
}
