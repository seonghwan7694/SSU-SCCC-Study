#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v;
bool used[10];

void func(int n, int m){
  if(m == M){
    for(auto i : v){
      cout << i << " ";
    }
    cout << "\n";
  }
  for(int i = n; i <= N; i++){
    if(used[i] == false){
      used[i] = true;
      v.push_back(i);
      func(i, m + 1);
      used[i] = false;
      v.pop_back();
    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin >> N >> M;
  func(1, 0);
}