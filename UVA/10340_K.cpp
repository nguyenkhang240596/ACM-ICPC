#include <bits/stdc++.h>

using namespace std;

int main(){
    
    string a,b;
    while(cin >> a && cin >> b) {
        int pos=0;
        for(int i=0;i<b.length();i++) {
            if (a[pos] == b[i] && pos < a.length()) {
                pos++;
            } 
        } 
        if (pos == a.length()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
