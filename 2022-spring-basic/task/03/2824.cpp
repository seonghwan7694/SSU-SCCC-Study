#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX_NUM 1'000'000'000ll
ll N, M, ans = 1, tmp;
bool flag = false;
map<ll, ll> nm, mm;

// 최대 공약수 -> 두 수에서 공통적으로 가지고 있는 소수

void func(map<ll, ll> &m, ll v){
  for(ll i = 2; i * i <= v; i++){
    while(v % i == 0){
      m[i]++;
      v /= i;
    }
  }
  if(v != 1) m[v]++;
  return;
}
int main(){
  ios::sync_with_stdio(false);
  cin >> N;
  while(N--){
    cin >> tmp;
    func(nm, tmp);
  }
  cin >> M;
  while(M--){
    cin >> tmp;
    func(mm, tmp);
  }
  for(auto iter = nm.begin(); iter != nm.end(); iter++){
    auto iter2 = mm.find(iter->first);
    auto v = min(iter->second, iter2->second);
    if(iter2 == mm.end()) continue;
    while(v--){
      ans *= iter->first;
      if(ans >= MAX_NUM) ans %= (ll) MAX_NUM, flag = true;
    }
  }

  if(flag){
    string str = to_string(ans);
    for(int i = 0; i < 9 - str.length(); i++) cout << "0";
  }
  cout << ans << "\n";
  return 0;
}