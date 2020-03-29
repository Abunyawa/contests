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

ll toN(string x){
    ll n =0;
    for(int i=0;i<x.length();i++){
        n+=pow(9,x.length()-1-i)*(int)(x[i]-'0');
    }
    return n;
}
void solve(){
    string r;
    string l;
    cin>>l>>r;
    cout<<toN(r)-toN(l)+1<<endl;

}

int main(){
    abu;
    said;
    int t = 1;
    while(t--){
        solve();
    }

    return 0;
}