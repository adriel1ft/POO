#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ponto {
    double x,y;

    public:
        ponto(double xx, double yy): x(xx), y(yy){}

double get_x(){return x;}
void get_x(double xx){ x = xx;}
double get_y(){ return y;}
void get_y(double yy){ y = yy;}

void print_info(){
    cout << "ponto(" << x << ", " << y << ")" << endl;
}

ponto operator+(ponto& outro){
    double xr = x + outro.x;
    double yr = y + outro.y;
    return ponto(xr, yr); //alocando no operador
}

ponto operator-(ponto& outro){
    double xr = x - outro.x;
    double yr = y - outro.y;
    return ponto(xr, yr); //alocando no operador
}

bool operator ==(ponto& outro){
    return ((x == outro.x) && (y == outro.y));
}

bool operator !=(ponto& outro){
    return ((x != outro.x) && (y != outro.y));
}

friend ostream& operator<<(ostream os, const ponto& p){
    os << "x: " << ", " << "y: " << p.y << endl;
    return os;
}
};



int main()
{
    ponto a(10,20), b(20,30), c(40,50), d(50,60), k(10,11);

    ponto e = a + b;
    //ponto e = a.operabor(b)

    ponto f = d - c;
    //ponto f = d.operabor(c)

    //nao esqiueca os parenteses
    e.print_info();
    f.print_info();


   if (f == k){
       cout << "ponto f == k" << endl;
       cout << "ponto k: ";
       k.print_info();
   } else {
       cout << "ponto f != k" << endl;
       cout << "ponto k: ";
        k.print_info();

   }

   cout << "Ponto A" << a << endl;
   cout << b << endl;
   cout << c << endl;


    return 0;
}
