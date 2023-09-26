/*
Adriel Ferreira Trajano - 20220071160
questão 3

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class pessoa{
    string nome;
    int cpf;

public:
    pessoa(const string& no, int c): nome(no), cpf(c){}
    
    int get_cpf(){return cpf;}
    void set_cpf(int c){cpf = c;}
    string get_nome(){return nome;}
    void set_nome(string n){nome = n;}
    
    virtual void exibir() = 0;
    
    friend ostream& operator<<(ostream& os, pessoa& p){
        os << "Nome: " << p.nome << ", cpf: " << p.cpf << endl;
        return os;
    }
    
    bool operator==(const pessoa& outra) const {
        return this->cpf == outra.cpf;
    }
};

class passageiro: public pessoa{
    int cartao;
    
    passageiro(const string& no, int c, int ca): pessoa(no,c), cartao(ca){}
public:
    int get_cpf(){return cartao;}
    void set_cpf(int ca){cartao = ca;}
 
    
    virtual void exibir()  override {}
    
    friend ostream& operator<<(ostream& os, passageiro& p){
        os << "Cartao: " << p.cartao << endl;
        return os;
    }
    
    
};

class voo{
    int num_voo;
    string origem, destino, data, horario;
public:
    voo(int v, const string& o, const string& de, const string& da, const string& ho): 
    num_voo(v), origem(o), destino(de), data(da), horario(ho) {}
    
    int get_num_voo(){return num_voo;}
    void set_num_voo(int v){num_voo = v;}
    
    string get_origem(){return origem;}
    void set_origem(string o){origem = o;}
    
    string get_destino(){return destino;}
    void set_destino(string de){destino = de;}
    
    string get_data(){return data;}
    void set_data(string da){data = da;}
    
    string get_horario(){return horario;}
    void set_horario(string ho){horario = ho;}
 
    
    virtual void exibir()  override {
        cout << "Voo nº: " << num_voo << endl;
        cout << "Origem: " << origem << endl;
        cout << "Destino: " << destino << endl;
        cout << "Data: " << data << endl;
        cout << "Horario: " << horario << endl;
    }
    
    friend ostream& operator<<(ostream& os, voo& v){
        os << "Voo nº: " << v.num_voo << endl;
        os << "Origem: " << v.origem << endl;
        os << "Destino: " << v.destino << endl;
        os << "Data: " << v.data << endl;
        os << "Horario: " << v.horario << endl;
        return os;
    }
};

class reserva{
    string classe, ass;
    passageiro* pass;
    voo* v;
    
public:
    reserva(const string& c, const string& a, passageiro* p , voo* vv):
    pass(p), voo(v), classe(c), ass(a){}
    
    //gets e sets 
    passageiro* get_pass(){return pass;}
    void set_pass(string p){pass = p;}
    
    voo* get_voo(){return voo;}
    void set_voo(voo* v){voo = v;}
    
    string get_classe(){return classe;}
    void set_classe(string a){ass = a;}
    
    
    //classe pra exibir
    
    virtual void exibir()  override {
        passageiro::exibir();
        voo::exibir();
        cout << "Class: " << classe << endl;
        cout << "Assento: " << ass << endl;
  
    }
    
    //operator<< 
    friend ostream& operator<<(ostream& os, reserva& r){
        passageiro::exibir();
        voo::exibir();
        cout << "Classe: " << r.classe << endl;
        cout << "Assento: " << r.ass << endl;
        return os;
};

class companhia{
    
    vector<voo*> voos;
    vector<reserva*> reservas;
    
    void adicionar_voo(voo* v){
        voo.push_back(v);
    }
    
    void fzr_reserva(passageiro* pas, voo* v, std::string classe, std::string assento){
        reserva* res = new reserva()
        reservas.push_back(reserva);
    }
    
    listar_voos_disponiveis(){
        cout << "Lista de voos disp:" << endl;
        for(const auto& v: voos){
            cout << *v << endl;
        }
        cout << "----------" << endl;
    }
    
    listar_reservas(){
        cout << "Lista de reservas:" << endl;
        for(const auto& r: reservas){
            cout << *r << endl;
        }
        cout << "----------" << endl;
    }
    
    
    

    
};




int main()
{
    companhia* comp = new companhia();
    
    //criacao de passageiro
    
    passageiro* p1 = new passageiro();
    passageiro* p2 = new passageiro();
    passageiro* p3 = new passageiro();
    
    //criacao de voos
    
    voo* v1 = new voo();
    voo* v2 = new voo();
    voo* v3 = new voo();
    
    //criacao de reservas
     
     reserva* r1 = new reserva();
     reserva* r2 = new reserva();
     
     //fzr reserva
     
     companhia->fzr_reserva();
     
    return 0;
}