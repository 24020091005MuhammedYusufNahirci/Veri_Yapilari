#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;
    int choice;
    int value;

    while (true) {
        // Menü
        std::cout << "\n--- Queue Menu ---\n";
        std::cout << "1. Kuyruga eleman ekle (enqueue)\n";
        std::cout << "2. Kuyruktan eleman cikar (dequeue)\n";
        std::cout << "3. Kuyrugun basindaki elemani goster\n";
        std::cout << "4. Kuyrugun boyutunu goster\n";
        std::cout << "5. cikis\n";
        std::cout << "Seciminiz: ";
        std::cin >> choice;

        switch(choice) {
            case 1:
                std::cout << "Eklemek istediginiz sayiyi girin: ";
                std::cin >> value;
                q.push(value);
                std::cout << value << " kuyruga eklendi.\n";
                break;
            case 2:
                if (!q.empty()) {
                    std::cout << "Cikarilan: " << q.front() << std::endl;
                    q.pop();
                } else {
                    std::cout << "Kuyruk bos!\n";
                }
                break;
            case 3:
                if (!q.empty()) {
                    std::cout << "Kuyrugun başindaki eleman: " << q.front() << std::endl;
                } else {
                    std::cout << "Kuyruk bos!\n";
                }
                break;
            case 4:
                std::cout << "Kuyrugun boyutu: " << q.size() << std::endl;
                break;
            case 5:
                std::cout << "Cikis yapiliyor...\n";
                break;
            default:
                std::cout << "Gecersiz secim! Tekrar deneyin.\n";
        }

    }

}
