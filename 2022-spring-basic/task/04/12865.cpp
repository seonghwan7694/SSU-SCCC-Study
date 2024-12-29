#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

ll N, K, W, V, dp[2][101'101];
// dp[i][j] = {1..i번째 물건을 적당히 선택해서 무게의 합이 j일때 가능한 가치의 최댓값}
// dp[i][j] = dp[i-1][j] (i번째 물건을 선택하지 않는 경우)
// dp[i][j] = dp[i][j - Wi] + Vi (i번째 물건을 선택하는 경우)

vector<pll> v;

int main(){
  ios::sync_with_stdio(false);

  cin >> N >> K;
  v.push_back({0, 0}); // 1-based
  for(int i = 0; i < N; i++){
    cin >> W >> V;
    v.push_back({W, V});
  }
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= K; j++){
      auto [w, c] = v[i];
      if(j - w >= 0) dp[i%2][j] = max(dp[(i-1)%2][j], dp[(i-1)%2][j-w]+c);
      else dp[i%2][j] = dp[(i-1)%2][j];
    }
  }
  cout << dp[N%2][K] << "\n";
  return 0;
}