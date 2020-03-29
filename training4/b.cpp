#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pii pair<int, int>
using namespace std;

void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}
int ctr[5001];

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    bool flag = true;
    for(int i=0;i<n;i++){
        cin>>a[i];
        ctr[a[i]]++;
        if(ctr[a[i]]>k){
            flag = false;
        }
    }
    if(flag){
        int col = 0;
        vector<int> ans(n);
        for(int i=1;i<=5000;i++){
            for(int j=0;j<n;j++){
                if(a[j]==i){
                    ans[j] = (col++%k);
                }
            }
        }
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            cout<<ans[i]+1<<' ';
        }
        cout<<endl;
    }else{
        cout<<"NO"<<endl;
    }


    return 0;
}