#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
	for(int i = 2; i <= sqrt(n); i++){
          if(n % i == 0) return false;
	}
    return true;
}

bool isPalindrome(int n){
  string str = to_string(n);
  for(int i = 0, j = str.length() - 1; i < j; i++, j--){
    if(str[i] != str[j]) return false;
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  int a, b;
  cin >> a >> b;

  for(int i = a; i <= min(b, 10'000'000); i++){
    if(isPalindrome(i) and isPrime(i)) cout << i << "\n";
  }
  cout << -1 << "\n";
  return 0;
}