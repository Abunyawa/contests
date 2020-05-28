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
#define abu ios_base::sync_with_stdio(0)
#define said cin.tie(0)
using namespace std;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

double dis(int n,int *t, int *v, double m, int l){
    vector<double> first;
    vector<double> second;
    double time = 0;
    for(int i = 0;i<n;i++){
        first.pb(time);
        time+=t[i];
    }
    first.pb(time);
    time = m;
    for(int i = 0;i<n;i++){
        second.pb(time);
        time+=t[i];
    }
    vector<double> allt;
    while(!first.empty() && !second.empty()){
        if(first.front()<second.front()){
            allt.pb(first.front());
            first.erase(first.begin());
        }else{
            allt.pb(second.front());
            second.erase(second.begin());
        }
    }
    while(!first.empty()){
        allt.pb(first.front());
        first.erase(first.begin());
    }
    while(!second.empty()){
        allt.pb(second.front());
        second.erase(second.begin());
    }

    vector<double> dist1;
    int cur = 0;
    double dist = 0;
    double tp = 0;
    double lt = 0;
    for(int i=0;i<allt.size();i++){
        if(allt[i]-tp<=t[cur]){
            dist += (allt[i]-lt)*v[cur];
            lt = allt[i];
            dist1.pb(dist);
        }else{
            tp+=t[cur];
            cur++;
            i--;
        }
    }

    vector<double> dist2;
    cur = 0;
    dist = 0;
    tp = 0;
    lt = 0;
    for(int i=0;i<allt.size();i++){
        if(allt[i]<m){
            dist2.pb(-9999999);
            continue;
        }
        if(allt[i]-tp-m<=t[cur]){
            dist += (allt[i]-lt-m)*v[cur];
            lt = allt[i]-m;
            dist2.pb(dist);
        }else{
            tp+=t[cur];
            cur++;
            i--;
        }
    }

    double mn = 9999999;
    for(int i=0;i<allt.size();i++){
        if(dist1[i]-dist2[i]<mn){
            mn = dist1[i]-dist2[i];
        }
    }

    return mn;
}

void solve(){
    int lim;
    cin>>lim;
    int n;
    cin>>n;
    double l = 0;
    double r = 0;
    int t[n],v[n];
    for(int i=0;i<n;i++){
        cin>>t[i]>>v[i];
        r+=t[i];;
    }
    while(r-l>0.0000000001){
        double m = (l+r)/2.0;
        double minD = dis(n,t,v,m,lim);
        if(minD>=lim){
            r = m;
        }else{
            l = m;
        }
    }

    cout<<r<<'\n';
}

int main(){
    
    freopen("trains.in","r",stdin);
    freopen("trains.out","w",stdout);
    
    abu;
    said;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
