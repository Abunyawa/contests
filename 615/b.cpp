#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int> > it;
        string ans="";
        for(int i =0 ;i<n;i++){
            int x,y;
            cin>>x>>y;
            it.push_back(make_pair(x,y));

        }
        sort(it.begin(),it.end());
        int curY=0;
        bool flag = true;
        int curX = 0;
        for(auto e: it){
            if(e.first<curX || e.second < curY){
                flag = false;
                break;
            }else{
                for(int j=0;j<(e.first-curX);j++){
                    ans+="R";
                }
                for(int j=0;j<(e.second-curY);j++){
                    ans+="U";
                }
                curX = e.first;
                curY = e.second;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
            cout<<ans<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}