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

    virtual void exibir()=0
};

friend ostream& operator<<(ostream& os, usuario u){
os << u.nome << ", " << u.idade << endl; //concatenar informacoes

virtual void tipo_usuario(){//completar}
}

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

    vois exibir(){ //print na tela
    cout << Nome << get.nome() << endl;

friend ostream& operator<(ostream& os, estudante e){
//completar
}
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

virtual void exibir_detalhes() = 0;// nas subclasses ela detalha tbm
};

class livro: public material{
    string autor;
    int ano_publicacao;

public:
    livro(const string& t,const string& au,int ano): material(t), autor(a),ano_publicacao(ano){}
    
    //gets e sets

void exibir(){//completar}
friend ostream& operator>>(ostream& os,const material& ma){
    os << ma.titulo << endl;
    return os;
}

};

class revista: public material{
    int num_edicao;
    
public:
    revista(const string& t,int e): material(t), num_edicao(e){}
    
    //gets e sets
friend ostream& operator<<(ostream& os, revista r){
//completar
}
};

class emprestimo{
    usuario* u;
    material* m;
    int qtd_material;
    string data;

public:
    emprestimo(usuario uu, material mm, int q, const string& d{}

//gets e sets 

emprestimo& operator+(emprestimo& outro) //primeiro operando é ele q recebe. em ostream começa com ostream. é fora
    {if(u==outro.u)
// criar novo array que eh a soma dos dos anteriores
{novo_q = qtd_m + outro.qtd_m;
material* na = malloc(novi_q*sizeof(material);
// preencher (popular) 'na' com emprestimos}
}

//friend ostream
};

class biblioteca{

    //pode declarar assim ou na mão: classe, int qtd
    /*vector traz facilidades mas pode acontecer de
fazer na mão ser mais rapido e consumir menos memória*/

    vector<usuario*> usuarios;
    vector<material*> materiais;
    vector<emprestimo*> emprestimos;
    
public:

    biblioteca (){
    usuarios = null;
    

}
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

// rever oq o professor fez de diferente na sala
