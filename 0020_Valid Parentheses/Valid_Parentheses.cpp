class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0 ; i < s.length() ; i++ )
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty()||(s[i]==')'&&st.top()!='(')||(s[i]=='}'&&st.top()!='{')||(s[i]==']'&&st.top()!='[')) return false;
                else st.pop();
            }
        }
        return st.empty();
    }
};

// Time  Complexity: O(n)
// Space Complexity: O(1)
// 單純利用stack去操作
// edge case有 ']' , '[' 這種情況
// 搭配stack當時empty()狀態判斷是否為正常