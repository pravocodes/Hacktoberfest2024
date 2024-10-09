

// GFG - Find XOR of numbers from L to R
// Time complexity - O(1)
// Space complexity - O(1)
int func(int n)
{
    if (n % 4 == 0)
        return n;
    else if (n % 4 == 1)
        return 1;
    else if (n % 4 == 2)
        return n + 1;
    return 0;
}

int findXOR(int l, int r)
{
    return func(l - 1) ^ func(r);
}