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
#define abu ios_base::sync_with_stdio(0)
#define said cin.tie(0)
using namespace std;
ll const MOD = 998244353;



int n,m,k;


struct team{
    string name;
    int n;
    char c[26];
    int a[26];
    int t[26];
};


bool cmp(team a, team b){
    int ctr1=0;
    int ctr2=0;
    int pen1=0;
    int pen2=0;
    int last1=0;
    int last2 = 0;
    for(int i=0;i<n;i++){
        if(a.c[i]=='+'){
            ctr1++;
            pen1 += a.t[i] + (a.a[i]-1)*20;
            last1 = max(last1,a.t[i]);
        }
        if(b.c[i]=='+'){
            ctr2++;
            pen2 += b.t[i] + (b.a[i]-1)*20;
            last2 = max(last2,b.t[i]);
        }
    }
    if(ctr1!=ctr2){
        return ctr1>ctr2;
    }else{
        if(pen1!=pen2){
            return pen1<pen2;
        }else{
            if(last1!=last2){
                return last1<last2;
            }else{
                return a.name<b.name;
            }
        }
    }

}

bool check1(team a, team b){
    int ctr1=0;
    int ctr2=0;
    int pen1=0;
    int pen2=0;
    for(int i=0;i<n;i++){
        if(b.c[i]=='+'){
            ctr2++;
        }
        if(a.c[i]!='+'){
            a.c[i] = '+';
            a.a[i]++;
            a.t[i] = 240;
        }
    }
    if(ctr2<n) return true;
    return cmp(a,b);
}





void solve(){
    cin>>n>>m>>k;
    vector<team> in(m);
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        in[i].name = s;
        for(int j = 0;j<n;j++){
            char c;
            int a;
            int t;
            cin>>c>>a>>t;
            in[i].c[j] = c;
            in[i].a[j] = a;
            in[i].t[j] = t;
        }
    }
    vector<team> leaked(k);
    for(int i=0;i<k;i++){
        string s;
        cin>>s;
        leaked[i].name = s;
        for(int j = 0;j<n;j++){
            char c;
            int a;
            int t;
            cin>>c>>a>>t;
            leaked[i].c[j] = c;
            leaked[i].a[j] = a;
            leaked[i].t[j] = t;
        }
    }

    for(int i=0;i<k;i++){
        for(int j = 0;j<m;j++){
            if(in[j].name==leaked[i].name){
                in[j] = leaked[i];
            }
        }

    }
    sort(all(in),cmp);
    /*
    for(int i=0;i<m;i++){
        cout<<in[i].name<<' ';
        for(int k=0;k<n;k++){
            cout<<in[i].c[k]<<' '<<in[i].a[k]<<' '<<in[i].t[k]<<' ';
        }
        cout<<'\n';
    }
    */
    int ind =0;
    for(ind = 0;ind<m;ind++){
        if(in[ind].name==leaked[0].name){
            break;
        }
    }
    for(int i=0;i<k;i++){
        if(ind+i>=m){
            cout<<"Fake\n";
            return;
        }
        if(in[ind+i].name!=leaked[i].name){
            if(check1(in[ind+i],leaked[0])){
                ind++;
                continue;
            }else{
                cout<<"Fake\n";
                return;
            }
        }
    }
    cout<<"Leaked\n";
    return;
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
