#include<bits/stdc++.h>
using namespace std ;

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int n, vector<vector<int>>edges, int s) {
        // Code here
        vector<int>dis(n,1e8);
        dis[s] = 0 ;
        int i , j;
        for(i =0 ; i< n-1 ; i++)
        {
            for(j = 0 ; j< edges.size() ; j++)
            {
                int start = edges[j][0];
                int end = edges[j][1];
                int dist = edges[j][2] ;
                if(dis[start]+dist < dis[end] )
                {
                    dis[end] = dis[start]+dist ;
                }
            }
        }
        for(j = 0 ; j< edges.size() ; j++)
            {
                int start = edges[j][0];
                int end = edges[j][1];
                int dist = edges[j][2] ;
                if(dis[start]+dist < dis[end] )
                {
                    return {-1} ;
                }
            }
            
            return dis ;
        
    }
};



int main(){
    Solution s ;
    vector<int>ans ;
    ans = s.bellman_ford(3 , {{0,1,5} , {1,0,3} , {1,2,-1} , {2,0,1}} ,  2 ) ;
    for(int i = 0 ; i< ans.size() ; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0 ;
}


