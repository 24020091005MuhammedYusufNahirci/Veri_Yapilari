#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main() {
    BinaryTree tree;
    int n, val, target;

    cout << "Kac sayi eklemek istiyorsunuz?: ";
    cin >> n;

    cout << "Sayilari girin:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        tree.insert(val);
    }

    cout << "\nBST inorder: ";
    tree.printInorder();

    cout << "Hedef toplam sayiyi girin: ";
    cin >> target;

    if (!tree.findPairWithSum(target))
        cout << "Boyle bir pair yok.\n";

    return 0;
}
