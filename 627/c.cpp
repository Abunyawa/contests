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
using namespace std;

void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}


void solve(){
    string s;
    cin>>s;
    s='R'+s+'R';
    int n = s.length();
    int prevR = 0;
    int mxD = 0;
    for(int i=1;i<n;i++){
        if(s[i]=='R'){
            if(i-prevR>mxD){
                mxD = i-prevR;
            }
            prevR = i;
        }
    }    
    cout<<mxD<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}