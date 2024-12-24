#include <bits/stdc++.h>
using namespace std;

bool v[1010];
int N, res;

int main(){
  ios::sync_with_stdio(false);
  for(int i = 2; i <= 1000; i++){
    v[i] = i;
  }

  for(int i = 2; i <= 1000; i++){
    if(v[i] == 0) continue;
    for(int j = i * 2; j <= 1000; j += i){
      v[j] = 0;
    }
  }

  cin >> N;
  while(N--){
    int tmp;
    cin >> tmp;
    if(v[tmp] != 0) res++;
  }
  cout << res << "\n";
  return 0;
}