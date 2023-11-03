/*Sistema de gerenciamento de funcionarios*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class funcionario{
    string nome;
    int id;
    float salario;
    static int contador; // n pode inicializar dentro da classe

protected:
    static void add_contador(){
        contador++;
    }

    static void dec_contador(){
        contador--;
    }

    
public:
funcionario(const string& n, int i, float s): nome(n), id(i), salario(s) {
    contador++;
}
    //~funcionario(){contador--;} prof n usou mais isso
    static void get_contador(){
        return contador;
    }
    
    virtual void print_info(){
        cout << "funcionario" << endl;
        cout << "nome: " << " | ";
        cout << "id: " << id << " | ";
        cout << "salario" << salario << endl;
    }

    string& get_nome(){
        return nome;
    }
};

int funcionario::contador = 0;

class empregado_regular: public funcionario{
    int codigo_categoria;

public:
empregado_regular(int cc, const string& n, int i, float s ): funcionario(n,i,s), codigo_categoria(cc){ funcionario::add_contador();}

virtual void print_info(){
    funcionario::print_info();
    cout << "Regular" << endl;
    cout << "Codigo: " << codigo_categoria << endl;
}
    



//gets e sets

    
};

class gerente: public funcionario{
    float bonus;

public:
    gerente(float b, const string& n, int i, float s): funcionario(n,i,s), bonus(b){ funcionario::add_contador(); }
    
    virtual void print_info(){
    funcionario::print_info();
    cout << "Gerente" << endl;
    cout << "Bonus: " << bonus << endl;
}
};

class estagiario: public funcionario{
    string data_nascimento;

public:
    estagiario( const string& d, const string& n, int i, float s): funcionario(n,i,s), data_nascimento(d){}


    virtual void print_info(){
        funcionario::print_info();
        cout << "Estagiario: " << endl;
        cout << "Data de aniversario: " << data_nascimento << endl;
    }
};

class empregado_gerente: public empregado_regular, public gerente{
public:
    empregado_gerente( int cc, float b, const string& n, int i, float s): empregado_regular(cc,n,i,s), funcionario(b,n,i,s){}
     
};


class empresa{
    vector<funcionario*> funcionarios;
    //pra ser singleton, terá no máximo uma instância
    static empresa* _instance;
    
    empresa(){}
public:
    
    static empresa* get_instance(){
        if(_instance == NULL){
            _instance = new empresa();
        }
        return _instance;
    }
    void add_funcionario(funcionario* f){
        funcionarios.push_back(f);
        
    }
    
    void delete_funcionario(int index){
        funcionarios.erase(funcionarios.begin+index())
    }
    
    void list_funcionarios(){
        for (funcionario f: funcionarios){
            f->print_info();
        }
    }
};

empresa* empresa::get_instance() == NULL;

class funcionario_exception{
    string msg;
public:
funcionario_exception(string& m): msg(m){}
void print_info(){
    cout << msg << endl;
}

estagiario* create_estagiario(){
    int  id;
    string n,d;
    float s;
    
    cout << "Digite o nome do estagiario: ";
    cin >> n;
    cout << "Digite a data de nascimento do estagiario: ";
    cin >> d;
    
    
    if (s <= 0)
        throw new funcionario_exception("salario");
    if(n.size() == 0)
        throw new funcionario_exception("nome");
         
    
}
    
}

int main()
{
    empresa e*;
    estagiario est1("31/10/2023","Ana",1013,1500);
    empregado_regular ere1(10, "Maria", 1015, 6000);
    gerente ger1(1500, "Jose", 1200,7000);
    empregado_gerente ege1(11, 1500, "Josefa", 1030, 8000);
    
    e->add_funcionario(est1);
    e->add_funcionario(ere1);
    e->add_funcionario(ger1);
    e->add_funcionario(ege1);

    return 0;
}

//como acessar a classe empresa
/*
singleton
empresa* e;
e = empresa::get_instance()

ou fzr


e = empresa::get_instance()->add_funcionario();


isso é um padrao de projeo que pode ser aplicado em outras linguagens tbm
*/