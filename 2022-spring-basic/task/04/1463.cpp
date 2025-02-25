#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N, D[1'000'001];

int main(){
  ios::sync_with_stdio(false);
  cin >> N;
  D[1] = 0;
  for(int i = 2; i <= N; i++){
    D[i] = D[i-1] + 1;
    if(i % 2 == 0) D[i] = min(D[i], D[i/2] + 1);
    if(i % 3 == 0) D[i] = min(D[i], D[i/3] + 1);
  }
  cout << D[N] << "\n";
  return 0;
}