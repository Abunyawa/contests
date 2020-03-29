#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,l,r;
    cin>>n>>l>>r;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x>=l && x<=r){
            a.push_back(x);
        }
    }
    sort(a.begin(),a.end());
    if(a.size()>1)
        cout<<a[a.size()-1]+a[a.size()-2]<<endl;
    else
        cout<<-1<<endl;

    return 0;
}