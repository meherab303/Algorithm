#include<bits/stdc++.h>
using namespace std;

vector<int>adj_list[1005];
bool visited[1005];

void dfs(int src){
    
    cout<<src<<" ";
    visited[src]=true;

    for(int child:adj_list[src]){
        if(!visited[child])
            dfs(child);
    }
        
}
int main()
{
  int vertex,edge;
  cin>>vertex>>edge;

  while (edge--)
  {
    int a,b;
    cin>>a>>b;

    adj_list[a].push_back(b);
    adj_list[b].push_back(a);

  }
  memset(visited,false,sizeof(visited));

  dfs(0);
  
   
  return 0;
}