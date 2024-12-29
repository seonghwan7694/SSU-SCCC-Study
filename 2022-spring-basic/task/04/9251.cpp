#include <bits/stdc++.h>
using namespace std;

string A, B;
// dp[i][j] = {A[0..i]와 B[0..j]의 LCS 값}
int dp[1001][1001];

int main(){
  ios::sync_with_stdio(false);
  cin >> A >> B;
  int N = A.length(), M = B.length();
  A = '#' + A, B = '#' + B;

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= M; j++){
      if(A[i] == B[j]){
        dp[i][j] = dp[i-1][j-1] + 1;
      }else{
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  cout << dp[N][M] << "\n";
  return 0;
}