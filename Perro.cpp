#include "Perro.h"

Perro::Perro(){}
Perro::Perro(string nombre, Genero genero, float peso, RazaPerro raza, bool vacunaCachorro):Mascota(nombre,genero,peso){
  this->raza=raza;
  this->vacunaCachorro=vacunaCachorro;
}
RazaPerro Perro::getRaza(){
  return this->raza;
}
bool Perro::getVacunaCachorro(){
  return this->vacunaCachorro;
}
void Perro::setRaza(RazaPerro raza){
  this->raza=raza;
}
void Perro::setVacunaCachorro(bool vacunaCachorro){
  this->vacunaCachorro=vacunaCachorro;
}
Perro::~Perro(){}
float Perro::obtenerRacionDiaria(){
  return(getPeso()*0.025);
}
