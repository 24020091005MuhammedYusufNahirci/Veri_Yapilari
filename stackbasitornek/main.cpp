#include<iostream>
#include<stack>
using namespace std;

void printStack(stack<int> s) {
    if(s.empty()) {
        cout<<"Stack bos"<<endl;
        return;
    }
    cout<<"stack:";
    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main() {
    stack<int> s;
    int secim,value;

    while (true) {
        cout<<"STACK MENU"<<endl;
        cout<<"1. push(elelman ekleme)"<<endl;
        cout<<"2. pop(eleman silme)"<<endl;
        cout<<"3. top (tepedeki eleman)"<<endl;
        cout<<"4. stack yazdirma"<<endl;
        cout<<"5. stack boyutu"<<endl;
        cout<<"6. Cikis"<<endl;
        cout<<"yapmak istediginiz islemi giriniz.";
        cin>>secim;

        switch (secim){
            case 1:
                cout<<"eklenecek deger";
                cin>>value;
                s.push(value);
                cout<<"stacke eklendi";
                break;

            case 2:
                if (s.empty())
                    cout << "Stack bos, pop yapilamaz!\n";
                else {
                    cout << s.top() << " stack'ten silindi.\n";
                    s.pop();
                }
                break;

            case 3:
                if (s.empty())
                    cout << "Stack bos!\n";
                else
                    cout << "Top eleman: " << s.top() << "\n";
                break;

            case 4:
                printStack(s);
                break;

            case 5:
                cout << "Stack boyutu: " << s.size() << "\n";
                break;

            case 6:
                cout << "Program sonlandi.\n";
                return 0;

            default:
                cout << "Gecersiz secim!\n";
                break;
        }
    }
}