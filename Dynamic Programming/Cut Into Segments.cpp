/*
Code Studio

You are given an integer ‘N’ denoting the length of the rod. You need to determine the maximum number of segments you can make of this rod provided that each segment should be of the length 'X', 'Y', or 'Z'.
*/
int cutSegments(int n, int a, int b, int c)
{
	int dp[n+1];
	dp[0] = 0;
	
	for(int i = 1; i <= n; i++)
	{
		dp[i] = -1;
		
		if(i-a >= 0) dp[i] = std::max(dp[i], dp[i-a]);
		if(i-b >= 0) dp[i] = std::max(dp[i], dp[i-b]);
		if(i-c >= 0) dp[i] = std::max(dp[i], dp[i-c]);
		
		if(dp[i] != -1)
			dp[i]++;
	}
	if(dp[n] == -1)
		return 0;
	else
		return dp[n];
}
