#ifndef DEBITO
#define DEBITO

#include "Reserva.h"

using namespace std;

class Debito: public Reserva{
  private:
    string banco;
  public:
    Debito();
    Debito(int,float,int,string);
    void setBanco(string);
    string getBanco();
    ~Debito();
};

#endif
