#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int n, m, k;
int a[50];
vector<long long> P[50], Q[50];

void Sinh1(int i, int j, int h, long long w, vector<long long> P[50]) {
    if (i > h) {
       P[j].push_back(w);
    } else {
        for (int c = 0; c < 2; c++) {
            Sinh1(i + 1, j + c, h, w + a[i] * c, P);
        }
    }   
}

int main () {
    while(scanf("%d%d", &n, &m) == 2) {
        long long ans = 0;
        scanf("%d", &k);
        for (int i = 1; i <= k; ++i) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < 50; ++i) {
            Q[i].clear();
            P[i].clear();
        }
        Sinh1(1, 0, k / 2, 0, P);
        Sinh1(k / 2 + 1, 0, k, 0, Q);
        for (int i = 0; Q[i].size(); ++i) sort(Q[i].begin(), Q[i].end());
        for (int i = 0; P[i].size(); ++i) {
            for (vector<long long>::iterator it1 = P[i].begin(); it1 != P[i].end(); ++it1) {
                for (int j = 0; j <= n - i && Q[j].size(); ++j) {
                    vector<long long>::iterator it2 = upper_bound(Q[j].begin(), Q[j].end(),m -  *it1);
                    if (it2 != Q[j].begin()) ans = max (ans, *(it2 - 1) + *it1);
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
