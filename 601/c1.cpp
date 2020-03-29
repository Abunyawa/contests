#include <iostream>
#include <vector>
#define maxn 100100
using namespace std;
vector <int> a[maxn];
int count[maxn],vis[maxn];
 
int main(){
	int n;
	cin >> n;
	int x,y,z;
	for (int i=1;i<=n-2;i++){
		scanf("%d%d%d",&x,&y,&z);
		a[x].push_back(y);a[x].push_back(z);
		a[y].push_back(x);a[y].push_back(z);
		a[z].push_back(x);a[z].push_back(y);
		count[x]++,count[y]++,count[z]++;
	}
	
	for (int i=1;i<=n;i++)
		if (count[i] == 1) x = i;
	if (count[a[x][0]] == 2) y=a[x][0];
	else y = a[x][1];
	vis[x] = vis[y] =1;
	printf("%d %d ",x,y);
	for (int i=1;i<=n-2;i++){
		int z ;
		for (int j=0;j<a[x].size();j++)
			if (!vis[a[x][j]]) z =a[x][j];
		vis[z] = 1;
		printf("%d ",z);
		x=y;
		y=z;
	}
 
}    