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
    int n;
    cin>>n;
    vi a(n);
    vi ansa(n);
    vi ansb(n);
    for(int i=0;i<n;i++){
        char x;
        cin>>x;
        a[i] = (x-'0');
    }
    int b =0;
    for(int i=0;i<n;i++){
        if(b==0){
            if(a[i]==0){
                ansa[i] = 0;
                ansb[i] = 0;
            }else if(a[i]==1){
                ansa[i] = 1;
                ansb[i] = 0;
                b = 1;
            }else if(a[i]==2){
                ansa[i] = 1;
                ansb[i] = 1;
            }
        }else{
            if(a[i]==0){
                ansa[i] = 0;
                ansb[i] = 0;
            }else if(a[i]==1){
                ansa[i] = 0;
                ansb[i] = 1;
                b = 1;
            }else if(a[i]==2){
                ansa[i] = 0;
                ansb[i] = 2;
            }
        }
        
    }
    for(int i=0;i<n;i++){
        cout<<ansa[i];
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<ansb[i];
    }
    cout<<endl;
}

int main(){
    abu;
    said;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
