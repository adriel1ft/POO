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

    funcionario(){ //construtor padrão
        idade = 0;
        nome = "";
    }

    virtual ~funcionario() {}

    string get_nome(){return nome;}
    void set_nome(const string& n){nome = n;}
    int get_idade(){return idade;}
    void set_idade(int i){idade = i;}

    virtual void exibir() = 0;

};

class gerente: public funcionario{
    string departamento;
    int nivel_acesso; // 1 - baixo, 2 - medio, 3 - alto
public:
    gerente(const string& no, int i, int ni, const string& dep): funcionario(no,i),departamento(dep), nivel_acesso(ni){}

    virtual ~gerente() {}

    //gets e sets
    string get_departamento(){return departamento;}
    void set_departamento(string dep){departamento = dep;}

    int get_nivel_acesso(){return nivel_acesso;}
    void set_nivel_acesso(int ni){nivel_acesso = ni;}

    void exibir() override{
        cout << "Nome: " << get_nome() << endl;
        cout << "Idade: " << get_idade() << endl;
        cout << "Departamento: " << departamento << endl;
        cout << "Nivel acesso: " << nivel_acesso << endl;
    }

    friend ostream& operator<<(ostream& os, gerente& g){
        os << "Nome: " << g.get_nome() << endl;
        os << "Idade: " << g.get_idade() << endl;
        os << "Departamento: " << g.departamento << endl;
        os << "Nivel acesso: " << g.nivel_acesso << endl;
        return os;
    }




};

class desenvolvedor: private funcionario{
    string ling;

public:
    desenvolvedor(const string& no, int i, const string& l): funcionario(no,i), ling(l){}

    //gets e sets
    string get_ling(){return ling;}
    void get_ling(string l){ ling = l;}

    void exibir() override{
        cout << "Nome: " << get_nome() << endl;
        cout << "Idade: " << get_idade() << endl;
        cout << "Linguagem de Programação: " << ling << endl;    
        }

    friend ostream& operator<<(ostream& os, desenvolvedor& d){
        os << "Nome: " << d.get_nome() << endl;
        os << "Idade: " << d.get_idade() << endl;
        os << "Linguagem de Programação: " << d.ling << endl; 
        return os;
    }


};

class analista: private funcionario{
    string projeto_atual;
public:
    analista(const string& no, int i, const string& p):funcionario(no,i),projeto_atual(p){}

    //gets e sets
    string get_ling()const{return projeto_atual;}
    void get_ling(string p){ projeto_atual = p;}

    void exibir() override{
        cout << "Nome: " << get_nome() << endl;
        cout << "Idade: " << get_idade() << endl;
        cout << "Projeto Atual: " << projeto_atual << endl;    
        }

    friend ostream& operator<<(ostream& os, analista& a){
        os << "Nome: " << a.get_nome() << endl;
        os << "Idade: " << a.get_idade() << endl;
        os << "Projeto Atual: " << a.projeto_atual << endl;  
        return os;
    }


};

class funcionario_estagiario: public desenvolvedor, public analista{
    int duracao;
public:
    funcionario_estagiario(const string& n, int i, const string& l, const string& p, int d): desenvolvedor(n,i,l), analista(n, i,p), duracao(d){} 

    //gets e sets
    int get_duracao(){return duracao;}
    void set_duracao(int d){duracao = d;}

    void exibir() override{
      cout << endl;
    analista::exibir(); //usado pois não é possivel acessar informações de funcionario
    cout << "Linguagem(s) de Programacao: " << desenvolvedor::get_ling() << endl;
    cout << "Duracao do Estagio: " << duracao << " meses" << endl;  
        }

};

int main(){

    funcionario_estagiario e1("Gabriel",19,"C++","Jogo da cobra",9);
    e1.exibir();

    return 0;
}