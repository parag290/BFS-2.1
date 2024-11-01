// Apporach 1 
// Time Complexity : O(m*n) ...... N is total number of emplpoyees
// Space Complexity : O(n) .....
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this :
//

/*
Leetcode : https://leetcode.com/problems/rotting-oranges/description/

You are given an m x n grid where each cell can have one of three values:
0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. 
If this is impossible, return -1.
*/

/**
 * Approach 1 : BFS
*/

class Solution {
    vector<vector<int>>dir{{-1,0}, {1,0}, {0, -1}, {0, 1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>>q;
        int minutes = -1;
        int fresh = 0;

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        
        if(fresh == 0) return 0;

        while(!q.empty()){
            minutes++;
            int size = q.size();

            for(int k = 0; k < size; k++){
                vector<int> temp = q.front();
                q.pop();
                int ci = temp[0];
                int cj = temp[1];

                for(auto &pair : dir){
                    int ni = ci + pair[0];
                    int nj = cj + pair[1];

                    if(ni >=0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == 1){
                        grid[ni][nj] = 2;
                        q.push({ni, nj});
                        fresh--;
                    }
                } 
            }
        }
        return fresh ? -1 : minutes;

    }
};