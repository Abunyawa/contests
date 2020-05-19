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

vector<pair<int,char>> simulate(vl &a,int l, int r){
    ll mx = 0;
    for(int i=l;i<=r;i++){
        if(a[i] > mx){
            mx = a[i];
        }
    }
    vector<pair<int,char>> ans;
    for(int i =l;i<=r;i++){
        if(a[i]==mx){
            if(a[i]>a[max(i-1,l)]){
                int sh=0;
                while(i-sh>l){
                    ans.pb({i-sh,'L'});
                    sh++;
                }
                for(int j=0;j<r-i;j++){
                    ans.pb({l,'R'});
                }
                break;
            }else if(a[i]>a[min(r,i+1)]){
                int sh = 0;
                for(int j=0;j<r-i;j++){
                    ans.pb({i,'R'});
                }
                while(i-sh>l){
                    ans.pb({i-sh,'L'});
                    sh++;
                }
                break;
            }
        }
    }
    if(ans.size()!=r-l){
        vector<pair<int,char>> badAns;
        badAns.pb({-1,'B'});
        return badAns;
    }else{
        return ans;
    }
}


void solve(){
    int n;
    cin>>n;
    vl a(n+1);
    vl pre(n+1);
    pre[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i] = pre[i-1] + a[i];
    }
    int m;
    cin>>m;
    vl b(m+1);
    int sum = 0;

    for(int i=1;i<=m;i++){
        cin>>b[i];
        sum+=b[i];
    }
    if(sum!=pre[n]){
        no();
        return;
    }
    vector<pair<int,char>> Tans;

    int prev = 0;
    for(int i=1;i<=m;i++){
        int ptr = prev+1;
        while(ptr<=n && pre[ptr] - pre[prev]!=b[i] ){
            ptr++;
        }

        if(ptr>n){
            no();
            return;
        }  
        vector<pair<int,char>> ans = simulate(a,prev+1,ptr);
        if(ans.size()>0 && ans[0].F == -1){
            no();
            return;
        }
        for(auto e: ans){
            Tans.pb({e.F-prev+i-1,e.S});
        }
        prev = ptr;
    }

    yes();
    for(auto e: Tans){
        cout<<e.F<<' '<<e.S<<'\n';
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
