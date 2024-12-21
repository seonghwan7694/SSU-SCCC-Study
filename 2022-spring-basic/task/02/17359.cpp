#include <bits/stdc++.h>
using namespace std;

int N, res = (1 << 31) - 1;
vector<string> v;
vector<int> idx;

int func(string &str){
  int tmp_res = 0;
  for(int i = 1; i < str.length(); i++){
    if(str[i] != str[i-1]) tmp_res++;
  }
  return tmp_res;
}
int main(){
  ios::sync_with_stdio(false);
  cin >> N;
  for(int i = 0; i < N; i++){
    string str;
    cin >> str;
    v.push_back(str);
    idx.push_back(i);
  }
  do{
    string str;
    for(int i = 0; i < N; i++) str += v[idx[i]];
    res = min(res, func(str));
  }while(next_permutation(idx.begin(), idx.end()));
  cout << res << "\n";
  return 0;
}