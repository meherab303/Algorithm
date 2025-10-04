#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<int>adj_list[N];
bool visited[N];
int level[N];
int parent[N];

void bfs(int src){
    
    queue<int>q;
    q.push(src);
    visited[src]=true;
    level[src]=0;
    cout<<"bfs travers --> ";
    while(!q.empty()){
        int par=q.front();
        q.pop();
        
       
        cout<<par<<" ";

        for(int child:adj_list[par]){
            if(!visited[child]){
                q.push(child);
                visited[child]=true;
                level[child]=level[par]+1;
                parent[child]=par;  //tracking every childs parent;
            }
        }
    }
    
}

int main()
{
  
  int vertex,edge;
  cin>>vertex>>edge;
  
  while(edge--){
    int a,b;
    cin>>a>>b;
    adj_list[a].push_back(b);
    adj_list[b].push_back(a);

  }

  memset(visited,false,sizeof(visited));
  memset(level,-1,sizeof(level));
  memset(parent,-1,sizeof(parent)); // intially making all vertexs parent -1;

  int src,desti;
  cin>>src>>desti;

  bfs(src);
  cout<<endl;

  for(int i=0;i<vertex;i++){
    cout<<i<<" parent-->"<<parent[i]<<endl;
  }

  vector<int>path;  //taking vector for reverse the path as we start from the destination here
  int desti_vertex=desti;

  while(desti_vertex!=-1){
    path.push_back(desti_vertex);
    desti_vertex=parent[desti_vertex];
  }
  
  reverse(path.begin(),path.end()); //reverse the path

  cout<<"shortest route from source "<<src<<" to destination "<<desti<<" is ";
  


  if(level[desti]==-1){
        cout<<"IMPOSSIBLE";
        
    }else{
        cout<<path.size()<<endl;
        for(int x:path){
            cout<<x<<" ";
  }
    }
  return 0;
}