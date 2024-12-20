//
// Created by seong on 2024-12-21.
//

#include <bits/stdc++.h>
using namespace std;

int N, M, t;
set<int> s;

int main(){
  ios::sync_with_stdio(false);
 	cin >> N;
  for(int i = 0; i < N; i++){
    cin >> t;
    s.insert(t);
  }
  cin >> M;
  while(M--){
    cin >> t;
    if(s.find(t) == s.end()) cout << 0 << "\n";
    else cout << 1 << "\n";
  }
  return 0;
}
