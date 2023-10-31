#include <iostream>
#include <string>
//#include <map>
//#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::endl;
//using std::map;
//using std::vector;

class pagamento{

    double valor;
    string data;
    string num_cartao;

    pagamento(){
        valor = 0.0;
        data = "";
        num_cartao = "";     
    }

public:
    pagamento(double v, const string& d, const string& n): valor(v), data(d), num_cartao(n){}


    double get_valor(){
        return valor;
    }

    string get_data(){
        return data;
    } 

    string get_num_cartao(){
        return num_cartao;
    }

    void set_valor(double v){
        valor = v;
    }

    void set_data(const string& d){
        data = d;
    }

    void set_num_cartao(const string& n){
        num_cartao = n;
    }
    /*static pagamento& getInstance(){
        static pagamento instance;
        return instance;   
        }*/

    

};

class pagamento_online: public pagamento{
    string nome_site;
    int codigo_seg;

public:
    pagamento_online(double v, const string& d, const string& n, const string& ns, int cs):pagamento(v,d,n), nome_site(ns), codigo_seg(cs){}

    string get_nome_site(){
        return nome_site;
    }

    int get_codigo_seg(){
        return codigo_seg;
    }

    void set_nome_site(const string& ns){
        nome_site = ns;
    }

    void set_codigo_seg(int cs){
        codigo_seg = cs;
    }

};

class pagamento_presencial: public pagamento{
    string nome_loja;

public:
    pagamento_presencial(double v, const string& d, const string& n,const string& nj):pagamento(v,d,n), nome_loja(nj){}

    string get_nome_loja(){
        return nome_loja;
    }

    void set_nome_site(const string& nj){
        nome_loja = nj;
    }

};

template <typename T>
class fatura{
    double limite_credito;
    vector<T> pagamentos;

    public:

    fatura(double lc):limite_credito(lc){
    
        /*vetor vazio do tipo T -> tipo do pagamento
        especificado qnd vc criar uma instancia da classe fatura
        dessa forma eu posso escolher se vem de pgmt  online ou presencial*/
        
        pagamentos = vector<T>(); 

    }

    double get_limite_credito(){
        return limite_credito;
    }

    void set_limite_credito(double lc){
        limite_credito = lc;
    }

    void add_pagamento(T* pagamento){
        pagamentos.push_back(pagamento);
        limite_credito += pagamento;
    }

    double calcular_valor_total() const {
        double total = 0;
        for (const T& p: pagamentos){
            total += p.get_valor();
        }
        return total;

    }

    //listar pagamentos dps eu faço
    void listar_pagamentos(){
        cout << "Lista de pagamentos: " << endl;
        for(const T* p : pagamentos){
            cout << "Valor: " << p->valor;
            cout << "Data: " << p->data;
            cout << "Numero do Cartao: " << p->num_cartao;
        }
    }

    friend ostream& operator<<(ostream& os, const fatura& f){
        os << "Fatura: " << f.get_limite_credito();
        os << f.listar_pagamentos;
        return os;
    }



    fatura& operator+(const T* pagamento){
        pagamentos.push_back(p);
        return *this;
    }

    fatura& operator-(const T* pagamento){
        auto it = find(pagamentos.begin(), pagamentos.end(), pagamento);
        if(it != pagamentos.end()){
            pagamentos.erase(it);
        }
        return *this;
    }

    //tratamento de excecoes
    try{
        fatura + pagamento1;

    } cat

};


/*perguntas pro prof
os pagamentos podem ser de cartoes diferentes*/