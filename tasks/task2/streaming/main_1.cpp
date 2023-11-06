#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Music{
    protected:
        string title, artist;

    public:
        Music(string tt, string aa) : title{tt}, artist{aa} {}

        virtual void play() = 0;
};

class LocalMusic : public Music{
    string path_file;

    public:
        LocalMusic(string tt, string aa, string pf) : Music(tt, aa), path_file{pf} {}

        virtual void play() override {
            cout << "Music: " << Music::title << "\nArtist: " << Music::artist << "\nPath: " << path_file;
        }
};

class StreamingMusic : public Music{
    string url;

    public:
        StreamingMusic(string tt, string aa, string uu) : Music(tt, aa), url{uu} {}

        void play(){
            cout << "Music: " << Music::title << "\nArtist: " << Music::artist << "\nURL: " << url;
        }
};



int main(){
    StreamingMusic music1("Walk", "Foo Fighters", "www.youtube/walk");
    StreamingMusic music2("The Wall", "Pink Floyd", "www.spotfy/pinkfloyd");
    LocalMusic music3("Vamos Fugir", "Skank", "C://downloads/skank");
    LocalMusic music4("Ela e' amiga da minha mulher", "Seu Jorge", "C://downloads/seu-jorge");

    vector<Music*> musics;

    musics.push_back(&music1);
    musics.push_back(&music2);
    musics.push_back(&music3);
    musics.push_back(&music4);

    for(auto i : musics){
        i->play();
        cout << endl << endl;
    }
}