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
/*
abcccabc
*/
void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    char cur = 'a';
    string s = "";
    for(int i=0;i<a;i++){
        if(b>0){
            s+=cur;
            cur++;
            b--;
        }else{
            s+=cur-1;
        }
    }
    int ptr = 0;
    for(int i = a;i<n;i++){
        s+=s[ptr++];
    }
    cout<<s<<'\n';
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