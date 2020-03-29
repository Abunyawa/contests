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
const ll MOD = 998244353;
void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}
int findPalLeft(string s,int l,int r){
    int locL = l;
    int ans = 0;
    for(int i=r;i>=l;i--){
        int tmp = i;
        while(s[locL]==s[tmp]){
            locL++;
            tmp--;
        }
        if(locL>=tmp){
            ans+=i-l+1;
            break;
        }
        locL = l;
    }
    return ans;
}
int findPalRight(string s,int l,int r){
    int locR = r;
    int ans = 0;
    for(int i=l;i<=r;i++){
        int tmp = i;
        while(s[locR]==s[tmp]){
            locR--;
            tmp++;
        }
        if(locR<=tmp){
            ans+=r-i+1;
            break;
        }
        locR = r;
    }
    return ans;
}

void solve(){
    string s;
    cin>>s;
    int n = s.length();
    int l=0,r=n-1;
    while(l<r && s[l]==s[r]){
        l++;
        r--;
    }
    int lp =findPalLeft(s,l,r);
    int rp = findPalRight(s,l,r);
    if(lp>rp){
        for(int i=0;i<l;i++){
            cout<<s[i];
        }
        for(int i=l;i<l+lp;i++){
            cout<<s[i];
        }
        for(int i=r+1;i<n;i++){
            cout<<s[i];
        }
        cout<<endl;
    }else{
        for(int i=0;i<l;i++){
            cout<<s[i];
        }
        for(int i=r-rp+1;i<=r;i++){
            cout<<s[i];
        }
        for(int i=r+1;i<n;i++){
            cout<<s[i];
        }
        cout<<endl;
    }

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