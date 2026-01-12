#ifndef SARKIPROGRAMI_PLAYLIST_H
#define SARKIPROGRAMI_PLAYLIST_H
#include <iostream>
#include "Node.h"
using namespace std;
class Playlist {
private:
    Node* head;
    Node* current;
    bool isRepeat;

public:
    Playlist();
    ~Playlist();

    void addSong(Song song);
    bool removeSong(string title);
    void playCurrent();
    void nextSong();
    void prevSong();
    void toggleRepeat();
    void printPlaylist();
    bool getRepeatStatus() {
        return isRepeat;
    }
    Node* getCurrent() const {
        return current;
    }
};

#endif //SARKIPROGRAMI_PLAYLIST_H