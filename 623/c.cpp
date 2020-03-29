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

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool is[2*n+1];
        for(int i=1;i<=2*n;i++){
            is[i] = false;
        }
        vector<int> b(n+1);
        vector<int> a(2*n+2);
        for(int i=1;i<=n;i++){
            cin>>b[i];
            a[2*i-1] = b[i];
            is[b[i]] = true;
        }
        bool glFlag = true;
        for(int i=2;i<=2*n;i+=2){
            bool flag = false;
            for(int j = a[i-1]+1;j<=2*n;j++){
                if(!is[j]){
                    is[j] = true;
                    a[i] = j;
                    flag = true;
                    break;
                }
            }
            if(!flag){
                glFlag = false;
                break;
            }
        }
        if(glFlag){
            for(int i=1;i<=2*n;i++){
                cout<<a[i]<<' ';
            }
            cout<<endl;
        }else{
            cout<<-1<<endl;
        }
    }

    return 0;
}