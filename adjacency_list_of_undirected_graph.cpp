#include<bits/stdc++.h>
using namespace std;
int main()
{
  
  int node,edge;
  cin>>node>>edge;
  
  vector<int> adj_list[node];

  while(edge--){
    int a,b;
    cin>>a>>b;

    adj_list[a].push_back(b);
    adj_list[b].push_back(a);

  }
  
  while(node--){
    cout<<node<<" ---> ";
    for(int x:adj_list[node])
        cout<<x<<" ";
    cout<<endl;    
  }
  return 0;
}