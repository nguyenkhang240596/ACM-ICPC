#include <bits/stdc++.h>

using namespace std;

int main() {    
    cin.tie(0);

    string a[100];
    int current_site = 0;
    int max_size = 1;
    string cmd,site;
    a[0] = "http://www.acm.org/";
    while(cin >> cmd && cmd != "QUIT") {
        if (cmd == "BACK") {
            if (current_site - 1 >= 0) {
                cout << a[--current_site] << endl;
            } else {
                cout << "Ignored" << endl;
            }
        } else if (cmd == "FORWARD") {
            if (current_site + 1 < max_size) {
                cout << a[++current_site] << endl;
            } else {
                cout << "Ignored" << endl;
            }
        } else if (cmd == "VISIT") {
           cin >> site;
           a[++current_site] = site;
           max_size = current_site+1;
           cout << site << endl;
        }
    }

    return 0;
}
