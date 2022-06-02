// leetcode#44
class Solution {
public:
    bool isMatch(string s, string p)
    {
        int n = p.size(), m = s.size();
        vector<bool> prev(m + 1);
        prev[0] = true;

        for(int k = 1; k <= m; k++)
            prev[k] = false;

        for(int i = 1; i <= n; i++)
        {
            vector<bool> cur(m + 1);
            bool flag = true;

            for(int kk = 1; kk <= i; kk++)
            {
                if(p[kk - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            cur[0] = flag;

            for(int j = 1; j <= m; j++)
            {
                if(p[i-1] == s[j-1] || p[i-1] == '?')
                    cur[j] = prev[j - 1];
                else if(p[i-1] == '*')
                    cur[j] = prev[j] || cur[j - 1];
                else
                    cur[j] = false;
            }
            prev = cur;
        }
        return prev[m];
    }
};
