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

void solve(){
    double v1,v2;
    cin>>v1>>v2;
    double y;
    cin>>y;
    double l=0,r = 1;
    while(r-l>0.000000001){
        double m1 = l+(r-l)/3.0;
        double m2 = r-(r-l)/3.0;


        double d1 = sqrt(pow(m1,2)+pow(1-y,2));
        double d2 = sqrt(pow(1-m1,2)+pow(y,2));
        double f1 = d1/v1+d2/v2;
        d1 = sqrt(pow(m2,2)+pow(1-y,2));
        d2 = sqrt(pow(1-m2,2)+pow(y,2));
        double f2 = d1/v1+d2/v2;
        if(f1>f2){
            l = m1;
        }else{
            r = m2;
        }
    }
    printf("%0.10f\n",l);
}

int main(){
    
    freopen("forest.in","r",stdin);
    freopen("forest.out","w",stdout);
    
    abu;
    said;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
