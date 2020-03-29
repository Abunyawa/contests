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
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}

void solve(){
    double h,r;
    cin>>h>>r;
    double minD = sqrt(h*h - (h/2)*(h/2));
    cout<<max(((int)r+(int)minD-1)/(int)minD - 1,0)<<endl;
}

int main(){
    abu;
    said;
    int t = 1;
    while(t--){
        solve();
    }

    return 0;
}