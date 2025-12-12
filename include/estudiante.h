#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "persona.h"
#include "curso.h"

const int MAX_CURSOS = 5;

class Estudiante : public Persona {
private:

    char carrera[50];
    int ciclo;
    Curso cursos[MAX_CURSOS]; 
    int cantidadCursos;

public:

    Estudiante();
    Estudiante(int id, const char* nombre, const char* carrera, int ciclo);
    Estudiante(const Estudiante& nuevo); 
    ~Estudiante() override;

    bool agregarCurso(const Curso& NuevoCurso, float ep, float ef, float pp);
    bool actualizarNotas(const char* codCurso, float ep, float ef, float pp);
    int calcularTotalCreditos() const;

    int obtenerCantidadCursos() const;
    const Curso& obtenerCurso(int indice) const;
    const char* obtenerCarrera() const;
    int obtenerCiclo() const;

    void mostrarInfo() const override;
    float calcularDesempeno() const override;

};

#endif