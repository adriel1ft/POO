#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;

class funcionario{
    string nome;
    int idade;
public:
    funcionario(const string& n, int i): nome(n), idade(i){}

    string get_nome(){return nome;}
    void set_nome(const string& n){nome = n;}
    int get_idade(){return idade;}
    void set_idade(int i){idade = i;}

    virtual void exibir() = 0;

};

class gerente: public funcionario{
    string departamento;
    string nivel_acesso;

    gerente(const string& n,)
};

class desenvolvedor{};

class analista{};

class funcionario_estagiario{};

int main(){

    return 0;
}