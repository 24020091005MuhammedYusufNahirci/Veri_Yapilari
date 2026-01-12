#ifndef SARKIPROGRAMI_SONG_H
#define SARKIPROGRAMI_SONG_H
#include <string>

using namespace std;
//basit şarkı ismi ve artist tutma
struct Song {
    string title;
    string artist;

    Song() {}
    Song(string t, string a) : title(t), artist(a) {}
};

#endif //SARKIPROGRAMI_SONG_H
