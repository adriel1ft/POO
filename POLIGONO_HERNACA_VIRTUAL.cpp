/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;
using QTD_ANIMAIS = 3;

class poligono{ //classe ascendente
//n tem construtor
public:
virtual float area() = 0;
virtual void desenha() = 0;//definir metodos q podem ser sobrepostos, ligacao dinamica
};

class circulo: public poligono { //classe descendente
    float raio;

circulo(float r) : raio(r){}
float get_raio(){return raio;}

void set_raio(float r){ raio = r;}
float area(){
    return (PI* (raio*raio));
}
void desenha(){
cout << "circulo: " << raio << endl;
    
}
};

class retangulo: public poligono { //classe descendente
    float base, altura;
public:
    retangulo(float b, float a): base(b), altura(a){}
    
     float get_base(){
        return base;
    }
    
    void set_base(float b){
        base = b;
    }
    
    float get_altura(){
        return altura;
    }
    void set_altura(float a){
        altura = a;
    }
    float area(){
        return base*altura
    }
};

class triangulo: public poligono { //classe descendente
    float base, altura;
public:
    triangulo(float b, float a): base(b), altura(a){} //constructor
    
    float get_base(){
        return base;
    }
    
    void set_base(float b){
        base = b;
    }
    
    float get_altura(){
        return altura;
    }
    void set_altura(float a){
        altura = a;
    }
    float area(){
        return (base*altura)/2
    }
    virtual void desenha(){
        cout << "triangulo: " << base << endl;
        cout << altura << endl;
    }
    
};

int main()
{
    //animal a1(10); //vai dar errado
    poligono* v[QTD_POLIGONO];  
    
    for(int i = 0; i < QTD_ANIMAIS; i++ ){
        int read;
        cout << "Digite 1 para retangulo, 2 para triangulo: ";
        cin >> read;
        
        if(read == 1){
            int id, la;
            cout << "Digite a idade do retangulo: ";
            cin >> id;
            cout << "Digite o valvulas do retangulo: ";
            cin >> la;
            zoo[i] = new retangulo(id, la);
        }
    }
    
    
    

    return 0;
}