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
    
    int get_matricula(){return matricula;}
    void set_matricula(int m){matricula = m;}
    
    string get_curso(){return curso;}
    void set_curso(const string c){curso=c;}
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

virtual void exibir_detalhes(){ // nas subclasses ela detalha tbm
    cout << "titulo: " << titulo << endl;
}

class livro: public material{
    string autor;
    int ano_publicacao;

public:
    livro(const string& t,const string& au,int ano): material(t), autor(a),ano_publicacao(ano){}
    
    //gets e sets
}

friend ostream& operator>>(ostream& os,const material& ma){
    os << ma.titulo << endl;
    return os;
}

};

class revista: public material{
    int num_edicao;
    
public:
    livro(const string& t,int e): material(t), num_edicao(e){}
    
    //gets e sets
}

class emprestimo{
    usuario usu;
    material mat;

public:
    emprestimo()
    
};

class biblioteca{
    vector<usuario*> usuarios;
    vector<material*> materiais;
    vector<emprestimo*> emprestimos;
    
public:
    void adicionar_usuario(usuario* usr){
        usuarios.push_back(usr);
    }
    
    void adicionar_material(material* mat){
        materiais.push_back(mat);
    }
    
    void listar_usuarios(){
        cout << "Lista de usuarios:" << endl;
        for(const auto& usr: usuarios){
            cout << "Nome: " << usr->get_nome << endl;
        }
    }
    
    void emprestar_material(usuario* usr, material* mat){
        emprestimos.push_back(usr);
    }
};


};

class livro: public material{};

class revista: public material{};

class emprestimo{};
