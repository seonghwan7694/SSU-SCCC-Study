#include <bits/stdc++.h>
using namespace std;

int n, k, p[10101];
// p[가치] = 경우의 수
// p[가치] += p[가치 - 동전1];

vector<int> v;
int main(){
  ios::sync_with_stdio(false);
  cin >> n >> k;
  v.resize(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
    p[v[i]] = 1;
  }
  for(int i = 1; i <= k; i++){
    for(int j = 0; j < n; j++){
      if(i - v[j] <= 0) continue;
      p[i] += p[i - v[j]];
    }
  }

  cout << p[k] << "\n";
  return 0;
}