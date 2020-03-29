#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pii pair<int, int>
using namespace std;

void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}
ll c[100100];


ll t[100100];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,k;
	cin>>n>>m>>k;
	vector<ll> a(n+1);
	vector<ll> l(m+1);
	vector<ll> r(m+1);
	vector<ll> d(m+1);
	for(int i=1;i<n+1;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>l[i]>>r[i]>>d[i];
	}
	for(int i=0;i<k;i++){
		int l,r;
		cin>>l>>r;
		t[l]++;
		t[r+1]--;
	}
	for(int i = 1;i<=m;i++){
		t[i]+=t[i-1];
		c[l[i]]+=t[i]*d[i];
		c[r[i]+1]-=t[i]*d[i];
	}
	for(int i = 1;i<=n;i++){
		c[i]+=c[i-1];
		cout<<a[i]+c[i]<<' ';
	}
	cout<<endl;
    return 0;
}