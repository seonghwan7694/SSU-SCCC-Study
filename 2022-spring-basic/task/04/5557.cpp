#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N, ret;
vector<ll> v;
ll dp[101][21]; // dp[1..i][c] = {i번째 수까지 잘 조합하여 c가 나오는 경우}

int main(){
	ios::sync_with_stdio(false);
	cin >> N;
	v.resize(N + 1); // 1-based
	for(int i = 1; i <= N; i++){
		cin >> v[i];
	}

	dp[1][v[1]] = 1;
	for(int i = 1; i < N; i++){
		for(int c = 0; c <= 20; c++){
			if(0 <= c - v[i] and c - v[i] <= 20) dp[i][c] += dp[i-1][c - v[i]];
			if(0 <= c + v[i] and c + v[i] <= 20) dp[i][c] += dp[i-1][c + v[i]];
		}
	}

	cout << dp[N - 1][v[N]] << "\n";
	return 0;
}