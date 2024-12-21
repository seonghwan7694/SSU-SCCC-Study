#include <bits/stdc++.h>
using namespace std;

int N, res = (1 << 31);
vector<int> v;

int main(){
  ios::sync_with_stdio(false);
  cin >> N;
   v.resize(N);
  for(int i = 0; i < N; i++){
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  while(next_permutation(v.begin(), v.end())){
      int tmp_res = 0;
      for(int i = 1; i < N; i++) tmp_res += abs(v[i] - v[i-1]);
      res = max(res, tmp_res);
  }
  cout << res << "\n";
	return 0;
}