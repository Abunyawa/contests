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
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

void solve(){
    string s;
    cin>>s;
    int n = s.length();
    bool fl1=0,fl2=0,fl3=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1') fl1=1;
        if(s[i]=='2') fl2=1;
        if(s[i]=='3') fl3=1;

    }
    if(!(fl1 && fl2 && fl3)){
        cout<<0<<'\n';
        return;
    }
    vi dp(n,0);
    int n1=0,n2=0,n3=0;
    int l=0,r=0;
    while(r<=n){
        while(r<n && (n1==0 || n2==0 || n3==0)){
            if(s[r]=='1') n1++;
            if(s[r]=='2') n2++;
            if(s[r]=='3') n3++;
            r++;
        }
        if(n1>0 && n2>0 && n3>0){
            dp[l] = r-l;
        }else{
            break;
        }
        if(s[l]=='1') n1--;
        if(s[l]=='2') n2--;
        if(s[l]=='3') n3--;
        l++;

    }
    int mn = n;
    for(int i=0;i<n;i++){
        if(dp[i]<mn && dp[i]!=0) mn = dp[i]; 
    }
    cout<<mn<<'\n';
}

int main(){
    abu;
    said;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
