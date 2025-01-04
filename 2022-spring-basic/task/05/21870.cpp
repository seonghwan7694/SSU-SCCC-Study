#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll N, A[200'001];

ll GCD(ll a, ll b){
  ll r;
  while(b != 0){
    // GCD(a, b) = GCD(b, a % b);
    r = b;
    b = a % b;
    a = r;
  }
  return a;
}

ll mGCD(int l, int r){
  ll ret = A[l];
  for(int idx = l + 1; idx <= r; idx++){
    ret = GCD(ret, A[idx]);
  }
  return ret;
}

ll Divide(int l, int r){
  if(l == r){
    return A[l];
  }
  ll S = r - l + 1;
  ll L = l + floor(S/2.0) - 1, R = r - ceil(S/2.0) + 1; // [l부터 L까지 선택] vs [R부터 r까지 선택]

  ll t1 = mGCD(l, L) + Divide(R, r);
  ll t2 = mGCD(R, r) + Divide(l, L);
  return max(t1, t2);
}

int main(){
  ios::sync_with_stdio(false);
  cin >> N;
  for(int i = 1; i <= N; i++) cin >> A[i];
  cout << Divide(1, N) << "\n";
  return 0;
}