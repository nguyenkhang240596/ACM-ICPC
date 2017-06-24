#include <iostream>

using namespace std;

int main() {
    int n;
    int sx, sy, sz;
    sx = sy = sz = 0;
    int x,y,z;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> x >> y >> z;
        sx += x;
        sy += y;
        sz += z;
    }
    if (sx == 0 && sy == 0 && sz == 0) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
