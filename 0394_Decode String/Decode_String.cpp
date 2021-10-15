class Solution {
public:
    string decodeString(string s) {
        string res;
        stack<int> num;
        stack<string> dict;
        int count = 0;

        for(int i = 0;i<s.length();i++)
        {
            if((s[i]>='a' && s[i] <= 'z') || (s[i]>='A' && s[i] <= 'Z'))
            {
                if(num.empty()) res+= s[i];
                else dict.top()+= s[i];
                // if stack is empty, we add char to result;
                // else we add char to top of stack
            }
            else
            {
                if(s[i]>='0' && s[i] <= '9') 
                {
                    count*=10;
                    count+=s[i]-'0';
                    // count the number
                }
                else if(s[i]=='[')
                {
                    num.push(count);
                    count = 0;
                    dict.push("");
                    // if char == '[' => we need a new stack
                }
                else if(s[i]==']')
                {
                    string x;
                    for(int i = 0;i<num.top();i++) x+= dict.top();
                    //just add words to string
                    dict.pop();num.pop();
                    // pop it because we already added it.
                    if(!dict.empty())dict.top()+=x;
                    // if stack is not empty. This means we can't add the string to the result.
                    // so we add the string to next stack.(now that stack is on the top because we popped it.)
                    else res+=x;
                    // when stack is empty. finally we can add the string to the result.
                }
            }
        }
        return res;
    }
};

// Time  Complexity: O(n)
// Space Complexity: O(n)

// 利用Stack去實作
// 規則如下：
// 1. 如果遇到字母
//      a. 紀錄數字的stack為空 => 代表單純遇到字母，直接將字母加到result中
//      b. 反之，先加到紀錄數字的stack之中，晚點要依照數字去相加
// 2. 其他狀況，數字、"["、"]"
//      a. 數字 => 去紀錄幾次，遇到"["自然結算次數
//      b. "["  => 結算數字之外，還要push一個empty string => 因為代表會遇到新的字母或數字，要用新的位置幫忙紀錄
//      c. "]"  => 代表要結算次數了，用一個temp string紀錄，紀錄了(num的top的次數*dict的top字串) 
//              => 數字及字串完成後自然都pop掉，然後把現在的結果都加到原本下一層的dict之中，直到stack乾淨後才加到result之中
// 有只用一個stack的做法