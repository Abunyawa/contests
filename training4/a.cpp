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
    int n;
    cin>>n;
    if(n%2==0){
        if((n/2)%2==0){
            cout<<0<<endl;
        }else{
            cout<<1<<endl;
        }
    }else{
        if(((n-1)/2)%2==0){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
    }


    return 0;
}