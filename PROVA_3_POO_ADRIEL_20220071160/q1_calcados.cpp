#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class fornecedor{
    string nome, cnpj;

public:
    fornecedor(const string& n, const string& c): nome(n), cnpj(c){}
 
 // getters e setters
};

class calcado{
    string marca, modelo, cor;
    int tamanho;
    double preco;
    fornecedor* forn;

public:
    calcado(const string& ma, const string& mo, const string& co, int tam, double p):
    marca(ma), modelo(mo), cor(co), tamanho(tam), preco(p){}

    ~calcado(){}

    // getters e setters

    string get_marca()  {
        return marca;
    }
    void set_marca(const string& ma) {
        marca = ma;
    }

    string get_modelo()  {
        return modelo;
    }
    void set_modelo(const string& mo) {
        modelo = mo;
    }

    string get_cor()  {
        return cor;
    }
    void set_cor(const string& co) {
        cor = co;
    }

    int get_tamanho()  {
        return tamanho;
    }
    void set_tamanho(int tam) {
        tamanho = tam;
    }

    double get_preco()  {
        return preco;
    }
    void set_preco(double p) {
        preco = p;
    }

    fornecedor* get_fornecedor()  {
        return forn;
    }
    void set_fornecedor(fornecedor* f) {
        forn = f;
    }


    //metodo virtual
    virtual void print_info(){
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Cor: " << cor << endl;
        cout << "Preco: " << preco << endl;
    }


};

class tenis: public calcado{
    string tipo_esporte;

public:
    tenis(const string& ma, const string& mo, const string& co, int tam, 
    double p, const string&  te): calcado(ma,mo,co,tam,p),tipo_esporte(te){}

    string get_tipo_esporte(){
        return tipo_esporte;
    }

    void set_tipo_esporte(const string& te){
        tipo_esporte = te;
    }

    //metodo virtual
    //override no print_info de calcado
    void print_info(){
        calcado::print_info();
        cout << "Tipo de esporte: " << tipo_esporte << endl;
    }
};

class sapato_social: public calcado{
    string material;
public:
    sapato_social(const string& ma, const string& mo, const string& co, int tam, 
    double p, const string&  mt): calcado(ma,mo,co,tam,p),material(mt){}

    string get_material(){
        return material;
    }

    void set_material(const string& mt){
        material = mt;
    }

    //metodo virtual
    //override no print_info de calcado
    void print_info(){
        calcado::print_info();
        cout << "Material " << material << endl;
    }

};

//template para aceitar estoques de diferentes tipos de calcados

template <typename T>
class estoque{

    vector<T*> calcados;
    double total = 0; //valor total

public:

    //construtor
    estoque(){}

    //destrutor
    ~estoque(){
        for(T* calcado: calcados){
            delete calcado;
        }
    }

    void add_calcado(T* calcado){
        calcados.push_back(calcado);
    }

    void remover_calcado(T* calcado){
        //função da biblioteca algorithm para achar o calcado
        auto it = find(calcados.begin(), calcados.end(), calcado); 
        if( it != calcados.end()){
            calcados.erase(it);
        }
    }

    

    double valor_total(){
        for ( T* calcado: calcados){
            total += calcado->get_preco();
        }
        return total;
    }

    //void listar

    


};



class fabrica{
    //vetores para as outras classes
    map<string, fornecedor*> fornecedores;


    //instancia unica de fabrica
    static fabrica* _instance;

    //instancias de estoque
    estoque<sapato_social> estoque_social;
    estoque<tenis> estoque_tenis;

    fabrica(){} // construtor privado
    

public:
    //metodo para obter instancia unica
    static fabrica* get_instance(){
        if (_instance == nullptr){
            _instance = new fabrica();
        }
        return _instance;
    }

    // destrutor
    ~fabrica(){
        for(auto& f: fornecedores){
            delete f.second;
    } 
    }

    //criando instancias dos estoques dentro da classe
    estoque<sapato_social> get_estoque_social(){
        return estoque_social;
    }

    estoque<tenis> get_estoque_tenis(){
        return estoque_tenis;
    }

};

//inicializacao da instancia unica
fabrica* fabrica::_instance = nullptr;

//mensagem do tratamento de excecao 
class calcado_exception{
    string msg;

public:
    calcado_exception(const string& m): msg(m){}
    void print_info(){
        cout << msg << endl;
    }
};


tenis* create_tenis(){
    string marca, modelo, cor;
    int tamanho;
    double preco;
    string tipo_esporte;

    cout << "Digite a marca do calcado: ";
    cin >> marca;

    cout << "Digite o modelo do calcado: ";
    cin >> modelo;

    cout << "Digite a cor do calcado: ";
    cin >> cor;

    cout << "Digite o tamanho do calcado: ";
    cin >> tamanho;

    cout << "Digite o tipo de esporte do calcado: ";
    cin >> tipo_esporte;

    cout << "Digite o preco do calcado: ";
    cin >> preco;

    

    //tratamento de excecao onde preco tem q ser positivo
    if(preco <= 0){
        throw new calcado_exception("preco");
    }



}

int main(){

fabrica* fab;
fab = fabrica::get_instance();


//instanciando estoques
estoque<sapato_social> estoque_social = fab->get_estoque_social();
estoque<tenis> estoque_tenis = fab->get_estoque_tenis();

    sapato_social* calcado1 = new sapato_social("puma", "mod1","preto",44, 385.70, "couro");
    sapato_social* calcado2 = new sapato_social("hh", "mod2","marrom",42, 499.99, "couro");
    tenis* calcado3 = new tenis("nike", "air", "verde",39,320.00,"volei");
    
    // Adicione os calcados ao estoque
    estoque_social.add_calcado(calcado1);
    estoque_social.add_calcado(calcado2);
    estoque_tenis.add_calcado(calcado3);

    //tratamento de excecoes teste

    insert_test:
    try{
        tenis* calcado4 = create_tenis();
        estoque_tenis.add_calcado(calcado4);

    } catch (calcado_exception estoque_tenis){
        cout << "Erro ao add tenis: ";
        estoque_tenis.print_info();
        goto insert_test;
    }
    


    return 0;




}



