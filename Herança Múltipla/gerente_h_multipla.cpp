#include <iostream>

using std::cout;
using std::endl;

class vendedor{
    double meta;

public:
    vendedor(double m): meta(m){}

    double get_meta(){ return meta; }
    void set_meta(double m){ meta = m; }

    void print_info() {
		cout << "vendedor" << endl;
		cout << "meta: " << meta << endl;
	}

};

class gerente{
    int departamento; //codigo do departamento referente ao gerente
public:
    gerente(int d): departamento(d){}

    int get_codigo(){return departamento;}
    void set_codigo(int d){departamento = d;}

void print_info() {
		cout << "gerente" << endl;
		cout << "departamento: " << departamento << endl;
	}
};

class vendedor_gerente: public vendedor, public gerente{
    int codigo;

public:
    vendedor_gerente(int c, double m, int d): codigo(c),gerente(d),vendedor(m){}

    int get_codigo(){ return codigo;}
    void set_codigo(int c){ codigo = c;}

    void print_info(){
        cout << "gerente/vendedor" << endl;
        gerente::print_info();
        vendedor::print_info();
    }


};

int main(){
    vendedor_gerente vg1(123,1500.00,889);
    vg1.print_info();


    return 0;
}