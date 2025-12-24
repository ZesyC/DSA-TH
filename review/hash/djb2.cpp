#include <iostream>
#include <string.h>

using namespace std;

unsigned long hashDJB2(string str){
    unsigned long hash = 5381;
    for (char c : str){
        hash = ((hash << 5) + hash) + c;
    }
    return hash % 1000;
}

int main(){
    int n;
    cin >> n;
    int A[1000];
    for(int i = 0; i < 1000; i++){
        A[i] = 0;
    }
    for(int i = 0; i < n; i++){
        string a;
        cin >> a;
        int hash_value = hashDJB2(a);
        while(A[hash_value] != 0){
            hash_value = (hash_value + 1) % 1000;
        }
        A[hash_value] = 1;
        cout << hash_value << " ";
    }
    return 0;
}