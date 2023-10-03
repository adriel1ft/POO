#include <iostream>

using std::cout;
using std::endl;
using std::string;

class excecao_conta{
    string msg;

public:
    excecao_conta(const string& s){
        msg = s;
    }
    
    string get_msg(){return msg;}
    
    virtual void print_info() = 0;
};

class excecao_saldo: public excecao_conta{
    float excedente;
public:
    excecao_saldo(const string& s, float v): excecao_conta(s), excedente(v){}
    
    void print_info(){
        cout << "Excecao: Saldo insuficiente!" << endl;
        cout << "MSG: " << get_msg() << endl;
        cout << "Codigo: " << codigo << endl;
    }
};

class excecao_valor: public excecao_saldo{
    int codigo;
    
    
};

class conta_corrente{
    float saldo;
public:
    void sacar(float v){
            if (v <= saldo){
                saldo -=v;
            else
                throw new excecao_saldo("INS", (saldo-v))
                
            }
    }
    
    void depositar(float v){
        saldo += v;
    }
}

//captura o ponteiro pra classe qnd ascendente