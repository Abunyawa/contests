#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<long long, long long>
using namespace std;


void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        vector<int> p(m+1);
        vector<ll> ds(n+1,0);
        for(int i=0;i<m;i++){
            cin>>p[i];
            ds[p[i]]-=1;
        }
        vector<ll> ctr(26,0);
        ll cur = m+1;
        for(int i =0;i<n;i++){
            cur += ds[i];
            ctr[(int)(s[i]-'a')]+=cur;
        }

        for(int i=0;i<26;i++){
            cout<<ctr[i]<<' ';
        }
        cout<<endl;
    }


    return 0;
}