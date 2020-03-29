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
    set<int> nums;
    for(int i=0;i<n;i++){
        cin>>a[i];
        nums.insert(a[i]);
    }

    if(nums.size()==1){
        vi col(n,1);
        cout<<1<<endl;
        for(int i = 0;i<n;i++){
            cout<<col[i]<<' ';
        }
        cout<<endl;
    }else{
        if(n%2==0){
            cout<<2<<endl;
            for(int i=0;i<n;i++){
                if(i%2==0){
                    cout<<1<<' ';
                }else{
                    cout<<2<<' ';
                }
            }
            cout<<endl;
        }else{
            if(nums.size()==2){
                cout<<2<<endl;
                for(int i=0;i<n;i++){
                    if(a[i] == *nums.begin()){
                        cout<<1<<' ';
                    }else{
                        cout<<2<<' ';
                    }
                }
                cout<<endl;
            }else{
                vi ans(n,1);
                for(int i=0;i<n;i++){
                    
                }
            }
        }
    }
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
