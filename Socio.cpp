#include "Socio.h"

Socio::Socio(){}

Socio::Socio(string ci, string n, DtFecha fi){
  this->ci=ci;
  this->nombre=n;
  this->fechaIngreso=fi;
}
Socio::Socio(string ci, string nom){
  this->ci=ci;
  this->nombre=nom;
}

string Socio::getCi(){
  return this->ci;
}
void Socio::setCi(string ci){
  this->ci=ci;
}
string Socio::getNombre(){
  return this->nombre;
}
void Socio::setNombre(string n){
  this->nombre=n;
}
DtFecha Socio::getFechaIngreso(){
  return this->fechaIngreso;
}
void Socio::setFechaIngreso(DtFecha fi){
  this->fechaIngreso=fi;
}
void Socio::setMascota(Mascota* m){
  this->mascotas[this->topeMascota] = m;
  this->topeMascota++;
}

string Socio::getMascota(int i){
  return this->mascotas[i]->getNombre();
}

Socio::~Socio(){}
