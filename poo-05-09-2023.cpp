#include <iostream>

using namespace std;

class animal{ //classe ascendente
    int idade;
public:
animal(int i){
    idade = i;
}
int get_idade(){
    return idade;
}
void set_idade(int i){
    idade = i;
}
virtual void fazer_barulho() = 0; //deinir metodos q podem ser sobrepostos, ligacao dinamica
};

class cachorro: public animal { //classe descendente
    int latido;
public:
    cachorro(int i, int l): animal(i), latido(l){}
    int get_latido(){
        return latido;
    }
    void set_latido(int l){
        latido = l;
    }
    virtual void fazer_barulho(){
        cout << "cachorro latindo: " << latido << endl;
    }
};

class gato: public animal { //classe descendente
    int miado;
public:
    gato(int i, int m): animal(i), miado(m){} //constructor

    int get_miado(){
        return miado;
    }

    void set_miado(int m){
        miado = m;
    }
    virtual void fazer_barulho(){
        cout << "gato miando: " << miado << endl;
    }

};

int main()
{
    //animal a1(10); //vai dar errado
    animal = zero[QTD_ANIMAIS];

    for(int i = 0; i < QTD_ANIMAIS; i++ ){
        int read;
        cout << "Digite 1 para cachorro, 2 para gato: ";
        cin >> read;

        if(read == 1){
            int id, la;
            cout << "Digite a idade do cachorro: ";
            cin >> id;
            cout << "Digite o latido do cachorro: ";
            cin >> la;
            zoo[i] = new cachorro(id, la);
        }
    }




    return 0;
}
