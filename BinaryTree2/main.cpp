#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main() {
    BinaryTree tree;

    int n;
    cout << "kac adet sayi keleyceksiniz: ";
    cin >> n;
    cout<< n<<" sayiyi giriniz: ";

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tree.insert(x);
    }

    cout <<"\n inorder: "<<endl;
    tree.printInorder();

    cout <<"preorder "<<endl;
    tree.printPreorder();

    cout <<"postorder "<<endl;
    tree.printPostorder();

    return 0;
}