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
        ll a,b;
        cin>>a>>b;
        if(a==b){
            cout<<0<<endl;
        }else if(a>b){
            if((a-b)%2==0){
                cout<<1<<endl;
            }else{
                cout<<2<<endl;
            }
        }else if(a<b){
            if((b-a)%2==1){
                cout<<1<<endl;
            }else{
                cout<<2<<endl;
            }
        }
    }


    return 0;
}