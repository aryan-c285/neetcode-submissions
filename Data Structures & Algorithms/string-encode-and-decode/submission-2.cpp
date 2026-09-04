class Solution {
public:
    string encode(vector<string>& strs) {
        string enc = "";
        for (auto it : strs){
            enc+=to_string(it.size())+"#"+it;
        }
        return enc;
    }
    vector<string> decode(string s) {
        vector <string> dec;
        int i = 0;
        while(i<s.size()){
            int j=i;
            while(s[j] != '#'){
                j++;
            }
            int len = stoi(s.substr(i, j-i));
            dec.push_back(s.substr(j+1, len));
            i = j +1+len;   
        }
        return dec;
    }
};