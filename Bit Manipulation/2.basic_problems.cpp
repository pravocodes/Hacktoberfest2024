

//Swap 2 numbers without using 3rd variable

void swap(int *a, int *b){
    a = a^b;
    b = a^b;
    a = a^b;
}


//Check if 1st bit is set or not

if((n>>1) & 1 == 0){
    return true;
}else{
    return false;
}

//set i'th bit

return (n | (1 << i))