#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pii pair<int, int>
using namespace std;

void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}

bool s[100100];
vector<int> g[100100];

bool dfs(int v){
    bool is_any = false;
    if(s[v]==0){
        is_any = true;
        return is_any;
    }else{
        for(int i = 0;i<g[v].size();i++){
            if(s[g[v][i]]==0){
                is_any = true;
            }
        }
        return is_any;
    }
}
int ot[100100];
int main(){
    int n;
    cin>>n;
    vector<int> check;
    for(int i=0;i<n;i++){
        int p,c;
        cin>>p>>c;
        if(p==-1){
            continue;
        }
        ot[i] = p-1;
        s[i] = c;
        g[p-1].pb(i);
        if(c==1){
            check.pb(i);
        }
    }
    sort(all(check));
    vector<int> ans;
    for(int i=0;i<check.size();i++){
        if(!dfs(check[i])){
            ans.pb(check[i]);
            s[check[i]] = 1;
        }
    }
    if(ans.size()!=0){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]+1<<' ';
        }
        cout<<endl;
    }else{
        cout<<-1<<endl;
    }
    

    return 0;
}