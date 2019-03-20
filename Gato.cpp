#include "Gato.h"

Gato::Gato(){}
Gato::Gato(string nombre, Genero genero, float peso, TipoPelo tipoPelo):Mascota(nombre,genero,peso){
  this->tipoPelo=tipoPelo;
}
TipoPelo Gato::getTipoPelo(){
  return this->tipoPelo;
}
void Gato::setTipoPelo(TipoPelo tipoPelo){
  this->tipoPelo=tipoPelo;
}
Gato::~Gato(){}
float Gato::obtenerRacionDiaria(){
  return (getPeso() * 0.015);
}
