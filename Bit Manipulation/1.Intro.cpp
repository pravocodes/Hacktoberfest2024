

//Convert Decimal to Binary
// Time complexity: log2(n)
// Space complexity: log2(n)

string decToBin(int n){
    string result = '';
    while(n != 0){
        if(n%2 == 1) result+='1';
        else result += '0';
        n = n/2;
    }
    reverse(result);
    return result;
}

//Convert Binary to Decimal
// Time complexity: O(n)
// Space complexity: O(1)

string binToDec(string s){
    int n = s.length();
    int num = 0, prod=1;
    for(int i=n-1; i>=0; i--){
        if(s[i] == '1')
            num = num + prod;
        prod = prod*2;
    }
    return num;
}