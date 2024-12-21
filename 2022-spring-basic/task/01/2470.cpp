//
// Created by seong on 2024-12-21.
//

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N, l, r, res = (1LL << 31) - 1, ans[2]; // N = 100'000
vector<ll> v;

// NlongN algorithm

int main(){
  ios::sync_with_stdio(false);

  cin >> N;
  v.resize(N);
  for(int i = 0; i < N; i++){
     cin >> v[i];
  }

  l = 0, r = N - 1;
	sort(v.begin(), v.end());

  // two pointer?
	while(l < r){
    if(res > abs(v[l] + v[r])){
   		 ans[0] = v[l];
   		 ans[1] = v[r];
   		 res = abs(v[l] + v[r]);
    }
		if(v[l] + v[r] < 0){ // v[l] is strong
			l++;
		}else{ // v[r] is strong
			r--;
		}
	}
	cout << ans[0] << " " << ans[1] << "\n";
  return 0;
}