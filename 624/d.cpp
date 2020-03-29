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
        ll a,b,c;
        cin>>a>>b>>c;
        ll ta=a,tb=b,tc=c;
        ll aa=a,ab=b,ac=c;
        ll glAns = 999999999999;
        for(int i=1;i<=10000;i++){
            for(int j=1;i*j<=10000;j++){
                ll ans = abs(i-ta);
                ans+=abs(tb-i*j);
                a=i;b=tb;c=tc;
                b=i*j;
                if(c%b<b-c%b){
                    ans+=c%b;
                    c=c/b*b;
                }else{
                    ans+=b-c%b;
                    c=(c/b+1)*b;
                }
                if(ans<glAns){
                    glAns = ans;
                    aa=a;
                    ab=b;
                    ac=c;
                
                }

            }
            
        }
        cout<<glAns<<endl;
        cout<<aa<<' '<<ab<<' '<<ac<<endl;
    }


    return 0;
}