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

int main(){
    abu;
    said;
    //cin>>t;
    string s;
    cin>>s;
    int q;
    cin>>q;
    int t;
    int f;
    char c;
    vector<char> h;
    vector<char> e;
    bool pw=true;
    for(int i=0;i<q;i++){
        cin>>t;
        if(t==1){
            pw=!pw;
        }else{
            
            cin>>f>>c;
            if((f==1 && pw) || (f==2 && !pw)){
                h.pb(c);
            }else{
                e.pb(c);
            }
        }
    }
    if(pw){
        for(int i=h.size()-1;i>=0;i--){
            cout<<h[i];
        }
        cout<<s;
        for(int i=0;i<e.size();i++){
            cout<<e[i];
        }
        cout<<endl;
    }else{
        for(int i=e.size()-1;i>=0;i--){
            cout<<e[i];
        }
        for(int i=s.size()-1;i>=0;i--){
            cout<<s[i];
        }
        for(int i=0;i<h.size();i++){
            cout<<h[i];
        }
        cout<<endl;
    }
    

    return 0;
}