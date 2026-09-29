class Solution {
public:
    bool checkValidString(string str) {
        int n=str.size();
        int minOpen=0;
        int maxOpen=0;

        for(int i=0;i<n;i++){
            if(str[i]=='('){
                minOpen++;
                maxOpen++;
            }else if(str[i]==')'){
                minOpen--;
                maxOpen--;
            }else{
                minOpen--;
                maxOpen++;
            }

            if(maxOpen<0){
                return false;
            }
            minOpen=max(minOpen,0);
        }

        if(minOpen==0){
            return true;
        }
        return false;
        
    }
};
