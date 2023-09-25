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

    usuario(){ //construtor padrão
        idade = 0;
        nome = "";
    }

    virtual ~usuario() {}

    string get_nome()const{return nome;}
    void set_nome(const string& n){nome =  n;}
    int get_idade() const {return idade;}
    void set_idade(int i) {idade = i;}

    virtual void exibir()=0;

    friend ostream& operator<<(ostream& os, const usuario& u){
        os << u.nome << ", " << u.idade << endl; //concatenar informacoes
        return os;
    }

    virtual void tipo_usuario(){
        cout << "Usuario" << endl;
}
};

class estudante: public usuario{
    int matricula;
    string curso;

public:
    estudante(const string& n, int i, int m, const string& c): usuario(n,i), matricula(m), curso(c){}

    virtual ~estudante() {}

    //gets e sets
    
    int get_matricula(){return matricula;}
    void set_matricula(int m){matricula = m;}
    
    string get_curso(){return curso;}
    void set_curso(const string c){curso=c;}

    void exibir() override { //print na tela
    cout << "Nome: " << get_nome() << ", Matrícula: " << matricula << ", Curso: " << curso << endl;}

friend ostream& operator<<(ostream& os, estudante& e){

    os << "Nome: " << e.get_nome() << ", Matrícula: " << e.matricula << ", Curso: " << e.curso << endl;
    return os;
}
};

class professor: public usuario{
    string dep;

public:
    professor(const string& n, int i, const string& d): usuario(n,i), dep(d){}

    virtual ~professor() {}

    string get_dep(){return dep;}
    void set_dep(const string& d){dep = d;}

    void exibir() override { //print na tela
    cout << "Nome: " << get_nome() << ", Departamento: " << dep << endl;}

    friend ostream& operator<<(ostream& os, professor& p){

        os << "Nome: " << p.get_nome() << ", Departamento: " << p.dep << endl;
        return os;
}

};

class material{
    string titulo;

public:
    material(const string& t):titulo(t){}

    virtual ~material() {}

    string get_titulo() const {return titulo;}
    void set_titulo(const string& t){titulo =  t;}

virtual void exibir() = 0;// nas subclasses ela detalha tbm
};

class livro: public material{
    string autor;
    int ano_publicacao;

    virtual ~livro() {}

public:
    livro(const string& t,const string& au,int ano): material(t), autor(au),ano_publicacao(ano){}
    
    //gets e sets
    string& get_autor(){return autor;}
    void set_autor(const string& au){autor = au;}
    int get_ano_publicacao(){return ano_publicacao;}
    void set_ano_publicacao(int ano){ano_publicacao = ano;}


void exibir() override {
    cout << "Titulo: " << get_titulo() << ", Autor: " << autor << ", Ano de Publicacao: " << ano_publicacao << endl;
}

friend ostream& operator<<(ostream& os,const livro& li){
    os << "Titulo: " << li.get_titulo() << ", Autor: " << li.autor << ", Ano de Publicacao: " << li.ano_publicacao << endl;
    return os;
}

};

class revista: public material{
    int num_edicao;
    
public:
    revista(const string& t,int e): material(t), num_edicao(e){}

    virtual ~revista() {}
    
    //gets e sets
    int get_num_edicao(){return num_edicao;}
    void set_num_edicao(int e){num_edicao = e;}

    void exibir() override{
        cout << "Titulo: " << get_titulo() << ", Número da edição: " << num_edicao << endl;
    }


    friend ostream& operator<<(ostream& os, revista& r){
    os << "Titulo: " << r.get_titulo() << ", Número da edição: " << r.num_edicao << endl;
    return os;
}
};

class emprestimo{

        //pode declarar assim ou na mão: classe, int qtd
    /*vector traz facilidades mas pode acontecer de
fazer na mão ser mais rapido e consumir menos memória*/

    usuario* u;
    material* m;
    int qtd_material;
    string data;

public:
    emprestimo(usuario* uu, material* mm, int q, const string& d):u(uu),m(mm),qtd_material(q),data(d){}

//gets e sets 

int get_qtd_material(){return qtd_material;}
void set_qtd_material(int q){qtd_material = q;}

emprestimo& operator+(emprestimo& outro){ //primeiro operando é ele q recebe. em ostream começa com ostream. é fora
    if(u==outro.u){
        qtd_material = outro.qtd_material;
} 
return *this; // Retorne o próprio objeto para suportar operações em cadeia 
}
    
friend ostream& operator<<(ostream& os, const emprestimo& emp){
    os << "Informacoes do emprestimo: " << endl;
    os << "Usuario: " << emp.u->get_nome() << endl;
    os << "Material: " << emp.m->get_titulo() << endl;
    os << "Quantidade: " << emp.qtd_material << endl;
    os << "Data: " << emp.data << endl;
    return os;  
}


};

class biblioteca{



    vector<usuario*> usuarios;
    vector<material*> materiais;
    vector<emprestimo*> emprestimos;
    
public:

    biblioteca (){
    //usuarios = ptrnull;

    

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
            cout << "Nome: " << usr->get_nome() << endl;
        }
    }
    
    //tenho que criar uma biblioteca para emprestar um material
    void emprestar_material(usuario* usr, material* mat, int qm, string d){
        emprestimo* emp = new emprestimo(usr, mat, qm, d);
        emprestimos.push_back(emp);
    }

    void listar_emprestimos(){
        for(auto emp: emprestimos){ //o auto deduza automaticamente o tipo da variável
            cout << *emp << endl;
        }
    }

    void desalocar_recursos(){
        for(auto u: usuarios){
            delete u;
        }

        
        for(auto m: materiais){
            delete m;
        }

        
        for(auto emp: emprestimos){
            delete emp;
        }
    }
};


int main(){

    biblioteca* biblio = new biblioteca();

    usuario* user1 = new estudante("Ariana", 18, 666, "arquitetura"); 
    usuario* user2 = new professor("Nicki", 49, "DDL");

    material* mat1 = new livro("A hora da Estrela","Clarice",1999);
    material* mat2 = new livro("Barata","Clarice",1990);
    material* mat3 = new revista("Vogue",2013);
    material* mat4 = new revista("Science Magazine",2019);

    biblio->adicionar_usuario(user1);
    biblio->adicionar_usuario(user2);

    biblio->adicionar_material(mat1);
    biblio->adicionar_material(mat2);
    biblio->adicionar_material(mat3);
    biblio->adicionar_material(mat4);

    biblio->emprestar_material(user1,mat1,1,"24/09/2023");
    biblio->listar_emprestimos();

    biblio->desalocar_recursos();

    return 0;
}

// rever oq o professor fez de diferente na sala