#include <iostream>
#include<vector>
#include<unordered_map>;
using namespace std;

int maxDistance(vector<int> & arr) {
    int res=0;
    for(int i=0;i<arr.size();i++) {
        for(int j=i+1;j<arr.size();j++) {
            if(arr[i]==arr[j]) {
                res=max(res,j-i);
            }
        }
    }
    return res;
}

int MaxDistance(vector<int> & arr) {
    //sayı->ilk görüldüğü indeks
    unordered_map<int,int> mp;
    int res=0;
    for(int i=0;i<arr.size();i++) {
        //eğer eleman yoksa(ilk kez görülüyorsa)
        if (mp.find(arr[i])==mp.end()) {
            mp[arr[i]]=i;
        }//daha önce görülmüş ise
        else {
            //fark
            res=max(res,i- mp[arr[i]]);
        }
    }
    return res;
}


int main() {
    vector<int> arr={1,2,4,1,3,4,2,5,6,5};
    cout<<maxDistance(arr)<<endl;
    cout<<MaxDistance(arr)<<endl;
    return 0;
}