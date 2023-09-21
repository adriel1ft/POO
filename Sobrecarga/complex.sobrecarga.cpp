#include <iostream>
#include <string>
//#include <vector> fazer um vector de complex numbers

using std::cout;
using std::string;
using std::endl;
//using std::vector;

class complex{

    double real;
    double img;
public:
    complex(double r = 0.0, double i = 0.0): real(r), img(i){}

    double get_real(){return real;}
    double get_img(){return img;}
    void set_real(double r){ real = r;}
    void set_img(double i){ img = i;}

    //sobrecarga do operador de adição
    complex operator+(const complex& outro) const {
        return complex(real + outro.real, img + outro.img);
    }

      complex operator-(const complex& outro) const {
        return complex(real - outro.real, img - outro.img);
    }

    //funcao para imprimir numero complexo
    void print_info() const{
        cout << real << "+" << img << "i" << endl;
    }
};

int main(){

    complex a(2,3), b(5,1);
    a.print_info();
    b.print_info();



    return 0;
}