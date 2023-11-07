#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class uva{
    string nome;
    int safra;
    double preco_kg;

public:
    uva(const string& n, int s, double p): nome(n), safra(s), preco_kg(p){}

    string get_nome(){
        return nome;
    }

    void set_nome(const string& n){
        nome = n;
    }

    int get_safra(){
        return safra;
    }

    void set_safra(int s){
        safra = s;
    }

    double get_preco_kg(){
        return preco_kg;
    }
};

class vinho{
    string nome;
    int safra;
    double volume;
    vector<uva*> uvas; //ptr para vetor de uvas
    int qtd_vinho;

public:
    vinho(const string& n, int s, double v, int q): 
    nome(n), safra(s), volume(v),  qtd_vinho(q){}

    int get_qtd_vinho(){
        return qtd_vinho;
    }

    void set_qtd_vinho(int q) {
        qtd_vinho = q;
    }
};

class vinho_tinto: public vinho{
    float nv_tanino, qtd_polifenois;

public:
    vinho_tinto(const string& n, int s, double v, int q, float nt, float qpol):
    vinho(n,s,v,q), nv_tanino(nt) ,qtd_polifenois(qpol) {}

    //gets  sets

};

class vinho_branco: public vinho{
    string subtipo;
};

class cliente{
    string nome_cliente, sobrenome, email, tel;

public:
    cliente(const string& nc, const string& sob, const string& e, const string& t):
    nome_cliente(nc), sobrenome(sob), email(e), tel(t){}
};

//template para aceitar vendas de diferentes tipos de vinhos
template <typename T>
class venda{

    vector<cliente*> clientes;
    vector<T*> vinho;
    double total = 0; //valor total

public:
//construtor


};

class vinicola{
    //instancia unica de vinicola
    static vinicola* _instance;

    public:
    //metodo para obter instancia unica
    static vinicola* get_instance(){
        if (_instance == nullptr){
            _instance = new vinicola();
        }
        return _instance;
    }
};

template <typename N>
class vinoteca{

};

//inicializacao da instancia unica
vinicola* vinicola::_instance = nullptr;

//aqui eu faria tratamento de excecao

int main(){

    return 0;
}



