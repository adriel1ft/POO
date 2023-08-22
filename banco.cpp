#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;

class Cliente{
string nome;
string cpf;
string endereco;

public:
Cliente(string no, string c, string end){
    nome = no;
    cpf = c;
    endereco = end;}

~Cliente(){}
string get_nome(){return nome;}
string get_cpf(){return cpf;}
string get_endereco(){return endereco;}


void set_nome(string no){nome = no;}
void set_cpf(string c){cpf = c;}
void set_endereco(string end){endereco = end;}

void print_info(){
    cout << "Nome: " << nome << endl;
    cout << "CPF: " << cpf << endl;
    cout << "Endereco: " << endereco << endl;
}
};
class Operacao{
char tipo; //saque (D) ou deposito (C)
float valor;
public:
    Operacao(char t, float v){
        tipo = t;
        valor = v;
    }
~Operacao(){}
char get_tipo(){return tipo;}
float get_valor(){return valor;}
void set_tipo(char t){tipo = t;}
void set_valor(float v){valor = v;}
void print_info(){
    cout << "Tipo: " << tipo << endl;
    cout << "Valor: " << valor << endl;
}

};
class Conta{
int numero;//numero da conta
Cliente *cli;
float saldo;
vector<Operacao> operacoes;

public:
Conta(int num, Cliente *c, float sa){
    numero = num;
    cli = c;
    saldo = sa;
}
~Conta(){
    operacoes.clear();
}
int get_numero(){return numero;}
Cliente get_cliente(){return *cli;}
float get_saldo(){return saldo;}
vector<Operacao> get_operacoes(){return operacoes;}

void set_numero(int num){numero = num;}
void set_cliente(Cliente *c){cli = c;}
void set_saldo(float sa){saldo = sa;}
void add_operacao(Operacao o){
    operacoes.push_back(o);
    if(o.get_tipo()=='D') {//saque. DÉBITO
        saldo -= o.get_valor();
    
    } else if (o.get_tipo() == 'C'){ //deposito. CRÉDITO
        saldo += o.get_valor();
    }
}

void print_info(){
    cout << "Numero: " << numero << endl;
    cout << "Cliente: " << cli->get_nome() << endl;
    cout << "Operacoes: " << endl;
    for (int i = 0; i < operacoes.size(); i++){
        operacoes[i].print_info();
    }
    cout << "Saldo: "<< saldo << endl;
}
};
class Banco{
vector<Conta> contas;

public:
int codigo;
Banco(int c){codigo = c;}
~Banco(){
    contas.clear();
}

void add_conta(Conta c){
    contas.push_back(c);
}
void remove_conta(int n){ //
    for(int i=0; i < contas.size();i++){
        if(contas[i].get_numero() == n){
            contas.erase(contas.begin()+1);
            break;
            
        }
    }
}

int get_codigo(){
    return codigo;
}

Conta* get_conta(int n){
    for(int i=0; i < contas.size();i++){
        if(contas[i].get_numero() == n){
            return &contas[i];
        }
    }
    return NULL;
}

void transfere(Conta *c1, Conta *c2, float v){
    Operacao o1('D', v);
    Operacao o2('C', v);
    c1->add_operacao(o1);
    c2->add_operacao(o2);
}

void print_info(){
    cout << "Banco: " << codigo << endl;
    cout << "Contas: " << endl;
    for(int i = 0; i < contas.size(); i++){
        contas[i].print_info();}
}
    
};

int main() {

    Banco *b1 = new Banco(1);
    
    Cliente *c1 = new Cliente("andre","158845677-00","rua das bananas");
    Cliente *c2 = new Cliente("luiz","584345966-37","avenida ruy barbosa");
    //c1->print_info();
    Conta *con1 = new Conta(12345678,c1,0);
    Conta *con2 = new Conta(47885694,c2,100);
        
    Operacao op1('C',500);
    Operacao op2('D',330);

    vector<Operacao> operacoes1;
    operacoes1.push_back(op1);
    operacoes1.push_back(op2);

    con1->add_operacao(op1);
    con1->add_operacao(op2);
    con1->print_info();

    

    b1->transfere(con2, con1,50);
    b1->print_info();

    
    return 0;
}