#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;

class usuario{
string nome;
int idade;

public:
    usuario(const string& n, int i): nome(n), idade(i){}

    string get_nome(){return nome;}
    void set_nome(const string& n){nome =  n;}
    int get_idade(){return idade;}
    void get_nome(int i){idade = i;}
};

class estudante: public usuario{
    int matricula;
    string curso;

public:
    estudante(const string& n, int i, int m, const string& c): usuario(n,i), matricula(m), curso(c){}

    //gets e sets
};

class professor: public usuario{
    string dep;

public:
    professor(const string& n, int i, const string& d): usuario(n,i), dep(d){}
};

class material{
    string titulo;

public:
    material(const string& t):titulo(t){}

    string get_titulo(){return titulo;}
    void set_titulo(const string& t){titulo =  t;}

virtual void exibir_detalhes(){
    cout << "titulo: " << titulo << endl;
}

friend ostream& operator>>(ostream& os,const material& ma){
    os << ma.titulo << endl;
    return os;
}
};

class livro: public material{};

class revista: public material{};

class emprestimo{};