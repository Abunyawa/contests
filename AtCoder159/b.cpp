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
    cout<<"Yes"<<endl;
}

void no(){
    cout<<"No"<<endl;
}

void solve(){
    string s;
    cin>>s;
    int n=s.length();
    int l=0, r = n-1;
    while(l<=r && s[l]==s[r]){
        l++;r--;
    }
    if(l<r){
        no();
        return;
    }else{
        l=0;
        r=(n-1)/2-1;
        while(l<=r && s[l]==s[r]){
            l++;r--;
        }
        if(l<r){
            no();
            return;
        }else{
            yes();
            return;
        }
    }
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
