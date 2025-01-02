#include <bits/stdc++.h>
using namespace std;
#define MAX_N 500'000
unsigned long long int ret;
int N, A[MAX_N], tmp[MAX_N];

void Merge(int l, int m, int r){
  int i = l, j = m + 1, idx = l;
  while(i <= m and j <= r){
    if(A[i] <= A[j]){
      tmp[idx++] = A[i++];
    }else{
      ret += (m - i + 1);
      tmp[idx++] = A[j++];
    }
  }
  while(i <= m) tmp[idx++] = A[i++];
  while(j <= r) tmp[idx++] = A[j++];
  for(int k = l; k <= r; k++) A[k] = tmp[k];
  return;
}

void Sort(int l, int r){
   if(l == r) return;
   int m = (l + r) >> 1;
   Sort(l, m);
   Sort(m + 1, r);
   Merge(l, m, r);
   return;
}
int main(){
  ios::sync_with_stdio(false);
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }
  Sort(0, N - 1);
  cout << ret << "\n";
  return 0;
}