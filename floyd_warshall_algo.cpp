#include<bits/stdc++.h>
using namespace std ;


class Solution {
  public:
	void shortest_distance(vector<vector<int>>matrix){
        int i , j , mid ;
        int n = matrix.size() ;
        for(i = 0 ; i< n ; i++)
        {
            for(j = 0 ; j< n ; j++)
            if(matrix[i][j] == -1)matrix[i][j] = 1e8 ;
        }
        for(mid = 0 ; mid < n ; mid++)
        {
            for(i = 0 ; i< n ; i++)
            {
                for(j = 0 ; j< n ; j++)
                {
                    if(matrix[i][mid]+ matrix[mid][j] < matrix[i][j])
                    {
                        matrix[i][j] = matrix[i][mid]+ matrix[mid][j] ;
                    }
                    // if(matrix[i][i] < 0 ) return -1 ;
                }
            }
        }
        for(i = 0; i< n ; i++)
        {
            for(j = 0 ; j< n ; j++)
            {
                if(matrix[i][j] == 1e8)matrix[i][j] = -1 ;
            }
        }
        for(i = 0 ; i< n ; i++)
        {
            for(j = 0 ; j < n ; j++)
            {
                cout << matrix[i][j] << " " ;
            }
            cout << "\n";
        }
	}
};

int main(){
    Solution s ;
    vector<int>ans ;
    
    s.shortest_distance({{0,1,43} , {1,0,6} , {-1,-1,6} } ) ;
    return 0 ;
}
