#include <iostream>
#include <vector>

using namespace std;
const int N = 10000100;
int lp[N+1];
vector<int> pr;

int getBg(int n) {
	if (lp[n] == n) {
		return n;
	} else {
		return max(lp[n], getBg(n/lp[n]));
	}
}

int main() {
	// freopen("a.in", "r", stdin);

	for (int i=2; i<=N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back (i);
		}
		for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
			lp[i * pr[j]] = pr[j];
	}	

	// cout << getBg(7) << endl;
	int ans = N+1;
	int n;
	cin >> n;
	for (int i = n - getBg(n)+1; i <= n; i++) {
		// cout << i << endl;
		int bg = getBg(i);
		if (bg < i) {
			ans = min(ans, i-bg+1);	
		}
	}
	cout << ans << endl;
	return 0;
}
