// problem link https://leetcode.com/problems/word-search/

class Solution{
public:
    bool search(vector<vector<char>>& board, int i, int j, int ind, string& word){

        if(ind == word.size()) return true;

        if(i<0 || j<0 || i>-=board.size() || j>=board[0].size() || board[i][j] == '*'){
            return false;
        }

        if(board[i][j] != word[ind]){
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '*'; // to avoid duplicate search

        bool res = search(board, i-1, j, ind+1, word) ||
                   search(board, i, j-1, ind+1, word) ||
                   search(board, i+1, j, ind+1, word) ||
                   search(board, i, j+1, ind+1, word);

        board[i][j] = temp;
        return res;
    }

    bool exist(vector<vector<char>>& board, string word){

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){

                if(board[i][j] == word[0]){
                    if(search(board, i, j, 0, word)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};