#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<long long, long long>
using namespace std;


void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> a(n+1);
        vector<bool> c(n+1,false);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        vector<int> p(m+1);
        for(int i=1;i<=m;i++){
            cin>>p[i];
            c[p[i]] = true;
        }
        bool flag = true;
        for(int i =1;i<=n;i++){
            for(int j=1;j<n;j++){
                if(a[j]>a[j+1]){
                    if(c[j]){
                        int tmp = a[j];
                        a[j] = a[j+1];
                        a[j+1] = tmp;
                    }else{
                        flag = false;
                        break;
                    }
                }
            }
            if(!flag){
                break;
            }
        }
        if(flag){
            yes();
        }else{
            no();
        }
    }


    return 0;
}