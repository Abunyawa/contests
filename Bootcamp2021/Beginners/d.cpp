    #include<bits/stdc++.h>
    using namespace std;


    void solve(){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==j && i==0){
                    cout<<"W";
                }else{
                    cout<<"B";
                }
            }
            cout<<'\n';
        }
    }


    int main(){
        int t;
        cin>>t;
        while(t--){
            solve();
        }
        return 0;
    }