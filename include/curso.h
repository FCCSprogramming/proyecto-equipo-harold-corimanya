#ifndef CURSO_H
#define CURSO_H

struct Notas {
    float EP; // 30%
    float EF; // 50%
    float PP; // 20%
    Notas() : EP(0), EF(0), PP(0) {}
};

class Curso {
private:
    char codigo[10];
    char nombre[50];
    int creditos;
    Notas notas;

public:

    Curso();
    Curso(const char* codigo, const char* nombre, int creditos);
    Curso(const Curso& nuevo);
    ~Curso();

    const char* obtenerCodigo() const;
    const char* obtenerNombre() const;
    int obtenerCreditos() const;

    float obtenerEP() const;
    float obtenerEF() const;
    float obtenerPP() const;

    void GuardarNotas(float ep, float ef, float pp);
    float calcularPromedio() const;
    const char* obtenerEstado() const;
    

};

#endif