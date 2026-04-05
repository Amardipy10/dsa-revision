class Solution {
public:
    bool judgeCircle(string moves) {
        int ver=0;
        int hor=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='R'){
                hor++;
            }
            else if(moves[i]=='L'){
                hor--;
            }
            else if(moves[i]=='U'){
                ver++;
            }
            else{
                ver--;
            }
        }
        if(ver==0 && hor==0){
            return true;
        }
        return false;
    }
};