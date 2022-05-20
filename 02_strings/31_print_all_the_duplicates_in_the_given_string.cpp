// problem link https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/

class Solution{
public:
    void printDuplicates(stirng str){

        unordered_map<char, int> m;

        for(int i=0; i<str.length(); i++){
            m[str[i]]++;
        }

        for(auto i : m){
            if(i.second > 1){
                cout << i.first << " " <<i.second<<endl;
            }
        }
    }
}