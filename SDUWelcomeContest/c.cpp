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
int state[200100];
vector<int> g[200100];


bool used[10];

void solve(){
    for(int i=0;i<5;i++){
        string s;
        cin>>s;
        if(s[1] == '>'){
            g[s[0]-'A'].pb(s[2]-'A');
        }else{
            g[s[2]-'A'].pb(s[0]-'A');
        }
    }
    string s = "";
    for(int __ = 0;__<5;__++){
        for(int i=0;i<5;i++){
            if(g[i].size()==0 && !used[i]){
                s+='A'+i;
                for(int j=0;j<5;j++){
                    for(int k = 0;k<g[j].size();k++){
                        if(g[j][k]==i){
                            g[j].erase(g[j].begin()+k);
                        }
                    }
                }
                used[i]=true;
                break;
            }
        }
    }
    if(s.length()==5){
        cout<<s<<'\n';
    }else{
        cout<<"impossible\n";
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
