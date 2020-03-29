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
    vector<ll> a(n);
    ll max = -10000000;
    int ind =-1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>=0 && a[i]>max){
            max = a[i];
            ind = i;
        }
        if(a[i]<0 && -a[i]-1>max){
            max = -a[i]-1;
            ind = i;
        }
    }
    if(n%2==0){
        for(int i=0;i<n;i++){
            if(a[i]<0){
                cout<<a[i]<<' ';
            }else{
                cout<<-a[i]-1<<' ';
            }
        }
        cout<<endl;
    }else{
        for(int i =0;i<n;i++){
            if(i == ind){
                if(a[i]>=0){
                    cout<<a[i]<<' ';
                }else{
                    cout<<-a[i]-1<<' ';
                }
            }else{
               if(a[i]<0){
                    cout<<a[i]<<' ';
                }else{
                    cout<<-a[i]-1<<' ';
                } 
            }
        }
        cout<<endl;
    }

    

    return 0;
}