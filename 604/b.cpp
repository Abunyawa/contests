#include<bits/stdc++.h>
using namespace std;

bool check(int m, int *nums){
    int dist = m-1;
    int l=999999999;
    int r = 0;
    for(int i=1;i<=m;i++){
        if(nums[i]>r){
            r = nums[i];
        }
        if(nums[i]<l){
            l = nums[i];
        }
    }
    
    return (abs(l-r)==m-1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int nums[n+10];
        int arr[n];
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            arr[i] = x;
            nums[x] = i;
        }
        vector<int> ans;
        int l = nums[1];
        int r = nums[1];
        ans.push_back(1);
        
        
        for(int i=1;i<=n;i++){
            bool flag = true;
            for(int j = 0;j<i;j++){
                if(arr[l-j]>i || arr[r+j]>i){
                    flag = false;
                }
            }
            if(flag){
                ans.push_back(1);
            }else{
                ans.push_back(0);
            }
            

        }
       
            
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}