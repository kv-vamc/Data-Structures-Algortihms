/*Code Studio

There is a frog on the 1st step of an N stairs long staircase. The frog wants to reach the Nth stair. HEIGHT[i] is the height of the (i+1)th stair.If Frog jumps from ith to jth stair, the energy lost in the jump is given by |HEIGHT[i-1] - HEIGHT[j-1] |.In the Frog is on ith staircase, he can jump either to (i+1)th stair or to (i+2)th stair. Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.

For Example
If the given ‘HEIGHT’ array is [10,20,30,10], the answer 20 as the frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost) and then a jump from 2nd stair to last stair (|10-20| = 10 energy lost). So, the total energy lost is 20.
*/
#include <bits/stdc++.h>
int frogJump(int n, vector<int> &a)
{
    int prev1 = 0, prev2 = 0; 

    for(int i = 1; i < n; i++)
    {
        int one_step = prev1 + abs(a[i] - a[i - 1]);
        int two_step = INT_MAX;
        if(i > 1)
            two_step = prev2 + abs(a[i] - a[i - 2]);

        int cur = min(one_step, two_step);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}
