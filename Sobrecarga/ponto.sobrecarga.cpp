#include <iostream>
#include <string>

using std::cout;
using std::ostream; //ver pra q serve
using std::endl;

class ponto{
    double x;
    double y;
public: //n esqueca isso
    ponto(double xx, double yy): x(xx), y(yy){}

    double get_x(){ return x;}
    double get_y(){ return y;}
    void set_x(double xx){ x = xx; }
    void set_y(double yy){ y = yy; }

    void print_info(){
        cout << "ponto (" << x << ", " << y << ")" << endl;
    }

    //Agora vamos fazer os operadores

    ponto operator+(const ponto& outro){
        double xr = x + outro.x;
        double yr = y + outro.y;
        return ponto(xr, yr);
    }

    ponto operator-(const ponto& outro){
        double xr = x - outro.x;
        double yr = y - outro.y;
        return ponto(xr, yr);
    }

    bool operator==(const ponto& outro) const {
        return ((x == outro.x) && (y == outro.y));
    }

    bool operator!=(const ponto& outro){
        return ((x != outro.x) || (y != outro.y));
    }

    //a função amiga ajuda a gente a acessar membros privados da classe ponto
    friend ostream& operator<<(ostream& os, const ponto& p){
        os << "x: " << p.x << ", y: " << p.y << endl;
        return os;
    }

};

void comparacao(const ponto& p1, const ponto& p2, const std::string& nome1, const std::string& nome2){
    if(p1 == p2){
        cout << nome1 << " eh igual a " << nome2 << endl;
    } else {
        cout << nome1 << " eh diferente de " << nome2 << endl;
    }
    cout << endl;
    cout << nome1 << " = " << p1 << endl;
    cout << nome2 << " = " << p2 << endl;
}



int main(){

    //criacao de objetos da classe ponto

    ponto a(1,2), b(10,10), c(25,25), d(5,6), e(5,4);

    ponto f = d + e;

    //cout << f;

    comparacao(a,b,"a","b");

    cout << "ponto d: "<< d << endl;
    cout << "ponto e: "<< e << endl;
    cout << "ponto f: "<< f << endl;

    return 0;
}