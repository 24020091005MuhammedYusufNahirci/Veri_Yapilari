#include <chrono>
#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    stack<int> s;//int tipinde stack
//eleman pushlama
    cout << "eleman ekleme" << endl;
    s.push(1);
    s.push(2);
    std::cout<<"2 sayi eklendi"<<std::endl;
    std::cout<<"eklemek istediginiz sayiyi ekleyiniz"<<std::endl;
    cin>>n;
    s.push(n);
    std::cout<<"yazdiginiz eleman eklendi"<<std::endl;
//top
    cout<<"tepedeki eleman(top)"<<s.top()<<endl;
//eleman cikarma
    cout << "Eleman cikarma (pop): " << s.top() << " silindi.\n";
    s.pop();
    std::cout << "yeni top:"<< s.top() << std::endl;
//boyut
    std::cout<<"stack boyutu:"<< s.size()<<std::endl;
//stack yazdırma
    std::cout<<"stack (top->bottom):";
    stack<int> temp=s;
    while(!temp.empty()) {
        cout<<temp.top()<<" ";
        temp.pop();
    }
    cout<<std::endl;
//stack bos mu kontrolu
    if (s.empty()){
        cout<<"stack bos"<<std::endl;
    }
    else {
        cout<<"stack bos degil"<<std::endl;
    }

    return 0;
}