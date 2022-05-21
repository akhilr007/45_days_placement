// problem link https://leetcode.com/problems/valid-square/

/*
approach:

1. given that points can be duplicate
2. since square can have at best two different sides so calculate all the sides and put into set
3. if any points are same then it is not a square
4. if set contains only two sides then it is a square
*/

class Solution {
public:
    bool findDistance(vector<int>& a, vector<int>& b, unordered_set<int>& s){

        if(a[0] == b[0] && a[1] == b[1]) return false;

        int dx = a[0] - b[0];
        int dy = a[1] - b[1];

        int dist = dx*dx + dy*dy;

        s.insert(dist);

        return true;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {

        unordered_set<int> s;

        if(!findDistance(p1, p2, s) || !findDistance(p1, p3, s) || !findDistance(p1, p4, s) 
        !findDistance(p2, p3, s) || !findDistance(p2, p4, s) || !findDistance(p3, p4, s)){
            return false;
        }

        return s.size()==2 ? true : false;

    }
};