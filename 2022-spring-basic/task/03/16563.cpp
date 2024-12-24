#include <bits/stdc++.h>
using namespace std;
#define ll int
#define MAX_k 5000505
ll N, K, k;
bool isPrime[MAX_k + 100];
vector<ll> Prime;

void func(){

  for(int i = 0; i < Prime.size(); i++){
   while(k != 1){
     while(k % Prime[i] == 0){
       k /= Prime[i];
       cout << Prime[i] << " ";
     }
   }
  }
   cout << "\n";
}

int main(){
  ios::sync_with_stdio(false);
  for(int i = 2; i <= MAX_k; i++) isPrime[i] = true;
  for(int i = 2; i <= MAX_k; i++){
    if(!isPrime[i]) continue;
    for(int j = i * 2; j <= MAX_k; j += i){
      isPrime[j] = false;
    }
  }
  for(int i = 2; i <= MAX_k; i++){
   if(isPrime[i]) Prime.push_back(i);
  }

  cin >> K;
  while(K--){
    cin >> k;
    func();
  }
  return 0;
}