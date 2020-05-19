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
int used1[26];
int used2[26];


void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    string t;
    cin>>t;
    for(auto e: s){
        used1[e-'a']++;
    }
    for(auto e: t){
        used2[e-'a']++;
    }
    for(int i=0;i<26;i++){
        if(used1[i]!=used2[i]){
            cout<<-1<<'\n';
            return;
        }
    }
    vi ans1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(t[j]>t[j+1]){
                char tmp = t[j];
                t[j] = t[j+1];
                t[j+1] = tmp;
                ans1.pb(j);
            }
        }
    }
    vi ans2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(s[j]>s[j+1]){
                char tmp = s[j];
                s[j] = s[j+1];
                s[j+1] = tmp;
                ans2.pb(j);
            }
        }
    }
    cout<<ans1.size()+ans2.size()<<'\n';
    for(int i=0;i<ans2.size();i++){
        cout<<ans2[i]+1<<' ';
    }

    for(int i = ans1.size()-1;i>=0;i--){
        cout<<ans1[i]+1<<' ';
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
