using System;

public class Solution
{
public long solution(long k, long d)
{
long Count = 0;

        for(long a = 0; a <= d; a += k)
        {
            Count += (long)(Math.Floor((Math.Sqrt(d*d - a*a))/k)) + 1;
        }
        return Count;
    }

}
