#include "../include/estudiante.h"
#include <iostream>
#include <cstring>

using namespace std;

Estudiante :: Estudiante() : Persona() {

    carrera[0] = '\0';
    ciclo = 1;
    cantidadCursos = 0;

}

Estudiante :: Estudiante(int id, const char* nombre, const char* carrera, int ciclo) : Persona(id, nombre) {

    strncpy(this->carrera, carrera, sizeof(this->carrera) - 1); 
    this->carrera[sizeof(this->carrera) - 1] = '\0';
    this->ciclo = ciclo;
    cantidadCursos = 0;

}

Estudiante :: Estudiante(const Estudiante& nuevo) : Persona(nuevo) {

    strncpy(this->carrera, nuevo.carrera, sizeof(this->carrera) - 1);
    this->ciclo = nuevo.ciclo;
    this->cantidadCursos = nuevo.cantidadCursos;
    for(int i = 0; i < MAX_CURSOS; i++) {
        this->cursos[i] = nuevo.cursos[i]; 
    }

}

Estudiante :: ~Estudiante() {

    // Destructor
     
}

bool Estudiante :: agregarCurso(const Curso& NuevoCurso, float ep, float ef, float pp) {
    if (cantidadCursos >= MAX_CURSOS) {
        cout << "Se alcanzo el limite de cursos.\n";
        return false;
    }

    cursos[cantidadCursos] = NuevoCurso;

    cursos[cantidadCursos].GuardarNotas(ep, ef, pp);

    cantidadCursos++;

    return true;

}

bool Estudiante :: actualizarNotas(const char* codCurso, float ep, float ef, float pp) {

    for(int i = 0; i < cantidadCursos; i++) {
        if(strcmp(cursos[i].obtenerCodigo(), codCurso) == 0) {
            cursos[i].GuardarNotas(ep, ef, pp);
            return true; 
        }
    }
    return false;

}

int Estudiante :: calcularTotalCreditos() const {

    int credtot = 0;
    for(int i=0; i<cantidadCursos; i++) 
    credtot += cursos[i].obtenerCreditos();
    return credtot;

}

int Estudiante :: obtenerCantidadCursos() const { 
    return cantidadCursos; 
}

const Curso& Estudiante :: obtenerCurso(int i) const { 
    return cursos[i]; 
}

const char* Estudiante :: obtenerCarrera() const { 
    return carrera; 
}

int Estudiante :: obtenerCiclo() const { 
    return ciclo; 
}

void Estudiante :: mostrarInfo() const {
    cout << "Codigo: " << id << " | " << nombre << " | " << carrera << endl;
}

float Estudiante :: calcularDesempeno() const {

    if (cantidadCursos == 0) 
    return 0.0f;
    
    float suma = 0;
    int totalCred = 0;

    for(int i=0; i<cantidadCursos; i++) {
        suma += cursos[i].calcularPromedio() * cursos[i].obtenerCreditos();
        totalCred += cursos[i].obtenerCreditos();
    }
    
    if (totalCred > 0) {

        return suma / totalCred;

    } else {

        return 0.0f; 
    
    }

}