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
vector<int> pr(27);
vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && (s[i] != s[j] && pr[s[j]-'a'+1]!=s[i]-'a'+1))
			j = pi[j-1];
		if (s[i] == s[j] || pr[s[j]-'a'+1]==s[i]-'a'+1)  ++j;
		pi[i] = j;
	}
	return pi;
}

void solve(){
    for(int i=1;i<=26;i++){
        cin>>pr[i];
    }
    string t;
    string s;
    cin>>t;
    cin>>s;
    vector<int> ans = prefix_function(t+'#'+s);
    for(auto e: ans){
        cout<<e;
    }
    cout<<endl;
    for(int i = t.length()+t.length();i<ans.size();i++){
        if(ans[i]==t.length()){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    cout<<'\n';
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
