/*
Adriel Ferreira Trajano - 20220071160
questão 1

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class pessoa{
    
    string nome;
    int idade;
//construtor    
public:
    pessoa(int i, const string& n): nome(n), idade(i){}
    
    int get_idade(){return idade;}
    void set_idade(int i){idade = i;}
    string get_nome(){return nome;}
    void set_nome(string n){nome = n;}
    
    virtual void exibir() = 0;
    
    friend ostream& operator<<(ostream& os, pessoa& p){
        os << "Nome: " << p.nome << ", idade: " << p.idade << endl;
        return os;
    }
}; //feito

class paciente: public pessoa{
    int num_paciente;
    string condicao;
    
public: //constructor
    paciente(const string& no, int i, int num, const string& c): pessoa(i,no), num_paciente(num), condicao(c){}
    
    int get_num_paciente(){return num_paciente;}
    void set_num_paciente(int num){num_paciente = num;}
    string get_condicao(){return condicao;}
    void set_condicao(string c){condicao = c;}
    
    void exibir() override{
        cout << "Nome: " << get_nome() << endl;
        cout << "Idade: " << get_idade() << endl;
        cout << "Numero do paciente: " << num_paciente << endl;
        cout << "Condicao: " << condicao << endl;
    }
    
    friend ostream& operator<<(ostream& os, paciente& p){
        os << "Nome: " << p.get_nome() << endl;
        os << "Idade: " << p.get_idade() << endl;
        os << "Numero do paciente: " << p.num_paciente << endl;
        os << "Condicao: " << p.condicao << endl;
        return os;
    }
    
    
    
};//feito

class medico: public pessoa{ 
    int crm;
    string especialidade;
    
public: //constructor
    medico(const string& no, int i, int c, const string& e): pessoa(i,no) , crm(c), especialidade(e){}
    
    int get_crm(){return crm;}
    void set_crm(int c){crm = c;}
    string get_especialidade(){return especialidade;}
    void set_especialidade(string e){especialidade = e;}
    
    void exibir() override{
        cout << "Nome: " << get_nome() << endl;
        cout << "Idade: " << get_idade() << endl;
        cout << "CRM: " << crm << endl;
        cout << "Especialidade: " << especialidade << endl;
    }
    
    friend ostream& operator<<(ostream& os, medico& m){
        os << "Nome: " << m.get_nome() << endl;
        os << "Idade: " << m.get_idade() << endl;
        os << "CRM: " << m.crm << endl;
        os << "especialidade: " << m.especialidade << endl;
        return os;
    }
}; //feito

class procedimento{
    string desc;
    string data;
public:

    procedimento(const string& de, const string& da): desc(de), data(da){}

    string get_desc(){return desc;}
    void set_desc(string de){desc = de;}
    string get_data(){return data;}
    void set_data(string da){data = da;}
    
    virtual void exibir(){
        cout << "Descricao: " << desc << endl;
        cout << "Data: " << data << endl;

}

    friend ostream& operator<<(ostream& os, procedimento& pr){
        os << "Descricao: " << pr.desc << endl;
        os << "Data: " << pr.data << endl;
        return os;
    }
}; //feito

class hospital{
    vector<paciente*> pacientes;
    vector<medico*> medicos;
    vector<procedimento*> procedimentos;
 
 public:  
    void adicionar_paciente(paciente* paci){
        pacientes.push_back(paci);
    }
    
    void adicionar_medico(medico* med){
        medicos.push_back(med);
    }
    
    void listar_pacientes(){
        cout << "Lista de pacientes:" << endl;
        for(const auto& paci: pacientes){
            cout << *paci << endl;;
        }
        cout << "----------" << endl;
    }
        
    void listar_medicos(){
    cout << "Lista de medicos:" << endl;
    for(const auto& med: medicos){
        cout << *med << endl;
            }
        cout << "----------" << endl;
        }
    
    void reg_procedi(medico* med, paciente* paci, procedimento* proc){
        procedimentos.push_back(proc);
    }
    
    void listar_procedi(){
        cout << "Lista de procedimentos:" << endl;
        for(const auto& proc: procedimentos){
            cout << *proc << endl;
        }
        cout << "----------" << endl;
    }
    
    //void desalocar(){}
};





int main()
{
    hospital* h = new hospital();
    
    paciente* p1 = new paciente("Lin",25,777,"braco quebrado");
    paciente* p2 = new paciente("Jake",36,778,"escoliose");
    paciente* p3 = new paciente("Mina",19,779,"gripe");
    
    medico* med1 = new medico("Claudio", 50, 12345, "ortopedista");
    medico* med2 = new medico("Joao", 49, 34567, "ortopedista");
    
    procedimento* proc1 = new procedimento("cirurgia","20/05");
    procedimento* proc2 = new procedimento("terapia","21/05");
    
    h->adicionar_medico(med1);
    h->adicionar_medico(med2);

    h->adicionar_paciente(p1);
    h->adicionar_paciente(p2);
    h->adicionar_paciente(p3);
    
    h->reg_procedi(med1,p1,proc1);
    h->reg_procedi(med2,p2,proc2);

    
    h->listar_pacientes();
    h->listar_medicos();
    h->listar_procedi();
    
    //finalizar hospital

    return 0;
}
