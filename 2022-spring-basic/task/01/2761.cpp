//
// Created by seong on 2024-12-21.
//

#include <bits/stdc++.h>
using namespace std;

int N, t;
vector<int> v;

int main(){
    cin >> N;
    while (N--) {
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    for (auto &x : v) cout << x << "\n";
    return 0;
}