#include <bits/stdc++.h>
using namespace std;

int N;

void hanoi_move(int n, int a, int b, int c){ // move n-blocks from 'a' to 'c' using 'b'
  if(n == 1){
    cout << a << " " << c << "\n";
    return;
  }

  hanoi_move(n-1, a, c, b); // a 위에 있는 n-1에 블럭을 c를 경유해 b로 옮긴다. -> 가능
  hanoi_move(1, a, b, c);
  hanoi_move(n-1, b, a, c);  // b에 있던 블럭 n-1개를 a를 경유해 c로 옮긴다.
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin >> N;
  cout << (1 << N) - 1 << "\n";
  hanoi_move(N, 1, 2, 3);
  return 0;
}