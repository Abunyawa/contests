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
9 * 9 + 9 * 9 * 9
9*9*(1+81)
*/

void solve(){
    int n;
    cin>>n;
    vi a(n);
    int mxInd = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>a[mxInd]){
            mxInd = i;
        }
    }

    int ans = n;
    for(int i=1;i<=1000;i++){
        int ctr = 0;
        for(int j=0;j<a.size();j++){
            if(a[j]==i){
                ctr++;
            }else{
                if(j-ctr-1<0){
                    for(int k=j-1;k>0;k--){
                        a[k]++;
                        a.erase(a.begin()+k-1);
                        j--;
                    }
                }else{
                    if(a[j]==a[j-1]+1){
                        for(int k=j-1;k>0;k-=2){
                            a[k]++;
                            a.erase(a.begin()+k-1);
                            j--;
                        }
                    }else if(a[j-ctr-1]==a[j-1]+1){
                        for(int k=j-ctr;k<j-1;k++){
                            a[k]++;
                            a.erase(a.begin()+k+1);
                            j--;
                        }
                    }else{
                        if(a[j-ctr-1]>a[j]){
                            for(int k=j-1;k>0;k-=2){
                                a[k]++;
                                a.erase(a.begin()+k-1);
                                j--;
                            }
                        }else{
                            for(int k=j-ctr;k<j-1;k++){
                                a[k]++;
                                a.erase(a.begin()+k+1);
                                j--;
                            }
                        }
                    }
                }
                ctr=0;
            }
        }
        if(ctr!=0){
            for(int k=n-ctr;k<n;k++){
                a[k]++;
                a.erase(a.begin()+k+1);
            }
        }
    }
    for(auto e: a){
        cout<<e<<' ';
    }
    cout<<endl;
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