#include <bits/stdc++.h>
using namespace std;

int N, S, A[22], res;

int main(){
  ios::sync_with_stdio(false);
  cin >> N >> S;
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }
  for(int bitset = 1; bitset < (1 << N); bitset++){
    int tmp_sum = 0;
    for(int i = 0; i < N; i++){
      if(bitset & (1 << i)) tmp_sum += A[i];
    }
    if(tmp_sum == S) res++;
  }
  cout << res << "\n";
  return 0;
}