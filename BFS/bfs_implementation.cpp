#include<bits/stdc++.h>
using namespace std;


void bfs(int src,vector<int> adj_list[],int vertex){
    bool visited[vertex];
    memset(visited,false,sizeof(visited));

    //queue te push
    queue<int>q;   //space complexity=O(V)
    q.push(src);
    visited[src]=true;

    

    while(!q.empty()){ // time complexity=O(v).vertex jotota q te totota push hbe .
       //queue theke ber kore ana
        int par=q.front();
        q.pop();

        //oi vertex niye kaj
        cout<<par<<" ";

       //children push
       for(int child:adj_list[par]){  // time complexity=O(E).Edge jotota ototai operation hoi worst case e .karon protita edge ekbar e travers hbe.
         if(!visited[child]){   // ei condition er upor operation depend kortese
            q.push(child);
            visited[child]=true;
       }
    }

}

// overall bfs er time compleixty=O(V+E) .O(V) ar O(E) er modde nested relation na karon node jototai thakuk adjacency)list e  edge jotota totai operaton hbe.
// bfs er time complexity =O(V)

}

int main()
{
  int vertex,edge;
  cin>>vertex>>edge;
  vector<int>adj_list[vertex];

  while(edge--){
    int a,b;
    cin>>a>>b;
    adj_list[a].push_back(b);
    adj_list[b].push_back(a);
  }
  bfs(0,adj_list,vertex);
   
  return 0;
}