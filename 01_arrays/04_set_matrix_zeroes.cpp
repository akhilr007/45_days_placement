// problem link:- https://leetcode.com/problems/set-matrix-zeroes/

/*
better solution:- 
1. use two rows(m) and cols(n) space array
2. if grid[i][j] is 0 mark rows[i] and cols[j] to be 0
3. again traverse the matrix and find rows[i] = 0 or cols[j] = 0 then put grid[i][j]=0

time complexity:- O(n*m) space complexity:- O(n+m)
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        vector<int> rows(n, 1), cols(m, 1);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(grid[i][j] == 0){
                    rows[i] = 0;
                    cols[j] = 0;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(rows[i] == 0 or cols[j] == 0){
                    grid[i][j] = 0;
                }
            }
        }
        
    }
};


/*
best solution -
1. use first row and first col as dummy
2. set col0 = true so that if any element at first col is 0 then first row first col a[0][0] will be 0 
and it will mark the first row to be 0.
3. traverse backwards
*/

class Solution{
public:
    void setZeroes(vector<vector<int>>& grid){

        int n=grid.size();
        int m=grid[0].size();
        int col0 = 1;

        for(int i=0; i<n; i++){
            if(grid[i][0] == 0) col0 = 0;
            for(int j=1; j<m; j++){
                if(grid[i][j] == 0){
                    grid[i][0] = grid[0][j] = 0;
                }
            }
        }

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--)
                if(grid[i][0] == 0 or grid[0][j] == 0) grid[i][j] = 0;
            if(col0 == 0){
                grid[i][0] = 0;
            }
        }
    }
}