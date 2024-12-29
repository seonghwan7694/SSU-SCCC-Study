#include <bits/stdc++.h>
using namespace std;

int n, k, dp[10101];
vector<int> v;
// dp[k] = {k원을 만들기 위해 사용한 동전의 최소 개수}
// dp[k] = min(dp[k - vi] + 1, dp[k])
int main(){
  ios::sync_with_stdio(false);
  cin >> n >> k;
  fill(dp, dp + 10101, 10101);
  for(int i = 0, tmp; i < n; i++){
    cin >> tmp;
    v.push_back(tmp);
  }
  v.erase(unique(v.begin(), v.end()), v.end());
  dp[0] = 0;
  for(int i = 0; i < n; i++){
    for(int j = v[i]; j <= k; j++){
      dp[j] = min(dp[j], dp[j - v[i]] + 1);
    }
  }
  cout << (dp[k] == 10101 ? -1 : dp[k]) << "\n";
  return 0;
}