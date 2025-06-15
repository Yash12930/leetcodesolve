class Solution {
public:
    string generateTag(string caption) {
        string res = "#";
        bool firstword = true;

        for(int i=0; i<caption.length(); i++){
            if(isalpha(caption[i])){
                if(firstword){
                    res += tolower(caption[i]);
                    firstword = false;
                }else if(caption[i-1] == ' '){
                    res += toupper(caption[i]);
                }else{
                    res += tolower(caption[i]);
                }
            }else if(caption[i] == ' '){
                continue;
            }
            if(res.length() >= 100) break;
        }
        return res;
    }
};