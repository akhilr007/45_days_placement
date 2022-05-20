// problem link https://leetcode.com/problems/group-anagrams/

/*
brute : compare every string with other string and find out the anagram

optimal: use hashmap
1. take a string and copy it to temp
2. sort the given string and make it a key in hashmap
3. and push the given string

*/

class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){

        vector<vector<string>> ans;

        unordered_map<string, vector<string>> m;

        for(auto s : strs){

            string temp = s;

            sort(s.begin(), s.end());

            m[s].push_back(temp);
        }

        for(auto it : m){
            ans.push_back(it.second);
        }

        return ans;
    }
}