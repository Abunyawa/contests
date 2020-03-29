#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        int n,m;
        cin>>n>>m;
        vector<pair<int,int> > a;
        int arr[n];
        for(int j = 0; j<n;j++){
            int x;
            cin>>x;
            arr[j] = x;
            a.push_back(make_pair(x,j+1));
        }
        sort(a.begin(),a.end());
        vector<pair<int,int> > ans;
        int sum = 0;
        if(n==2){
            cout<<-1<<endl;
            continue;
        }else{
            for(int j=0;j<n;j++){
                if(j!=n-1){
                    ans.push_back(make_pair(a[j].second,a[j+1].second));
                    sum+=a[j].first+a[j+1].first;
                    m--;
                }else{
                    ans.push_back(make_pair(a[j].second,a[0].second));
                    sum+=a[j].first+a[0].first;
                    m--;
                }
            }
        }

        
        
        
        
        if(m<0){
            cout<<-1<<endl;
            continue;
        }else if(m>=0){
            for(int j = 0;j<m;j++){
                pair<int,int> cur = make_pair(a[0].second,a[1].second);
                ans.push_back(cur);
                sum+=arr[cur.first-1]+arr[cur.second-1];
            }
        }
        cout<<sum<<endl;
        for(int j=0;j<ans.size();j++){
            cout<<ans[j].first<<' '<<ans[j].second<<endl;
        }

    }

    return 0;
}