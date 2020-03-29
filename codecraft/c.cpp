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
    ll n,m,p;
    cin>>n>>m>>p;
    vl a(n+1);
    vl pa(n+1);
    pa[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pa[i] = pa[i-1]+a[i];
    }
    vl b(m+1);
    vl bp(m+1);
    bp[0] = 0;
    for(int i=1;i<=m;i++){
        cin>>b[i];
        bp[i] = bp[i-1]+b[i];
    }
    int ptr1 = 1;
    while(pa[ptr1]%p==0){
        ptr1++;

    }
    int ptr2 = 1;
    while(bp[ptr2]%p==0){
        ptr2++;
    }
    cout<<(ptr1-1)+(ptr2-1)<<endl;

}

int main(){
    abu;
    said;
    solve();
    

    return 0;
}