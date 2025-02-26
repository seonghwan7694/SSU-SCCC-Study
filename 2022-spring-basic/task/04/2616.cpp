#include <bits/stdc++.h>
using namespace std;
// n log n -> 누적 합을 저장해두기
// n^3 순간 망해버림
int N, tmp, M, SUM[50505], dp[4][50505]; // dp[i][n] = max(dp[i][n-1], dp[i-1][j-K] + SUM[j] - SUM[j-K]
int main(){
  ios::sync_with_stdio(false);
  cin >> N;
  for(int i = 1; i <= N; i++){
    cin >> tmp;
    SUM[i] = SUM[i-1] + tmp;
  }
  cin >> M;
  for(int i = 1; i <= 3; i++){
    for(int j = i * M; j <= N; j++){
      dp[i][j] = max(dp[i][j-1], dp[i-1][j-M] + SUM[j] - SUM[j-M]);
    }
  }
  cout << dp[3][N] << "\n";
  return 0;
}