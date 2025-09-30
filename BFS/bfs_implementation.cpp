#include<bits/stdc++.h>
using namespace std;


void bfs(int src,vector<int> adj_list[],int node){
    bool visited[node];
    memset(visited,false,sizeof(visited));

    //queue te push
    queue<int>q;
    q.push(src);
    visited[src]=true;

    //queue theke ber kore ana

    while(!q.empty()){
        int par=q.front();
        q.pop();
        cout<<par<<" ";

       //queue niye kaj kora 
       for(int child:adj_list[par]){
         if(!visited[child]){
            q.push(child);
            visited[child]=true;
       }
    }

}


}

int main()
{
  int node,edge;
  cin>>node>>edge;
  vector<int>adj_list[node];

  while(edge--){
    int a,b;
    cin>>a>>b;
    adj_list[a].push_back(b);
    adj_list[b].push_back(a);
  }
  bfs(0,adj_list,node);
   
  return 0;
}