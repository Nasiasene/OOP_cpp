#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Music{
    protected:
        string title, artist;
        void play_intro(){
            cout << "Will start playing !";
        }

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

class Podcast : public Music{
    string presenter;
    vector<string> episodes;

    public:
        Podcast(string tt, string aa, string pp) : Music(tt, aa), presenter{pp} {}

        void add_ep(string ep){episodes.push_back(ep);}

        void play() override{
            this->play_intro();
            cout << "Title: " << Music::title << "\nPodcast: " << Music::artist << "\nPresenter: " << presenter << endl;
            cout << "Episode List: ";
            for (auto x : episodes)
                cout << "\n- " << x;
        }

        void play_intro(){
            Music::play_intro();
            cout << " Welcome our Host " << presenter << " !" << endl;
        }   
};

class PodcastPremium : private Podcast{
    double price;

    public:
        PodcastPremium(string tt, string aa, string pp, double pr) : Podcast{tt, aa, pp}, price{pr} {}

        void add_ep(string ep){Podcast::add_ep(ep);}

        void play() override{
            Podcast::play();
        }
};

int main(){
    StreamingMusic music1("Walk", "Foo Fighters", "www.youtube/walk");
    StreamingMusic music2("The Wall", "Pink Floyd", "www.spotfy/pinkfloyd");
    LocalMusic music3("Vamos Fugir", "Skank", "C://downloads/skank");
    LocalMusic music4("Ela e' amiga da minha mulher", "Seu Jorge", "C://downloads/seu-jorge");
    Podcast pod1("Chatting with an apple!", "Flow Podcast", "Igor3k");
    pod1.add_ep("EP1");
    pod1.add_ep("EP2");
    PodcastPremium pod2("RPG cthullu!", "Jovem Nerd", "Azaghal/Jovem Nerd", 22);
    pod2.add_ep("Episode-0");
    pod2.add_ep("Episode-1");
    pod2.add_ep("Episode-2");

    vector<Music*> musics;

    musics.push_back(&music1);
    musics.push_back(&music2);
    musics.push_back(&music3);
    musics.push_back(&music4);
    musics.push_back(&pod1);
    //musics.push_back(&pod2); //It is clear that as a private podcast inheriter, a premium podcast WILL NOT BE A MUSIC

    for(auto i : musics){
        i->play();
        cout << endl << endl;
    }
}