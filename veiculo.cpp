/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;
using QTD_ANIMAIS = 3;

class veiculo{ //classe ascendente

virtual void print() = 0; //definir metodos q podem ser sobrepostos, ligacao dinamica
};

class carro: public veiculo { //classe descendente
    int valvulas;
    int qtd_valvulas;
public:
    carro(int a, int q): veiculo(a){
        qtd_valvulas = q;
        valculas = new int [q];
    }
    ~carro(){
        delete valvulas;
    }
    int* get_valvulas(){
        return valvulas;
    }
    
    int get_valvula(int idx){
        if (idx < qtd_valvulas){
            return valvulas[idx];
        } else {
            return -1;
        }
    }
    void set_valvulas(int l){
        valvulas = l;
    }
    virtual void fazer_barulho(){
        cout << "carro latindo: " << valvulas << endl;
    }
};

class lancha: public veiculo { //classe descendente
    int miado;
public:
    gato(int i, int m): animal(i), miado(m){} //constructor
    
    int get_miado(){
        return miado;
    }
    
    void set_miado(int m){
        miado = m;
    }
    virtual void fazer_barulho(){
        cout << "gato miando: " << miado << endl;
    }
    
};

int main()
{
    //animal a1(10); //vai dar errado
    veiculo* v[QTD_VEICULOS];  
    
    for(int i = 0; i < QTD_ANIMAIS; i++ ){
        int read;
        cout << "Digite 1 para carro, 2 para gato: ";
        cin >> read;
        
        if(read == 1){
            int id, la;
            cout << "Digite a idade do carro: ";
            cin >> id;
            cout << "Digite o valvulas do carro: ";
            cin >> la;
            zoo[i] = new carro(id, la);
        }
    }
    
    
    

    return 0;
}