#include<bits/stdc++.h>
using namespace std ;

class DisjointSet
{
    vector<int> rank, parent, size;


public:
    DisjointSet(int n)
    {
        rank.resize(n + 1 , 0);
        parent.resize(n + 1);
        size.resize(n + 1 ,1 );
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findpar(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findpar(parent[node]);
    }


    void unionbyrank (int u , int v)
    {
        int mpu = findpar(u);
        int mpv = findpar(v);
        if(mpu == mpv) return ;
        if(rank[mpu] < rank[mpv])
        {
            parent[mpu] = mpv ;
        }
        else if (rank[mpu] > rank[mpv])
        {
            parent[mpv] = mpu ;
        }
        else{
            parent[mpv] = mpu ;
            rank[mpv]++ ;
        }
    }


    void unionbysize(int u , int v)
    {
        int mpu = findpar(u);
        int mpv = findpar(v);
        if(mpu == mpv)return ;
        if(mpu < mpv){
            parent[mpu] = mpv ;
            size[mpv]+= size[mpu] ;
        }
        else{
            parent[mpv] = mpu ;
            size[mpu]+= size[mpv] ;
        }
    }
    /*
        DisjointSet ds1(n)  , DisjointSet ds2(n);
        ds1.unionbyrank(1,2);
        ds1.unionbyrank(1,3);
		ds1.unionbysize(1,2);
        ds1.unionbysize(1,3);  ds.findpar
    */
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>>adj)
    {
        int i,j ;
        int m = adj.size();
        vector<pair<int,pair<int,int>>>edges ;
        for(i = 0 ; i< n ; i++)
        {
               int wt = adj[i][2];
               int adjnode = adj[i][1];
               edges.push_back({wt,{i,adj[i][1]}});
        }
        sort(edges.begin(),edges.end());
        int sum = 0 ;
        DisjointSet ds(n);
        for(auto it : edges)
        {
            int node = it.second.first ;
            int adjnode = it.second.second ;
            int wt = it.first ;
            if(ds.findpar(node) != ds.findpar(adjnode))
            {
                sum+= wt ;
                ds.unionbysize(node , adjnode);
            }
        }
        
        return sum ;
    }
};

int main(){
    Solution s ;
    // cout << "hello" ;
    int ans = s.spanningTree(3 , {{0,1,5} ,{1,2,3},{0,2,1}}) ;
    cout << ans << "\n";
    return 0 ;
}