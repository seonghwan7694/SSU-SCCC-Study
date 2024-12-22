#include <bits/stdc++.h>
using namespace std;

int n, x, y, res;
bool vis[30];
vector<int> v;

bool func(){
  fill(vis, vis + 30, false);
  for(int i = 0; i < 2 * n; i++){
    if(vis[i] == false){
      vis[i] = true; // v[i] ... {v[i] + v[i]}
      if(i + v[i] + 1 >= 2 * n) return false;
      vis[i + v[i] + 1] = true;
      if(v[i] != v[i + v[i] + 1]) return false;
    }
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin >> n >> x >> y; x--, y--;
  for(int i = 1; i <= n; i++){
    v.push_back(i);
    v.push_back(i);
  }
  do{
    if(v[x] != v[y]) continue;
    if(func()) res++;
  }while(next_permutation(v.begin(), v.end()));
  cout << res << "\n";
  return 0;
}