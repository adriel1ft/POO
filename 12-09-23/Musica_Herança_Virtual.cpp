#include <iostream>
#include <string>
#include <vector> 

using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::vector;

class Musica{
    
   private:
   string titulo;
   string artista;
   
   public:
   Musica(const string& t, const string& a){
      titulo = t;
      artista = a;
   }
   
   
   
   string get_titulo(){
       return titulo;
   }
   
   void set_titulo(string t){
       titulo = t;
   }
   
   string get_artista(){
        return artista;       
   }
   
   void set_artista(string a){
       artista = a;
   }
   
   virtual void tocar() = 0;
    
};

class MusicaLocal: public Musica{
    private:
    string caminhoArquivo;
    
    public:
    MusicaLocal(const string& t, const string& a, const string& c)
        : Musica(t, a), caminhoArquivo(c) {}


    
    string get_caminho(){
        return caminhoArquivo;
    }
    
    void set_caminho(string c){
        caminhoArquivo = c;
    }
    
    virtual void tocar(){
        cout << "Música: " << get_titulo()<< endl;
        cout << "Artista: " << get_artista() << endl;
        cout << "Caminho do Arquivo: " << caminhoArquivo << endl <<endl;
    }
};

class MusicaStreaming: public Musica {
    string URL;
    
    public:
    MusicaStreaming(const string& t, const string& a, const string& u): Musica(t, a), URL(u) {}

     string get_url(){
        return URL;
    }
    
    void set_caminho(string u){
        URL = u;
    }
    
    virtual void tocar(){
        cout << "Música: " << get_titulo()<< endl;
        cout << "Artista: " << get_artista() << endl;
        cout << "URL: " << URL << endl <<endl;
    }
    
};



int main()
{
    MusicaLocal m1("cake","dnce","endereco/com/br");
    MusicaLocal m2("all i ask","adele","endereco/com/uk");
    //musica1.tocar();
    
    vector<Musica*>playlist;
    
    playlist.push_back(&m1);
    playlist.push_back(&m2);
    
    for(Musica* msc:playlist){
        msc->tocar();
    }
    
    

    return 0;
}

/*perguntas pro prof

-precisa de destrutor?
-pq a função virtual tem q ser igual a zero?

*/