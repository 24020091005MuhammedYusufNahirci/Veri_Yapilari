#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
//eleman ekleme
    q.push(1);
    q.push(2);
    q.push(30);
//kuyruk boyutu
    std::cout <<"kuyrugun boyutu: "<< q.size() <<std::endl;
    //eleman çıkarma
    std::cout<< "cikarilan: "<<q.front()<<std::endl;
    q.pop();

    std::cout<<"cikarilan: "<<q.front()<<std::endl;
    q.pop();
//kuyurugun kalan kisimlarini cikarma
    while(!q.empty()) {
        std::cout<<"kuruktan cikarilan: " <<q.front()<<std::endl;
        q.pop();
    }

    return 0;
}