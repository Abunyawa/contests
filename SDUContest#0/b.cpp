#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int l, int r){
    int tmp = a[l];
    a[l] = a[r];
    a[r] = tmp;
}

int main(){
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int pos = 0;
        vector<int> ans;
        
        while(pos!= n-1){
            int minInd = pos;
            for(int i = pos;i<n;i++){
                if(a[minInd]>a[i]){
                    minInd = i;
                }
            }
            for(int i=minInd-1;i>=pos;i--){
                swap(a,i,i+1);
            }
            if(pos!=minInd){
                pos = minInd;
            }else{
                pos++;
            }

        }
        for(int i =0;i<n;i++){
            cout<<a[i]<<' ';
        }
        cout<<endl;
    }

    return 0;
}

/*

5 4 1 3 2
    m
1 5 4 3 2
   |    m
1 5 2 4 3

*/