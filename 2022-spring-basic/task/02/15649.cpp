#include <bits/stdc++.h>
using namespace std;

int N, M;
bool vis[10];
vector<int> v;

void func(int m){
  if(v.size() == M){
    for(auto &x : v) cout << x << " ";
    cout << "\n";
    return;
  }

  for(int i = 1; i <= N; i++){
    if(vis[i] == false){
      vis[i] = true;
      v.push_back(i);
      func(m + 1);
      v.pop_back();
      vis[i] = false;
    }
  }
  return;
}

int main(){
  cin >> N >> M;
  func(0);
  return 0;
}