#ifndef PERSONA_H
#define PERSONA_H

class Persona {
protected:

    int id;             
    char nombre[50];    

public:
   
    Persona();
    Persona(int id, const char* nombre);
    Persona(const Persona& nuevo);

    virtual ~Persona();

    int obtenerId() const;
    const char* obtenerNombre() const;
   
    virtual void mostrarInfo() const = 0;
    virtual float calcularDesempeno() const;
    
};

#endif