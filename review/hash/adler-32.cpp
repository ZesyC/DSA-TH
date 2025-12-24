#include <iostream>
#include <string.h>
using namespace std;

unsigned long adler32(string &data){
    const unsigned long MOD_ADLER = 65521;
    unsigned long a = 1, b = 0;
    for (char c : data){
        a = (a + c) % MOD_ADLER;
        b = (b + a) % MOD_ADLER;
    }
    return (b << 16) | a;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        cout << adler32(s) << " ";
    }
    return 0;
}