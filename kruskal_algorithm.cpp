/*
In the Kruskal Algorithm, we are given a spanning tree and we are supposed to find the minimum cost to traverse through all nodes in the tree.

We start by noting down only the nodes and then sequentially start making the connections between those vertices starting from the least.

If we encounter a cycle, we neglect that loop and move to the next one


BEST CASE: N-1 edges
WORSE CASE: e edges E*LOG(E)
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+6;

vector<int> parent(N);
vector<int> sz(N);

void make_set(int v){
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v){
    if(v==parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a,int b){
    a = find_set(a);
    b = find_set(b);

    if(a!=b){
        if(sz[a]<sz[b])
            swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main(){
    for (int i = 0; i < N; i++) make_set(i);
    int vertices, edges;
    cin>>vertices>>edges;
    vector<vector<int>> edges_vector;
    for (int i = 0; i < edges; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges_vector.push_back({w,u,v});
    }
    sort(edges_vector.begin(),edges_vector.end());
    int cost = 0;
    for (auto i : edges_vector){
        int w = i[0];
        int u = i[1];
        int v = i[2];

        int x = find_set(u);
        int y = find_set(v);

        if(x==y) continue;

        else {
            cout<<u<<" "<<v<<"\n";
            cost += w;
            union_sets(u,v);
            
        }
    }

    cout<<"The min cost is "<<cost<<endl;
}







    




