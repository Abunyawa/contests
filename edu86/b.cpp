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
    
    bool ones = false;
    bool zeroes = false;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1'){
            ones = true;
        }else{
            zeroes = true;
        }
    }
    if(ones && zeroes){
        vector<char> ans(s.length()*2);
        for(int i = 0;i<ans.size();i++){
            if(i%2==0){
                ans[i] = '0';
            }else{
                ans[i] = '1';
            }
        }    
        
        for(auto e: ans){
            cout<<e;
        }
        cout<<'\n';
    }else if(zeroes){
        vector<char> ans(s.length()*2,'0');
        for(auto e: ans){
            cout<<e;
        }
        cout<<'\n';
    }else{
        vector<char> ans(s.length()*2,'1');
        for(auto e: ans){
            cout<<e;
        }
        cout<<'\n';
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
