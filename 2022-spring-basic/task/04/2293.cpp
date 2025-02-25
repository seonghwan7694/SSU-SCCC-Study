#include <bits/stdc++.h>
using namespace std;

int n, k, D[2][10101], A[111];

int main(){
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for(int i = 1; i <= n; i++){
    cin >> A[i];
  }
  D[0][0] = 1;
  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= k; j++) D[i%2][j] = 0;
    for(int j = 0; j <= k; j++){
      for(int c = 0; j - c * A[i] >= 0; c++){
        D[i%2][j] += D[(i-1)%2][j-c*A[i]];
      }
    }
  }
  cout << D[n%2][k] << "\n";
  return 0;
}