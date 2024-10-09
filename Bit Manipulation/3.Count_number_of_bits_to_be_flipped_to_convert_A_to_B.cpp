

// Count number of bits to be flipped to convert A to B

int minBitFlips(int start, int goal) {
        int ans = start ^ goal;
        int cnt = 0;

        for(int i=0; i<31; i++){
            if (ans & 1<<i){
                cnt++;
            } 
        }
        return cnt;
}