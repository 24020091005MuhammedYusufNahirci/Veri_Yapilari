#include <iostream>
#include <vector>
using namespace std;
const int TABLE_SIZE = 11;

void printTable(const vector<int>& table, string method) {
    cout<<"   "<<method<<"sonuc tablosu ---"<<endl;
    for (int i=0;i<TABLE_SIZE;i++) {
        if (table[i] != -1) {
            cout<<"["<<i<<"]"<<table[i]<<endl;
        }
        else {
            cout<<"["<<i<<"]:Bos"<<endl;
        }
    }
    cout<<endl;
}

void linearProbing(const vector<int>& data) {
    vector<int> table(TABLE_SIZE,-1);
    for (int key:data) {
        int index=key%TABLE_SIZE;
        while (table[index]!=-1) {
            index = (index+1)%TABLE_SIZE;
        }
        table[index]=key;
    }
    printTable(table,"linearProbing");
}

void quadraticProbing(const vector<int>& data) {
    vector<int> table(TABLE_SIZE,-1);
    for (int key:data) {
        int hashVal= key%TABLE_SIZE;
        int i=0;
        int index=hashVal;
        while (table[index]!=-1) {
            i++;
            index=(hashVal+i*i)%TABLE_SIZE;
        }
        table[index]=key;
    }
    printTable(table,"quadraticProbing");
}

int main() {
    vector<int> inputs= {12,25,45,14,1};
    cout<<"inputs:(12,25,45,14,1)\n"<<endl;
    linearProbing(inputs);
    quadraticProbing(inputs);
    return 0;
}