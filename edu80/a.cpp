#include<iostream>
using namespace std;
#define line1 ios_base::sync_with_stdio(0)
#define line2 cin.tie(0);

int main(){
    line1;
    line2;
    int t;
    cin>>t;

    while(t--){
        int n,d;
        cin>>n>>d;
        if(d<n){
            cout<<"YES"<<endl;
            continue;
        }else{
            int x = n/2;
            int a = x + (d+x)/(x+1);
            if(a<=n){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }


    }

    return 0;
}