#include <bits/stdc++.h>
using namespace std;
int N, ret;
vector<pair<int, int>> v;
int main(){
  ios::sync_with_stdio(false);

  cin >> N;
  for(int i = 0, x, y; i < N; i++){
    cin >> x >> y;
    v.push_back({x, y});
  }
  sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b){
    if(a.first == b.first){
      return a.second < b.second;
    }
    return a.first < b.first;
  });
  auto [l, r] = v[0];
  if(N == 1){
    cout << r - l << "\n";
    return 0;
  }

  for(int i = 1; i < N; i++){
    if(v[i].first <= r){
      r = max(r, v[i].second);
    }else{
      ret += r - l;
      l = v[i].first;
      r = v[i].second;
    }
  }
  ret += r - l;
  cout << ret << "\n";
  return 0;
}