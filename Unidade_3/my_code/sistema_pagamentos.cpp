#include <iostream>
#include <string>
#include <map>
#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::vector;
using std::ostream;
using std::exception;

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

class LimiteCreditoExcedidoException: public exception{
public:
    LimiteCreditoExcedidoException() = default;

    const char* what() const throw(){ // descreve o motivo da excecao
        return "Limite de crédito excedido";
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

    

    double calcular_valor_total() const {
        double total = 0;
        for (const T& p: pagamentos){
            total += p.get_valor();
        }
        return total;

    }

    void add_pagamento(const T& pagamento){
        if (limite_credito < pagamento->get_valor() + calcular_valor_total()){
            throw (LimiteCreditoExcedidoException()); //lança a msg da excecao
    }
    pagamentos.push_back(pagamento);
    limite_credito -= pagamento.get_valor();
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
        os << "Fatura: " << f.get_limite_credito() << endl;
        os << f.listar_pagamentos;
        return os;
    }



    fatura& operator+(const T* pagamento){
        pagamentos.push_back(pagamento);
        return *this;
    }

    fatura& operator-(const T* pagamento){
        auto it = find(pagamentos.begin(), pagamentos.end(), pagamento);
        if(it != pagamentos.end()){
            pagamentos.erase(it);
        }
        return *this;
    }

    template <typename R>
    friend void transferir_pagamentos(fatura<R>& f1, fatura<R>& f2){
        for(const R* p : f1.pagamentos){
            f2.add_pagamento(p);
        }
        f1.pagamentos.clear(); // garantir que os pagamentos não sejam duplicados
            
    }


};


int main(){
    fatura<pagamento> fatura1(1500);

    //criando pagamentos
    pagamento_online pag_o1(100, "01/01/2021","Pedro", "site1",7985);
    pagamento_presencial pag_p1(700, "01/01/2021","Li", "loja1");
    pagamento_presencial pag_p2(350.50, "01/01/2021","Anna", "loja1");

    
}


/*perguntas pro prof
os pagamentos podem ser de cartoes diferentes*/
