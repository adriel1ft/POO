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
   
   protected:
   virtual void tocarIntro() {
       cout << "Introdução: " << endl;
   }
   
   
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
        cout << "Musica: " << get_titulo()<< endl;
        cout << "Artista: " << get_artista() << endl;
        cout << "Caminho do Arquivo: " << caminhoArquivo << endl <<endl;
        cout << "-----------------------------------------------"<<endl;
    }
};

class MusicaStreaming: public Musica {
    string URL;
    
    public:
    MusicaStreaming(const string& t, const string& a, const string& u): Musica(t, a), URL(u) {}

     string get_url(){
        return URL;
    }
    
    void set_url(string u){
        URL = u;
    }
    
    virtual void tocar(){
        cout << "Musica: " << get_titulo()<< endl;
        cout << "Artista: " << get_artista() << endl;
        cout << "URL: " << URL << endl <<endl;
        cout << "-----------------------------------------------"<<endl;
    }
    
};

class Podcast: public Musica {
   string  apresentador;
   vector <string> episodios;
   
protected:
   void tocarIntro () override {
       cout << "Podcast em execucao" << endl;
   }
   
public:
   
   Podcast(const string& t,const string& a,const string& ap, const vector<string>& eps)
   : Musica(t,a), apresentador(ap), episodios(eps){}
   
   void adicionar_epi(const string& episodio){
       episodios.push_back(episodio);
   } //funcao de add episodio na lista (vector)
    
    vector<string> getEps() const { //manter cada string constante pra entrar na lista
        return episodios;
    }
    
    
    string get_apresentador(){
        return apresentador;
    }
    
    void set_apresentador(string ap){
        apresentador = ap;
    }
    
    virtual void tocar() override{
        tocarIntro(); //chama o metodo tocarIntro da classe base
        cout << "Titulo do Podcast: " << get_titulo() << endl;
        cout << "Rede / Produtora: " << get_artista() << endl;
        cout << "Apresentador(a): " << apresentador << endl<<endl;
        
        cout << "Episodios: " << endl; 
        for(const string& ep : episodios){
            cout << ep <<endl;
            
        }
        cout << endl;
        cout << "-----------------------------------------------"<<endl;
        
    }
};

class PodcastPremium: private Podcast {
    private:
        float preco;
        //bool AssinaturaAtiva; // 0 - nao, 1 - sim ->dps testo isso

    public:
        PodcastPremium(const string& t, const string& a, const string& ap, const vector<string>& eps, float p)
        : Podcast(t, a, ap, eps), preco(p){}

    //metodo para obter o preço 
    float get_preco() const{
        return preco;
    }

    void set_preco(float p){
        preco = p;
    }

   /* void ativarAssinatura (){
        assinaturaAtiva = true;
    }*/

//Método para add um episodio (override do método da classe base)
void adicionar_episodio(const string& eps){
    Podcast::adicionar_epi(eps);
    }

//Método para tocar o podcast (override do método tocar da classe base)
void tocar () {
    Podcast::tocar();
    }

};



int main()
{
    //musicas local
    MusicaLocal ml1("cake","dnce","endereco1/com/br");
    MusicaLocal ml2("all i ask","adele","endereco2/com/uk");
    
    //musicas em streaming
    MusicaStreaming ms1("sonifera ilha","titas","url1");
    ms1.tocar();
    
    vector<Musica*>playlist; //vetor de ponteiros do tipo Musica
    
    //adicionando musicas na playlist
    playlist.push_back(&ml1);
    playlist.push_back(&ml2);
    playlist.push_back(&ms1);

    //podcasts

    vector<string> lista_epis; 
    lista_epis.push_back("episodio 1");
    lista_epis.push_back("episodio 2");

    Podcast p1("podcre", "globo", "xuxa", lista_epis);
    //p1.tocar();

    vector<string> lista_epis_p; 
    lista_epis_p.push_back("episodio 1");
    lista_epis_p.push_back("episodio 2");

    

    //adicionando podcasts
    playlist.push_back(&p1);
    //playlist.push_back(&pp1);
    
    for(Musica* msc:playlist){ //estrutura de repetiçao para tocar as musicas e podcasts da playlist
        msc->tocar();
    }
    
    PodcastPremium pp1("tea with bob", "hbo", "bob the drag queen", lista_epis_p,12.90);
    pp1.tocar();
    

    return 0;
}

/*perguntas pro prof:

-qual a diferença de caminhoArquivo e URL
-pq lista_epis não é um vetor de ponteiros?
-era bom ter um bool para diferenciar Podcast Normal e Podcast Premium? 
-nao dá pra colocar um objeto PodcastPremium
*/