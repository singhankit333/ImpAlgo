//Given an undirected weighted graph G consisting of N vertices and M edges, and two arrays Edges[][2] and Weight[] consisting of M edges of the graph 
//and weights of each edge respectively, the task is to find the maximum product of any two vertices of the largest connected component of the graph, 
//formed by connecting all edges with the same weight.

#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int curr, vector<int> &temp) {
    if(visited[curr]) return;
    temp.push_back(curr+1);
    visited[curr] = 1;
    for(auto &neigh : adj[curr]) dfs(adj, visited, neigh, temp);
}

int solve(int n, int m, vector<int> &from, vector<int> &to, vector<int> &weight) {
    unordered_map<int, vector<pii>> myMap;
    for(int i=0; i<m; i++) {
        myMap[weight[i]].push_back({from[i]-1, to[i]-1});
    }
    int maxProd=0, maxCount=2;
    for(auto &p : myMap) {
        vector<pii> v = p.second;
        vector<vector<int>> adj(n);
        for(auto &t : v) {
            adj[t.first].push_back(t.second);
            adj[t.second].push_back(t.first);
        }
        vector<bool> visited(n, 0);
        for(int i=0; i<n; i++) {
            if(visited[i]) continue;
            vector<int> temp;
            dfs(adj, visited, i, temp);
            sort(temp.begin(), temp.end());
            if(temp.size() > maxCount) {
                maxCount = temp.size();
                maxProd = temp[maxCount-1]*temp[maxCount-2];
            }
            else if(maxCount==temp.size()) {
                maxProd = max(maxProd, temp[maxCount-1]*temp[maxCount-2]);
            }
        }
    }
    return maxProd;
}

int main() {
    int n, m;
    cin>> n >> m;
    vector<int> from(m), to(m), weight(m);
    for(int i=0; i<m; i++) cin>> from[i];
    for(int i=0; i<m; i++) cin>> to[i];
    for(int i=0; i<m; i++) cin>> weight[i];
    cout<< solve(n, m, from, to, weight) <<endl;
    return 0;
}
