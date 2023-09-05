#include <iostream>
#include <list>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::list;

class YoutubeChannel{
    private: //these attributes should be private
    string Name;
    string OwnerName;
    int SubscribersCount;
    list<string> PublishedVideoTitles;

public://exposure of public methods
     // Constructor
    YoutubeChannel(string name, string owNa) : Name(name), OwnerName(owNa), SubscribersCount(0) {
        // Inicializa SubscribersCount a 0 y la lista PublishedVideoTitles está vacía por defecto.
    }

    //getters and setters

    void get_info(){
        cout << "Name: " << Name << endl;
        cout << "OwnerName: " << OwnerName << endl;
        cout << "SubscribersCount: " << SubscribersCount << endl;
        cout << "Videos: " << endl;
        for(string videoTitle: PublishedVideoTitles){
            cout << videoTitle << endl;
        }
    }
    void Subscribe(){
        SubscribersCount++;
    }
    void Unsubscribe(){
        if(SubscribersCount > 0)
        SubscribersCount--;
    }
    void PublishVideo(string title){
        PublishedVideoTitles.push_back(title);
    }
};


int main(){
    YoutubeChannel ytChannel("CodeBeauty", "Saldina");

    ytChannel.PublishVideo("C++ for beginners");

    //ytChannel.Subscribe();
    ytChannel.Unsubscribe();
    ytChannel.get_info();
    //ytChannel.Published

    return 0;
}