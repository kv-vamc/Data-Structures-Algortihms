/*
Code Studio

You are given an expression ‘EXP’ in the form of a string where operands will be : (TRUE and FALSE) and operators will be : (AND, OR, XOR). Now you have to find the number of ways we can parenthesize the expression such that it will evaluate to TRUE.

Note :
‘T’ will represent the operand TRUE.
‘F’ will represent the operand FALSE.
‘|’ will represent the operator OR.
‘&’ will represent the operator AND.
‘^’ will represent the operator XOR.

For example :
 Input: 
 'EXP’ = T|T & F
 There are total 2  ways to parenthesize this expression:
 (i) (T | T) & (F) = F
 (ii) (T) | (T & F) = T
 Out of 2 ways, one will result in True, so we will return 1.

 Output :
 1
*/
int solve(string & exp, int i, int j, bool isTrue, vector<vector<vector<int>>>& dp)
{
    if(i > j) return false;

    if(i == j)
    {
        if(isTrue == true)
            return exp[i] == 'T';
        else
            return exp[i] == 'F';
    }

    if(dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    int res = 0;

    for(int k = i + 1; k < j; k = k + 2)
    {
        int left_true, left_false, right_true, right_false;

        left_true = solve(exp, i, k - 1, 1, dp);
        left_false =  solve(exp, i, k - 1, 0, dp);
        right_true = solve(exp, k + 1, j, 1, dp);
        right_false = solve(exp, k + 1, j, 0, dp);

        if(exp[k] == '&')
        {
            if(isTrue == 1)
                res += left_true * right_true;
            else
                res += left_true * right_false + left_false * right_true + left_false * right_false;            
        }

        if(exp[k] == '|')
        {
            if(isTrue == 1)
                res += left_true * right_false + left_false * right_true + left_true * right_true;
            else
                res += left_false * right_false;
        }
        
        if(exp[k] == '^')
        {
            if(isTrue == 1)
                res += left_true * right_false + left_false * right_true;
            else
                res += left_true * right_true + left_false * right_false;
        }
    }
    return dp[i][j][isTrue] = res;
}

int evaluateExp(string & exp)
{
    int n = exp.size();
    
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));

    return solve(exp, 0, n - 1, 1, dp);
}
