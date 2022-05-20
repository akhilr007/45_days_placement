// problem link https://leetcode.com/problems/simplify-path/

/*
approach:

1. 
*/

class Solution{
public:
    string simplifyPath(stirng path){

        stringstream ss(path);
        string temp;
        vector<string> word;

        while(getline(ss, temp, '/')){
            
            if(temp == "" or temp == "."){
                continue;
            }
            else if(temp == ".."){
                if(word.size()>0){
                    word.pop_back();
                }
            }
            else{
                word.push_back(temp);
            }
        }

        if(word.size()==0) return "/";
        string res="";
        for(auto s : word){
            res += "/" + s;
        }

        return res;
    }
}