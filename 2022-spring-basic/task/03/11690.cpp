#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define MOD (1ull << 32)
ll n;
// lcm(1, ..., n) = lcm(n, lcm(n-1, ... lcm(2, 1)))
ll lcm(ll a, ll b){
  return ((a / gcd(a, b)) * b);
}

int main(){
  ios::sync_with_stdio(false);
  cin >> n;
  ll ans = 1;
  for(ll i = 2; i <= n; i++){
    ans = lcm(ans, i);
  }
  cout << ans % MOD << "\n";
  return 0;
}