#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX_K 8000000
int v[MAX_K + 1];

int main(){
  ios::sync_with_stdio(false);
  ll K;
  cin >> K;
  for(int i = 1; i <= MAX_K; i++) v[i] = i;

  for(int i = 2; i <= MAX_K; i++){
    if(v[i] == 0) continue;
    for(int j = i * 2; j <= MAX_K; j += i){
      v[j] = 0;
    }
  }

  for(int i = 2; i <= MAX_K; i++){
    if(v[i] > 0) K--;
    if(K == 0){
      cout << i << "\n";
      break;
    }
  }
  return 0;
}

