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
        int a,b,c;
        cin>>a>>b>>c;
        int ans = 0;
        if(a>0){
            ans++;
            a--;
        }
        if(b>0){
            ans++;
            b--;
        }
        if(c>0){
            ans++;
            c--;
        }
        if(max(a,max(b,c))>1 && min(a,min(b,c))>0){
            if(a>1 && b>1 && c>1){
                ans+=3;
                a-=2;
                b-=2;
                c-=2;
            }else{
                if(a>1){
                    ans+=2;
                    a-=2;
                    b--;
                    c--;
                }else if(b>1){
                    ans+=2;
                    a-=2;
                    b--;
                    c--;
                }else if(c>1){
                    ans+=2;
                    a-=2;
                    b--;
                    c--;
                }
            }
        }else{
            if(a>0 && b>0){
                ans++;
                a--;
                b--;
            }
            if(c>0 && b>0){
                ans++;
                c--;
                b--;
            }
            if(a>0 && c>0){
                ans++;
                a--;
                c--;
            }
        }

        if(a>0 && b>0 && c>0){
            ans++;
            a--;
            b--;
            c--;
        }
        cout<<ans<<endl;
    }


    return 0;
}