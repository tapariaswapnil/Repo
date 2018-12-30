    #include <cmath>
    #include <cstdio>
    #include <vector>
    #include <iostream>
    #include <algorithm>
    #include <stack>
    #include <utility>
    using namespace std;


    int main() {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        string str;
        cin>>str;
        stack<pair<char,int>> st;
        for(char ch:str)
        {
            if(st.empty() || st.top().first!=ch)
                st.push({ch,1});
            else
                st.top().second++;
            if(!st.empty() && st.top().second == 3)
                st.pop();
        }
        string ans = "";
        while(!st.empty())
        {
            for(int i=0;i<st.top().second;i++)
                ans.push_back(st.top().first);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        cout<<ans<<endl;
        return 0;
    }
