#ifndef DTPERRO
#define DTPERRO

#include "RazaPerro.h"
#include "DtMascota.h"
#include <iostream>

using namespace std;

class DtPerro : public DtMascota{
  private:
    RazaPerro raza;
    bool vacunaCachorro;
  public:
    DtPerro();
    DtPerro(string nombre, Genero genero, float peso, RazaPerro raza, bool vacunaCachorro);
    RazaPerro getRaza();
    bool getVacunaCachorro();
    ~DtPerro();

    friend ostream& operator<<(ostream& os, const DtPerro& perro);
};

#endif
