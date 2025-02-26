#include <bits/stdc++.h>
using namespace std;

int N;
queue<tuple<int, int, int, int>> q;
int dp[61][61][61];

tuple<int, int, int> attack[6] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 3, 9},
    {1, 9, 3}
};

int main(){
  ios::sync_with_stdio(false);
  cin >> N;
  vector<int> A(3);
  for(int i = 0; i < 61; i++) for(int j = 0; j < 61; j++) for(int k = 0; k < 61; k++) dp[i][j][k] = 10101;
  for(int i = 0; i < N; i++) cin >> A[i];

  q.push(make_tuple(A[0], A[1], A[2], 0));
  dp[A[0]][A[1]][A[2]] = 0;

  while(!q.empty()){
    auto [a1, a2, a3, cnt] = q.front(); q.pop();
    if(a1 == 0 and a2 == 0 and a3 == 0) break;

    for(int i = 0; i < 6; i++){
      auto &[b1, b2, b3] = attack[i];
      int na1 = a1 - b1 > 0 ? a1 - b1 : 0;
      int na2 = a2 - b2 > 0 ? a2 - b2 : 0;
      int na3 = a3 - b3 > 0 ? a3 - b3 : 0;
      if(dp[na1][na2][na3] == 10101){
        dp[na1][na2][na3] = cnt + 1;
        q.push(make_tuple(na1, na2, na3, cnt + 1));
      }
    }
  }
  cout << dp[0][0][0] << "\n";
  return 0;
}