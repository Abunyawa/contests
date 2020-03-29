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
        long long a;
        long long b;
        cin>>a>>b;
        b++;
        long long c = -1;
        while(b!=0){
            b/=10;
            c++;
        }
        cout<<a*c<<endl;
    }
    return 0;
}