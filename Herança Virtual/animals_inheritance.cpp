#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class animal{
    string nome;
    int idade;
protected:
    int codigo; //esse codigo eh do q?
public:
    animal(const string& n, int i){
        nome = n;
        idade = i;
        codigo =0;
    }

    string get_nome(){return nome;}
    void set_nome(const string& n){
        nome = n;
    }

    int get_idade(){return idade;}
    void set_idade(int i){
        idade = i;
    }

    int get_codigo(){
        return codigo;
    }

    void print_info(){
        cout << "animal" << endl;
        cout << "nome: " << nome << endl;
        cout << "idade: " << idade << endl;
    }

};

class ave: public animal{
    float envergadura;  //atributo privado (particular) das aves      
public:
    ave(const string& n, int i, float e) : animal(n, i){
        envergadura = e;
        codigo = 1;
    }
    float get_envergadura(){return envergadura;}
    void set_envergadura(float e){
        envergadura = e;
    }
};

class mamifero: public animal {
    int pelagem;
public:
    mamifero(const string &n, int i, int p) : animal(n,i){
        pelagem = p;
        codigo = 2;
    }
    int get_pelagem(){return pelagem;}
    void set_pelagem(int p){
        pelagem = p;
    }
    void print_info(){
        cout << "mamifero" << endl;
        animal::print_info(); //já vai printar os atributos básicos a todos os animais
        cout << "pelagem: " << pelagem << endl;
    }
};

int main(){

    return 0;
}

