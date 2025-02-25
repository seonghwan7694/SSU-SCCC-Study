#include <bits/stdc++.h>
using namespace std;
int N, D[1'000'001], pre[1'000'001];

int main(){
  ios::sync_with_stdio(false);
  cin >> N;
  fill(D, D + 1'000'001, 987654321);
  D[1] = 0, D[2] = 1, pre[2] = 1;

  for(int i = 2; i <= N; i++){
    if(i % 2 == 0){
      if(D[i] > D[i/2] + 1){
        D[i] = D[i/2] + 1;
        pre[i] = i/2;
      }
    }
    if(i % 3 == 0){
      if(D[i] > D[i/3] + 1){
        D[i] = D[i/3] + 1;
        pre[i] = i/3;
      }
    }
    if(D[i] > D[i-1] + 1){
      D[i] = D[i-1] + 1;
      pre[i] = i-1;
    }
  }
  cout << D[N] << "\n";
  cout << N << " ";
  for(int i = pre[N]; i != 0; i = pre[i]) cout << i << " ";
  return 0;
}