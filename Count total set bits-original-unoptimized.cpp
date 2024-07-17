class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        int count = 0;
        for(int i=1;i<=n;i++){
            int j=0;
            while(j<31){
                int b = (i&(1<<j))>>j;
                count += b;
                j++;
            }
        }
        return count;
    }
};
