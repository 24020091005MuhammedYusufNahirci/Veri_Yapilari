#include "Playlist.h"
Playlist::Playlist() {
    head = nullptr;
    current = nullptr;
    isRepeat = false;
}

Playlist::~Playlist() {
    if (!head) return;

    Node* temp = head->next;

    while (temp != head) {
        Node* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    delete head;

    head = nullptr;
    current = nullptr;
}


void Playlist::addSong(Song song) {
    Node* newNode = new Node(song);

    if (!head) {
        head = newNode;
        head->next = head;
        head->prev = head;
        current = head;
        return;
    }

    Node* tail = head->prev;

    tail->next = newNode;
    newNode->prev = tail;

    newNode->next = head;
    head->prev = newNode;
}


bool Playlist::removeSong(string title) {
    if (!head) return false;

    Node* temp = head;

    do {
        if (temp->data.title == title) {

            if (temp == head && temp->next == head) {
                delete temp;
                head = nullptr;
                current = nullptr;
                return true;
            }

            if (temp == head)
                head = head->next;

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            if (current == temp)
                current = temp->next;

            delete temp;
            return true;
        }
        temp = temp->next;
    } while (temp != head);

    return false;
}

void Playlist::playCurrent() {
    if (!current) {
        cout << "Liste Bos" << endl;
        return;
    }

    cout << "Calan: " << current->data.title
         << " - " << current->data.artist << endl;
}

void Playlist::nextSong() {
    if (!current) return;

    if (current->next == head) {
        if (isRepeat) {
            current = head;
        } else {
            cout << "Listenin sonundasiniz.\n";
            return;
        }
    } else {
        current = current->next;
    }
}



void Playlist::prevSong() {
    if (!current) return;

    if (current == head) {
        if (isRepeat) {
            current = head->prev;
        } else {
            cout << "Listenin basindasiniz.\n";
            return;
        }
    } else {
        current = current->prev;
    }
}



void Playlist::toggleRepeat() {
    isRepeat = !isRepeat;
    cout << "Tekrar modu " << (isRepeat ? "ACIK" : "KAPALI") << endl;
}


void Playlist::printPlaylist() {
    if (!head) {
        cout << "Liste Bos" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data.title << " - " << temp->data.artist << endl;
        temp = temp->next;
    } while (temp != head);
}
