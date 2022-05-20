// problem link https://leetcode.com/problems/rotate-image/

/*
approach:
1. swap and then rotate
*/

class Solution{
public:
    void rotate(vector<vector<int>>& matrix){

        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0; i<n; i++){
            for(int j=i+1; j<m; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // rotate;
        for(int i=0; i<n; i++){
            int left = 0, right = m-1;

            while(left <= right){
                swap(matrix[i][left], matrix[i][right]);
                left++;
                right--;
            }
        }

    }
};