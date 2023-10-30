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

class pagamento{

    double valor;
    string data;
    string num_cartao;

    pagamento(){
        valor = 0.0;
        data = "";
        num_cartao = "";


        
    }


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
    /*static pagamento& getInstance(){
        static pagamento instance;
        return instance;   
        }*/

    

};

class pagamento_online: public pagamento{
    string nome_site;
    int codigo_seg;

};

class pagamento_presencial: public pagamento{
    string nome_site;
    int codigo_seg;

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

    void add_pagamento(pagamento* p){
        pagamentos.push_back(p);
    }

    double calcular_valor_total() const {
        double total = 0;
        for (const T& p: pagamentos){
            total += p.get_valor();
        }
        return total;

    }

    //listar pagamentos

};