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
    void set_idade(int i){idade = i;}

    virtual void exibir()=0;

    friend ostream& operator<<(ostream& os, usuario& u){
    os << u.nome << ", " << u.idade << endl; //concatenar informacoes
    }

virtual void tipo_usuario(){//completar
}
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

    string get_titulo() const {return titulo;}
    void set_titulo(const string& t){titulo =  t;}

virtual void exibir() = 0;// nas subclasses ela detalha tbm
};

class livro: public material{
    string autor;
    int ano_publicacao;

public:
    livro(const string& t,const string& au,int ano): material(t), autor(au),ano_publicacao(ano){}
    
    //gets e sets
    string& get_autor(){return autor;}
    void set_autor(const string& au){autor = au;}
    int get_ano_publicacao(){return ano_publicacao;}
    void set_ano_publicacao(int ano){ano_publicacao = ano;}


void exibir() override {
    cout << "Titulo: " << get_titulo() << ", Autor: " << autor << ", Ano de Publicacao: " << ano_publicacao << endl;
}//completar

friend ostream& operator<<(ostream& os,const livro& li){
    os << "Titulo: " << li.get_titulo() << ", Autor: " << li.autor << ", Ano de Publicacao: " << li.ano_publicacao << endl;
    return os;
}

};

class revista: public material{
    int num_edicao;
    
public:
    revista(const string& t,int e): material(t), num_edicao(e){}
    
    //gets e sets
    int get_num_edicao(){return num_edicao;}
    void set_num_edicao(int e){num_edicao = e;}

    void exibir() override{}


friend ostream& operator<<(ostream& os, revista& r){
//completar
}
};

class emprestimo{
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
    if(u==outro.u){// criar novo array que eh a soma dos dos anteriores

        int novo_q = qtd_material + outro.qtd_material;

       material* na = new material[novo_q]; // alocando memoria para o novo array

        //Copiar os materiais originais para o array 'na'
        for(int i = 0; i < qtd_material; i++){
            na[i] = m[i];
        }

        // Copiar os materiais do empréstimo 'outro' para o array 'na'
        for (int i = 0; i < outro.qtd_material; ++i) {
            na[qtd_material + i] = outro.m[i];
        }

        //liberar memoria
        delete[] m;

        //atualizar o ponteiro 'm' para apontar para p novo array 'na'
        m = na;


}
return *this; // Retorne o próprio objeto para suportar operações em cadeia (por exemplo, emp1 + emp2 + emp3)
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


int main(){


    return 0;
}

// rever oq o professor fez de diferente na sala