#include<bits/stdc++.h>
using namespace std;

int n,m;
int grid[105][105];
bool visited[105][105];

vector<pair<int,int>>child_val={{-1,0},{1,0},{0,-1},{0,1}};

bool valid(int i,int j){
    if(i<0 ||i>=n ||j<0||j>=m)
        return false;
    return true;    
}

void dfs(int si,int sj){
    cout<<si<<" "<<sj<<endl;
    visited[si][sj]=true;

    for(int i=0;i<4;i++){
        int ci=si+child_val[i].first;
        int cj=sj+child_val[i].second;

        if(valid(ci,cj) && !visited[ci][cj])
            dfs(ci,cj);

    }
}

int main()
{
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
        cin>>grid[i][j];    
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
        cout<<grid[i][j]<<" ";
    cout<<endl;    
  }

  memset(visited,false,sizeof(visited));

  int si,sj;
  cin>>si>>sj;

  dfs(si,sj);
    
   
        

   
  return 0;
}