#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> stockSpan(vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n);
    stack<int> st; // gün indeksi tutuyor

    for (int i = 0; i < n; i++) {

        // stackteki fiyatlar mevcut fiyattan küçükse çıkar
        while (!st.empty() && prices[st.top()] <= prices[i]) {
            st.pop();
        }

        // eğer stack boşsa tüm önceki günler daha küçük
        if (st.empty()) {
            span[i] = i + 1;
        } else {
            span[i] = i - st.top();
        }
        // günü stacke ekle
        st.push(i);
    }

    return span;
}

int main() {
    vector<int> arr = {1, 2, 3, 120, 90, 300};
    vector<int> result = stockSpan(arr);

    cout << "span sonuclari: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
