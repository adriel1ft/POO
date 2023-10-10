#include <iostream>
#include <vector>

using namespace std;

template <typename T>

class pilha{
  vector<T> p; //attr q vai anlsr os elemts
 
public:
    pilha(){
        
    }
    
    void push(T elemento){
        p.push_back(elemento);
    }
    
    void pop(){
        if (!is_empty){
            p.pop_back();
        }
    }
    
    T top(){
        if (!is_empty){
            return p.back();
        }    
    }
    
    bool is_empty(){
        return p.empty;
    }
};

class coisa {
  int aributo;
 public:
    coisa(int a=0) {
        atributo = a;
    }
    int g et_atributo(){
        return atributo;
    }
    void set_atributo(int i){ atributo = i;}
    
};

int main()
{
    
    pilha<int> pilha_int;
    pilha<coisa> pilha_coisa;
    
    pilha_int.push(50);
    pilha_int.push(100);
    
    pilha_int.pop();
    cout<<"Hello World";

    return 0;
}