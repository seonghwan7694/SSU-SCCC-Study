//
// Created by seong on 2024-12-21.
//

#include <bits/stdc++.h>
using namespace std;

int N, x, y;
vector<pair<int, int>> v;

int main(){
  cin >> N;
  while(N--){
    cin >> x >> y;
    v.push_back({x, y});
  }
  sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
  });
  for(auto p : v){
    cout << p.first << " " << p.second << "\n";
  }
}