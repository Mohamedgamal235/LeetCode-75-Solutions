class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st ; 

        for (auto val : asteroids){
            bool explode = false ; 
            while(!st.empty() && val < 0 && st.top() >= 0 ){
                if (st.top() < abs(val) ){
                    st.pop() ;
                    continue; // if more exploded 
                }
                else if (st.top() == abs(val)){
                    st.pop() ; 
                }
                explode = true ; 
                break; 
            }
            if (explode == false)
                st.push(val) ; 
        }

        vector<int> newVec ; 
        while(!st.empty()){
            newVec.push_back(st.top());
            st.pop() ; 
        }
        reverse(newVec.begin() , newVec.end()) ; 
        return newVec ; 
    }
};