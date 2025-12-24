#include <iostream>
#include <string.h>
using namespace std;

int main(){
    string a; getline(cin, a);
    string s = "";

    for(int i=0; i<(int)a.length(); i++){
        if(a[i] != ' ') s += a[i];
    }

    for(int n=1; n<=(int)s.length(); n++){
        for(int i=0; i<n; i++) cout << s[i];
        cout << endl;
    }

    for(int n=(int)s.length()-1; n>=1; n--){
        for(int i=0; i<n; i++) cout << s[i];
        cout << endl;
    }
    return 0;
}