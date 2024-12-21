//
// Created by seong on 2024-12-21.
//

#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll K, N, l = 0, r = 1LL << 32, ans;
vector<ll> lan;

int main() {
  cin >> K >> N;
  for(int i = 0, t; i < K; i++){
     cin >> t;
     lan.push_back(t);
  }

  while(l <= r){ // 구간 [l, r]에서 f(res) >= N 을 만족하는 최대의 res 값 찾기
    ll m = (l + r) >> 1;
    ll res = 0;
    for(auto &x : lan){
    	  res += x / m;
    }
    if(res < N){ // m보다 덜 잘라야함
      r = m - 1;
    }else{ // m으로 잘라도 되고, 더 길게 잘라도됨..
      l = m + 1;
      ans = max(ans, m);
    }
  }
  cout << ans << "\n";
  return 0;
}