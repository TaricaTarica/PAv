#ifndef DTGATO
#define DTGATO

#include "DtMascota.h"
#include "TipoPelo.h"
#include <iostream>

using namespace std;

class DtGato : public DtMascota{
private:
  TipoPelo tipoPelo;
public:
  DtGato();
  DtGato(string nombre, Genero genero, float peso, TipoPelo tipoPelo);
  TipoPelo getTipoPelo();
  ~DtGato();

  friend ostream& operator<<(ostream& os, const DtGato& gato);
};

#endif
