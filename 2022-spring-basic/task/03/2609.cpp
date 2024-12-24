#include <bits/stdc++.h>
using namespace std;
int A, B;

int GCD(int a, int b){
  while(true){
    int r = b;
    b = a % b;
    a = r;
    if(b == 0) break;
  }
  return a;
}

int main(){
  ios::sync_with_stdio(false);
  cin >> A >> B;
  if(A < B) swap(A, B);
  cout << GCD(A, B) << "\n";
  cout << A * B / GCD(A, B) << "\n";
  return 0;
}