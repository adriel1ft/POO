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
    static int get_contador(){
        return contador;
    }
    
    virtual void print_info(){
        cout << "funcionario" << endl;
        cout << "nome: " << " | " << nome << " | ";
        cout << "id: " << " | " << id << " | ";
        cout << "salario" << " | " << salario << " | " << endl;
    }

    string& get_nome(){
        return nome;
    }
};

//inicializando a variavel contador
int funcionario::contador = 0;

class empregado_regular: public funcionario{
    int codigo_categoria;

public:
empregado_regular(int cc, const string& n, int i, float s ): funcionario(n,i,s), codigo_categoria(cc){ funcionario::add_contador();}

virtual void print_info(){
    funcionario::print_info();
    cout << "Regular" << endl;
    cout << "Codigo da categoria: " << codigo_categoria << endl;
}
    



//gets e sets

    
};

class gerente: public funcionario{
    float bonus;

public:
    gerente(float b, const string& n, int i, float s): funcionario(n,i,s), bonus(b){ 
        funcionario::add_contador(); }
    
    virtual void print_info(){
    funcionario::print_info();
    cout << "Gerente" << endl;
    cout << "Bonus: " << bonus << endl;
}
};

class estagiario: public funcionario{
    string data_nascimento;

public:
    estagiario( const string& d, const string& n, int i, float s): funcionario(n,i,s), data_nascimento(d){
        funcionario::add_contador();
    }


    virtual void print_info(){
        funcionario::print_info();
        cout << "Estagiario: " << endl;
        cout << "Data de aniversario: " << data_nascimento << endl;
    }
};

class empregado_gerente: public empregado_regular, public gerente{
public:
    empregado_gerente( int cc, float b, const string& n, int i, float s): empregado_regular(cc,n,i,s), gerente(b,n,i,s){
        funcionario::add_contador();
    }

    virtual void print_info(){
        cout << "Empregado Gerente" << endl;
        empregado_regular::print_info();
        gerente::print_info();
    }
};


class empresa{
    vector<funcionario*> funcionarios;
    vector<empregado_gerente*> e_gerentes;
    vector<estagiario*> estagiarios;

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

    //add and delete funcionario
    void add_funcionario(funcionario* f){
        funcionarios.push_back(f);
        
    }
    
    //deletando funcionario recebendo nome como argumento
    void delete_funcionario(const string& nome){
        for(int i=0; i<funcionarios.size();i++){
            if(funcionarios[i]->get_nome() == nome){
                funcionarios.erase(funcionarios.begin()+i);
            }
        }

            
    }

    //add and delete empregado gerente
    void add_empregado_gerente(empregado_gerente* eg){
        e_gerentes.push_back(eg);
    }

    void del_empregado_gerente(int index){
        e_gerentes.erase(e_gerentes.begin()+index);

    }

    //add and delete estagiario
    void add_estagiario(estagiario* e){
        estagiarios.push_back(e);
    }

    void del_estagiario(int index){
        estagiarios.erase(estagiarios.begin()+index);
        
    }
    
    //listagens
    void list_funcionarios(){
        for (funcionario* f: funcionarios){
            f->print_info();
        }
    }

    void list_empregado_gerente(){
        for (auto eg: e_gerentes){
            eg->print_info();
        }
    }

    void list_estagiarios(){
        for (auto* e: estagiarios){
            e->print_info();
        }
    }
};

empresa* empresa::_instance = NULL;

class funcionario_exception{
    string msg;

public:
    funcionario_exception(const string& m): msg(m){}
    void print_info(){
        cout << msg << endl;
    }
};

estagiario* create_estagiario(){
    int  id;
    string n,d;
    float s;
    
    cout << "Digite o nome do estagiario: ";
    cin >> n;
    cout << "Digite o id do estagiario: ";
    cin >> id;
    cout << "Digite a data de nascimento do estagiario: ";
    cin >> d;
    cout << "Digite o salario do estagiario: ";
    cin >> s;
    
    // o throw new lança a exception
    if (s <= 0)
        throw new funcionario_exception("salario");
    if (id <= 0)
        throw new funcionario_exception("id");
    if(n.empty())
        throw new funcionario_exception("nome");
    if(d.size() < 6)
        throw new funcionario_exception("data");
    return new estagiario(d,n,id,s);
    
    
}
    


int main()
{
    empresa* e;
    e = empresa::get_instance();

    estagiario* est1 = new estagiario("31/10/2023","Ana",1013,1500);
    empregado_regular ere1(10, "Maria", 1015, 6000);
    gerente ger1(1500, "Jose", 1200,7000);
    empregado_gerente* ege1 = new empregado_gerente(11, 1500, "Josefa", 1030, 8000);
    
    e->add_estagiario(est1);
    e->add_empregado_gerente(ege1);
    
    //teste de insercao de estagiario
    insert_est:
    try{
        estagiario* est2 = create_estagiario();
        e->add_estagiario(est2);
    } catch (funcionario_exception* e){
        cout << "Erro ao criar funcionario: ";
        e->print_info();
        goto insert_est;
    }

    return 0;
}

//como acessar a classe empresa
/*
singleton
empresa* e;
e = empresa::get_instance()

ou fzr


e = empresa::get_instance()->add_funcionario();


isso é um padrao de projeto que pode ser aplicado em outras linguagens tbm
*/