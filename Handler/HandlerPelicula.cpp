#include <map>
#include <list>
#include "HandlerPelicula.h"

HandlerPelicula* HandlerPelicula::instancia = NULL;

HandlerPelicula::HandlerPelicula(){}

HandlerPelicula* HandlerPelicula::getInstancia(){
  if(instancia == NULL){
    instancia = new HandlerPelicula();
  }
  return instancia;
}

list<Pelicula*> HandlerPelicula::getPeliculas(){
  list<Pelicula*> pelis;
  for (map<string,Pelicula*>::iterator it = this->peliculas.begin(); it != this->peliculas.end(); ++it)
    pelis.push_back(it->second);
  return pelis;
}

Pelicula* HandlerPelicula::buscarPelicula(string ttl){
  map<string,Pelicula*>::iterator it = this->peliculas.find(ttl);
  return it->second;
}

void HandlerPelicula::addPelicula(Pelicula* peli){
  this->peliculas.insert(std::pair<string,Pelicula*>(peli->getTitulo(), peli));
}

bool HandlerPelicula::existePelicula(string ttl){
  return this->peliculas.count(ttl);
}

void HandlerPelicula::eliminarPelicula(string ttl){
  map<string,Pelicula*>::iterator it = this->peliculas.find(ttl);
  this->peliculas.erase(it);
}

HandlerPelicula::~HandlerPelicula(){}
