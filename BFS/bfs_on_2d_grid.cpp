#include<bits/stdc++.h>
using namespace std;

int r,c; 
int grid[105][105];
bool visited[105][105];
int level[105][105];
vector<pair<int,int>>child_val={{-1,0},{1,0},{0,1},{0,-1}};

bool valid(int i,int j){
    if(i<0 || i>=r ||j<0||j>=c)
        return false;
    return true;   
}

void bfs(int si,int sj){
    queue<pair<int,int>>q;
    q.push({si,sj});
    visited[si][sj]=true;
    level[si][sj]=0;

    while(!q.empty()){
        pair<int,int> par=q.front();
        q.pop();

        int par_i=par.first;
        int par_j=par.second;

        cout<<par_i<<" "<<par_j<<endl;

        for(int i=0;i<4;i++){
            int ci=par_i+child_val[i].first;
            int cj=par_j+child_val[i].second;

            if(valid(ci,cj) &&!visited[ci][cj]){
                q.push({ci,cj});
                visited[ci][cj]=true;
                level[ci][cj]=level[par_i][par_j]+1;
            }

        }
    }

}
int main()
{
  
  cin>>r>>c;

  for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
        cin>>grid[i][j];

   int si,sj,di,dj;
   cin>>si>>sj>>di>>dj;     
  
  memset(visited,false,sizeof(visited));
  memset(level,-1,sizeof(level));
  bfs(si,sj);
  cout<<level[di][dj];
  return 0;
}