#include <iostream> //equivalent to stdio in C
#include <stdio.h>
#include <string.h>
#include <vector>
// using namespace std; //traz todas as classes. fica mais pesado pq aqui chama
// td
using std::cin;
using std::cout;
using std::endl;
using std::string;
/*classes:
livro (atributos: titulo, ISBN, ano_lancamento, lista_autores),
leitor(nome,idade, cpf)
autor(nome,idade,nacionalidade),
empréstimo(data_inicio,data_fim,lista_livros,leitor),
acervo(lista_livros, copias_disponiveis,copias_emprestadas)*/
#define MAX_LIVROS 1000

class Autor {
  string nome;
  int idade;
  string nacionalidade;

public:
  Autor(const string& no, int i, const string &na) {
    nome = no;
    idade = i;
    nacionalidade = na;
  }
  string &get_nome() { return nome; }
  void set_nome(string &no) { nome = no; }
  int get_idade() { return idade; }
  void set_idade(int i) { idade = i; }
  string &get_nacion() { return nacionalidade; }
  void set_nacion(string &na) { nacionalidade = na; }
  void print_info() {
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;
    cout << "Nacionalidade: " << nacionalidade << endl << endl;
  }
};

class Livro {

  string titulo;
  int ISBN;
  int ano_lancamento;
  Autor** autores;
  /*Autor** autores = (Array de ponteiros)*/
  int qtd_autores;

public:
  Livro(const string &t, int al, int is, Autor** au, int qtd_au) {
    titulo = t;
    ano_lancamento = al;
    ISBN = is;
    autores = au;
    qtd_autores = qtd_au;
  }

  string &get_titulo() { return titulo; }
  void set_titulo(string &t) { titulo = t; }

  int get_ano_lancamento() { return ano_lancamento; }
  void set_ano_lancamento(int al) { ano_lancamento = al; }

  int get_isbn() { return ISBN; }
  void set_isbn(int is) { ISBN = is; }

  Autor** get_autores() { return autores; }
  void set_autores(Autor** au) { autores = au; }

  int get_qtd_autores() { return qtd_autores; }
  void set_qtd_autores(int qtd_au) { qtd_autores = qtd_au; }
  void print_info() {
    cout << "Título: " << titulo << endl;
    cout << "Ano lancamento: " << ano_lancamento << endl;
    cout << "ISBN: " << ISBN << endl;
    cout << "Quantidade de autores: " << qtd_autores << endl << endl;
    cout << "Autores: " << endl << endl;
      for(int i =0; i<qtd_autores; i++){
          autores[i]->print_info();
      }
  }
};

class Leitor {
  string nome;
  int idade;
  int cpf;

  Leitor(const string &no, int i, int c) {
    nome = no;
    idade = i;
    cpf = c;
  }

  string &get_nome() { return nome; }
  int get_idade() { return idade; }
  int get_cpf() { return cpf; }

  void set_nome(string &no) { nome = no; }
  void set_idade(int i) { idade = i; }
  void set_cpf(int c) { cpf = c; }

  void print_info() {
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;
    cout << "CPF: " << cpf << endl << endl;
  }
};

class Emprestimo {
  string data_inicio;
  string data_fim;
  Livro** livros;
  int qtd_livros;
  Leitor* cliente;

public:
  Emprestimo(const string &di, const string &df, Livro** ls, int qtdl,
             Leitor* c) {
    data_inicio = di;
    data_fim = df;
    livros = ls;
    qtd_livros = qtdl;
    cliente = c;
  }

  string &get_data_inicio() { return data_inicio; }
  string &get_data_fim() { return data_fim; }
  Livro** get_livros() { return livros; }
  int get_qtd_livros() const { return qtd_livros; }
  Leitor* get_cliente() { return cliente; }

  void set_data_inicio(string &di) { data_inicio = di; }
  void set_data_fim(string &df) { data_fim = df; }
  void set_livros(Livro** ls) { livros = ls; }
  void set_cliente(Leitor* c) { cliente = c; }

  void print_info() {
    cout << "Data inicio: " << data_inicio << endl;
    cout << "Data fim: " << data_fim << endl;
    cout << "Livros: " << endl;
    for (int i = 0; i < qtd_livros; i++) {
      livros[i]->print_info();
    }
    cout << "Cliente: " << cliente << endl;
  }
};

class Acervo {
  // melhorar usando vector
  Livro* estoque[MAX_LIVROS];
  int copias_disponiveis[MAX_LIVROS];
  int copias_emprestadas[MAX_LIVROS];
  int last_index = 0;

public:
  void add_livro(Livro* l, int copias_emp) {
    estoque[last_index] = l;
    this->copias_emprestadas[last_index] = copias_emp;
    this->copias_disponiveis[last_index] = l->get_qtd_autores() - copias_emp;
    last_index++;
  }
    void listar_livros(){
    cout << "Lista de livros: " << endl;
    for(int i =0; i<last_index; i++){
        cout << "Livro " << i+1 << ":" << endl;
        cout << estoque[i]->get_titulo() << endl;
    }
}
};

int main(void) {

  /*int idade;

    cout << "Insira a idade do autor: "; //inserção
    cin >> idade; //extração
    cout << "Idade inserida: " << idade << endl;
    return 0;*/

Autor a1("XYZ",99,"BR");
  //a1.print_info();
Autor a2("ZWX",89,"PT");
Autor a3("ZYZ",77,"IT");
Autor a4("STEPHEN KING",75,"EN");
Autor a5("Alice",29,"UK");

  Autor* au1[3];
  au1[0] = &a1;
  au1[1] = &a2;
  au1[2] = &a3;

Autor* au2[2];
    au2[0] = &a4;
    au2[1] = &a5;

  Livro l1("ABCD",2011,1234,au1,3);

    Livro l2("EFGH",2023,5221,au2,2);
    //Livro* livros[2] = {&l1,&l2};
   Acervo meuAcervo;
    meuAcervo.add_livro(&l1,5);
    meuAcervo.add_livro(&l2,3);
       meuAcervo.listar_livros();

    return 0;

      /*Livro *li1[3];
  li1[0] =

      Emprestimo emp1()
*/
  
}

// dever de casa: criem um código q pede infos pro usuário. obs: prestar atenção
// na ordem. ele pediu 2 livros, com 2 autores cada. complementar emprestimo tbm