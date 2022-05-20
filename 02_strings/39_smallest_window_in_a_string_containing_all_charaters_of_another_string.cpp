// problem link https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1#

/*
brute force: generate all substrings and compare with pattern string

optimal: use sliding window and mapping technique
*/

class Solution{
public:
    string smallestWindow(string s, string p){

        int count=0;
        int m[256] = {0};

        for(int i=0; i<p.length(); i++){
            if(m[p[i]] == 0) count++;
            m[p[i]]++;
        }

        int res = INT_MAX;
        int start=0;
        int i=0, j=0;

        while(j<s.length()){

            m[s[j]]--;

            if(m[s[j]] == 0) count--;

            if(count == 0){

                while(count == 0){

                    if(res > j-i+1){
                        res = j-i+1;
                        start = i;
                    }

                    m[s[i]]++;

                    if(m[s[i]] == 1) count++;
                    i++;
                }
            }

            j++;
        }

        if(res == INT_MAX) return "-1";

        return s.substr(start, res);
    }
}