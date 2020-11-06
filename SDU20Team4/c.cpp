#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define watch(x) (#x)<<" : "<<(x)<<" ";
using namespace std;

int n,m;
vector<int> a[200100];
int in[200100];
int p[200100];
bool used[200100], o[200100];
vector<int> ans, arr;



void dfs(int key){
    if(used[key])
        return;

    used[key]=true;
    sort(a[key].begin(),a[key].end());
    for(int i:a[key])
        dfs(i);
    ans.push_back(key);
}

struct segtree {

    vl tree;
    int size;

    void init(int n){
        size = 1;
        while(size < n) size*=2;
        tree.assign(4*size-1,0);
    }
    void build(vi &a,int x, int lx, int rx){
        if(rx-lx == 1){
            if(lx<a.size())
                tree[x] = a[lx];
        }else{
            int m = (lx+rx)/2;
            build(a,2*x+1,lx,m);
            build(a,2*x+2,m,rx);
            tree[x] = min(tree[2*x+1],tree[2*x+2]);
        }
    }

    void build(vi &a){
        init(a.size());
        build(a,0,0,size);
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx-lx==1){
            tree[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }else{
            set(i,v,2*x+2,m,rx);
        }
        tree[x] = min(tree[2*x+1] , tree[2*x+2]);
    }

    void set(int i, int v){
        set(i,v,0,0,size);
    }

    ll sum(int l, int r, int x, int lx, int rx){
        if(l>=rx || lx>=r){
            return 999999999;
        }
        if(lx>=l && rx<=r){
            return tree[x];
        }
        int m = (rx+lx)/2;
        ll s1 = sum(l,r,2*x+1,lx,m);
        ll s2 = sum(l,r,2*x+2,m,rx);
        return min(s1,s2);
    }

    ll sum (int l,int r){
        return sum(l,r,0,0,size);
    }

};

void solve(){
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int p,q;
        cin>>p>>q;
        o[p] = o[q] = 1;
        a[q].push_back(p);
        in[p]++;
    }
    priority_queue<int> q;
    for(int i =1;i<=n;i++){
        if(in[i] == 0 && o[i]){
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur = q.top();
        q.pop();
        ans.pb(cur);
        for(auto x: a[cur]){
            in[x]--;
            if(in[x]==0){
                q.push(x);
            }
        }
    }
    reverse(all(ans));

    /*
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    */
    /*
    for(int i=1;i<=n;i++){
        if(o[i]) dfs(i);
        else{
            arr.pb(i);
        }
    }
    */

    if(m==0){
        for(int i=1;i<=n;i++){
            cout<<i<<' ';
        }
        cout<<'\n';
        return;
    }

    segtree sg;
    sg.build(ans);
    
    for(int i = 0;i<ans.size();i++){
        p[ans[i]] = i;
        //cout<<ans[i]<<' ';
    }
    //cout<<endl;
    vi tota;
    int cur = 0;
    if(sg.sum(cur,ans.size())!=1){
        for(int i =1;i<sg.sum(cur,ans.size());i++){
            tota.pb(i);
        }
    }
    while(cur<ans.size()){
        int ind = p[sg.sum(cur,ans.size())];
        for(int i=cur;i<=ind;i++){
            tota.pb(ans[i]);
        }
        if(ind+1<ans.size()){
            for(int i=ans[ind]+1;i<sg.sum(ind+1,ans.size());i++){
                if(!o[i]){
                    tota.pb(i);
                    o[i] = 1;
                }
            }
        }else{
            for(int i=ans[ind]+1;i<=n;i++){
                if(!o[i]){
                    tota.pb(i);
                    o[i] =1;
                }
            }
        }

        cur = ind+1;

    }
    for(int i=1;i<=n;i++){
        if(!o[i]){
            tota.pb(i);
            o[i] =1;
        }
    }

    for(int i=0;i<n;i++){
        cout<<tota[i]<<' ';
    }
    cout<<'\n';
    

    
        
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}