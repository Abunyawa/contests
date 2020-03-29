#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define abu ios_base::sync_with_stdio(0)
#define said cin.tie(0)
using namespace std;

void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}

/*
(n-1)+(m-1)+
n*m - 1 

*/
const ll MOD = 998244353;
int binPow (int a, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return (binPow (a, n-1) * a)%MOD;
	else {
		int b = binPow (a, n/2)%MOD;
		return (b * b)%MOD;
	}
}
void solve(){
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        if(i==n){
            cout<<10<<' ';
        }else{
            ll ans = ((n+1-i-2)*9*9 * binPow(10,n-i-1))+(2*9 * binPow(10,n-i));
            cout<<(ans)%MOD<<' '; 
        }
    }
    cout<<endl;
}

int main(){
    abu;
    said;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
