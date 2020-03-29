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
/*
13213
2112
101
11
0
*/
void solve(){
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++){
        char t;
        cin>>t;
        a[i] = (int)(t-'0');
    }
    if(n==2){
        cout<<abs(a[0]-a[1])<<endl;
        return;
    }
    int first = 0;
    for(int i=0;i<n-2;i++){
        first = abs(first-abs(a[i]-a[i+1]));
    }
    int second = 0;
    for(int i=1;i<n-1;i++){
        second = abs(second-abs(a[i]-a[i+1]));
    }
    cout<<abs(first-second)<<endl;
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
