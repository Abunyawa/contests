#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<char> g(26,'a');
    int n;
    cin>>n;
    int curCol = 0;
    vector<int> ans;
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        for(int j=0;j<=curCol;j++){
            if(c>=g[j]){
                ans.push_back(j+1);
                g[j] = c;
                break;
            }
        }
        if(ans.size()!=i+1){
            curCol++;
            ans.push_back(curCol+1);
            g[curCol] = c;
        }
    }

    cout<<curCol+1<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    return 0;
}