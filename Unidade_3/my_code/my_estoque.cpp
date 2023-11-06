#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class produto{
    string nome;
    T descricao;
    int num_serie;
    float preco;
    int qtd_estoque;

public:
    produto(const string& no, T desc, int ns, float p, int q): nome(no), descricao(desc), num_serie(ns), preco(p), qtd_estoque(q) {}

    void print_info(){
        cout << "produto" << endl;
        cout << "nome: " << nome << " | " << endl;
        cout << "descricao: " << descricao << endl;
        cout << "N/S: " << num_serie << " | " << endl;
        cout << "preco: " << preco <<
    }

    float get_preco(){
        return preco;
    }

    void set_preco(float p){
        preco = p;
    }

    int get_qtd_estoque(){
        return qtd_estoque;
    }

    void add_estoque(int q){
        qtd_estoque += q;
    }

    
    void vender(int q){
        qtd_estoque -= q;
    }
};

class gerenciador_estoque{
    int qtd_produto;
    float valor_total;
    produto <string*> mais_caro;
    vector<produto<string>*> estoque;
    static gerenciador_estoque* _instance;
};