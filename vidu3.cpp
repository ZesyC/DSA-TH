#include <iostream>
#include <string>

using namespace std;

int main() {
    string s; getline(cin, s);
    string c; cin >> c;
    int n = c.length();
    int dem = 0;
    string word = "";
    for(int i=0; i<s.size(); i++){
        if(i==s.size() || s[i]==' ' || s[i]=='\n'){
            if(word == c) dem++;
            word = "";
        }
        else word += s[i];
    }
    cout << dem;
    return 0;
}
