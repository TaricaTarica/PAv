#include "Interfaz/ICtrlUsuario.h"
#include "Fabrica.h"
#include "DT/Direccion.h"
#include "DT/DtCine.h"
#include <iostream>
#include <list>
#include <string>
#include "colormod.h"

using namespace std;

void menu();
void iniciarSesion();
void altaCine();
void altaFuncion();
void crearReserva();
void puntuarPelicula();
void comentarPelicula();
void eliminarPelicula();
void verInfoPelicula();
void verComentariosPelicula();

int main(){
  //creación de fabrica e icontroladores
  Fabrica* fab = Fabrica::getInstancia();
  ICtrlUsuario* iuser = fab->getICtrlUsuario();
  //Cargar usuarios al sistema
  iuser->cargarUsuarios();

  int opcion;
  while(1){
    menu();
    cin >> opcion;
    switch(opcion){
      case 1:
        iniciarSesion();
        break;
      case 2:
        altaCine();
        break;
      case 3:
        altaFuncion();
        break;
      case 4:
        crearReserva();
        break;
      case 5:
        puntuarPelicula();
        break;
      case 6:
        comentarPelicula();
        break;
      case 7:
        eliminarPelicula();
        break;
      case 8:
        verInfoPelicula();
        break;
      case 9:
        verComentariosPelicula();
        break;
      case 0:
        system("make clean"); //!Por conveniencia
        system("clear");
        exit(0);
        break;
      default:
        cout << "La opción ingresada no es correcta";
    }
  }
}

void menu(){
  string user;
  Fabrica* fab = Fabrica::getInstancia();
  ICtrlUsuario* iuser = fab->getICtrlUsuario();
  if (iuser->checkSesion()){
    user = iuser->getUsuarioSesion();
  }
  else user = "ANONIMO.";
  system("clear");
  Color::Modifier r(Color::FG_RED);
  Color::Modifier b(Color::FG_BLUE);
  Color::Modifier y(Color::FG_YELLOW);
  Color::Modifier d(Color::FG_DEFAULT);

  if (iuser->checkSesionAdmin()) Color::Modifier x(Color::FG_DEFAULT);
  else Color::Modifier x(FG_RED);

  cout <<b<<"    ╔═════════════════════════════════════════════════════╗"<<endl;
  cout <<"    ║"<<y<<"    ▂▂▃▃▅▅▇▇██▓▓▒▒░░  MENU CINE  ░░▒▒▓▓██▇▇▅▅▃▃▂▂    "<<b<<"║    "<<endl;
  if (iuser->checkSesion()){
  cout <<"╔═══╩═════════════════════════════════════════════════════╩═══╗"<<endl;
  cout <<"║"<<d<<"      Sesion inciada como:    "<<b<<" "<<d<<"\t"<<user<<" "<<"\t      "<<b<<"║"<<endl;
  cout <<"╠══════════════════════════════╦══════════════════════════════╣"<<endl;}
  else cout <<"╔═══╩══════════════════════════╦══════════════════════════╩═══╗"<<endl;
  cout <<"║"<<d<<"       1. Iniciar Sesión      "<<b<<"║"<<x<<"         2. Alta Cine         "<<b<<"║"<<endl;
  cout <<"╠══════════════════════════════╬══════════════════════════════╣"<<endl;
  cout <<"║"<<x<<"        3. Alta Función       "<<b<<"║"<<d<<"        4. Crear Reserva      "<<b<<"║"<<endl;
  cout <<"╠══════════════════════════════╬══════════════════════════════╣"<<endl;
  cout <<"║"<<d<<"       5. Puntuar Película    "<<b<<"║"<<d<<"     6. Comentar Película     "<<b<<"║"<<endl;
  cout <<"╠══════════════════════════════╬══════════════════════════════╣"<<endl;
  cout <<"║"<<x<<"      7. Eliminar Película    "<<b<<"║"<<d<<"    8. Ver Info de Película   "<<b<<"║"<<endl;
  cout <<"╠══════════════════════════════╩══════════════════════════════╣"<<endl;
  cout <<"║"<<d<<"           9. Ver Comentarios y Puntajes de Película         "<<b<<"║"<<endl;
  cout <<"╠═════════════════════════════════════════════════════════════╣"<<endl;
  cout <<"║"<<y<<"█▄█▀█▄█▀█▄█▀█▄█▀█▄█▀█▄    0. Salir     ▄█▀█▄█▀█▄█▀█▄█▀█▄█▀█▄█"<<b<<"║"<<endl;
  cout <<"╚═════════════════════════════════════════════════════════════╝"<<d<<endl;
  cout <<"Seleccione una opcion: ";
}

void iniciarSesion(){
  Fabrica* fab = Fabrica::getInstancia();
  ICtrlUsuario* iuser = fab->getICtrlUsuario();
  string nickname;
  string password;
  string buff;

  iuser = fab->getICtrlUsuario();
  cout << "nickname: ";
  cin >> nickname;
  iuser->ingresarNickname(nickname);
  cout << "password: ";
  cin >> password;
  if(iuser->verificarPassword(password)){
    iuser->iniciarSesion();
    cout << "Sesión iniciada correctamente para el usuario " << nickname << "\nIngrese cualquier caracter para continuar..." << endl;
    cin >> buff;
  }
  else{
    cout << "El nombre de usuario o la contraseña son incorrectos." << "\nIngrese cualquier caracter para continuar..."<< endl;
    cin >> buff;
  }
}

void altaCine(){
  Fabrica* fab = Fabrica::getInstancia();
  ICtrlCine* icine = fab->getICtrlCine();
  string buff;
  string calle;
  int numero;
  cout << "Ingrese la calle: ";
  cin >> calle;
  cout << "Ingrese el número: ";
  cin >> numero;
  Direccion dir = Direccion(calle, numero);
  icine->ingresarDireccion(dir);
  cout << "Para ingresar salas, ingrese la capacidad de una sala y presione enter.\nSi quiere dejar de ingresar salas, ingrese 0."<<endl;
  int capac = 1;
  while (capac != 0){
    cout << "Ingrese una capacidad: ";
    cin >> capac;
    icine->ingresarCapacidad(capac);
    cout << "Sala registrada." << endl;
  }
  cout << "¿Desea confirmar el alta del cine? 1: Si, 0: No"<<endl;
  bool confirmacion;
  cin >> confirmacion;
  if (confirmacion){
    icine->altaCine();
    cout << "Cine dado de alta. Ingrese cualquier caracter para continuar..."<<endl;
    cin >> buff;
  }
  else{
    icine->cancelAltaCine();
    cout << "Se ha cancelado el alta del cine. Ingrese cualquier caracter para continuar..."<<endl;
    cin >> buff;
  }
}

void altaFuncion(){
  Fabrica* fab = Fabrica::getInstancia();
  ICtrlCine* icine = fab->getICtrlCine();
  list<DtCine> cines = icine->listarIdCines();
  for(list<DtCine>::iterator it = cines.begin(); it != cines.end(); ++it){
    cout << (*it) << endl;
  }

  //cout << "Ingrese la ID del cine: "<<endl;
  //int cineid;
  string buff;
  cin>>buff;
}

void crearReserva(){}

void puntuarPelicula(){}

void comentarPelicula(){}

void eliminarPelicula(){}

void verInfoPelicula(){}

void verComentariosPelicula(){}
