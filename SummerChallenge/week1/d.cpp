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
    double a,b,c,d;
    double y;
    cin>>a>>b>>c>>d;
    double l=-10000,r = 10000;
    if(a>0){
        while(r-l>0.00000000000001){
            double mid = (l+r)/2.0;
            double f1 = a*pow(mid,3)+b*pow(mid,2)+c*mid+d;
            if(f1>0){
                r = mid;
            }else{
                l = mid;
            }
        }
        printf("%0.10f\n",l);
    }else{
         while(r-l>0.0000000000001){
            double mid = (l+r)/2.0;
            double f1 = a*pow(mid,3)+b*mid*mid+c*mid+d;
            if(f1>=0){
                l = mid;
            }else{
                r = mid;
            }
        }
        printf("%0.10f\n",l);
    }
}

int main(){
    
    freopen("cubroot.in","r",stdin);
    freopen("cubroot.out","w",stdout);
    
    abu;
    said;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
