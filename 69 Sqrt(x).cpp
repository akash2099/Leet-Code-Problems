static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int mySqrt(int x) {
        // Approach 1
        // return int(sqrt(x));
        
        // Approach 2
        // long long r = x;
        // while (r*r > x)
        //     r = (r + x/r) / 2;
        // return r;
        
        // Approach 3
        // if (x == 0)
        //     return 0;
        // int left = 1, right = Integer.MAX_VALUE;
        // while (true) {
        //     int mid = left + (right - left)/2;
        //     if (mid > x/mid) {
        //         right = mid - 1;
        //     } else {
        //         if (mid + 1 > x/(mid + 1))
        //             return mid;
        //         left = mid + 1;
        //     }
        // }
        
        // Approach 4
        // https://leetcode.com/problems/sqrtx/discuss/25048/Share-my-O(log-n)-Solution-using-bit-manipulation
        // Need to understand this solution
        // if(x==0)
        //     return 0;
        // int h=0;
        // while((long)(1<<h)*(long)(1<<h)<=x) // firstly, find the most significant bit
        //     h++;
        // h--;
        // int b=h-1;
        // int res=(1<<h);
        // while(b>=0){  // find the remaining bits
        //     if((long)(res | (1<<b))*(long)(res |(1<<b))<=x)
        //         res|=(1<<b);
        //     b--;
        // }
        // return res;
        
        // Approach: Using Binary Search Time: O(logn), Space: O(1)
        // Solution: https://terriblewhiteboard.com/sqrtx-leetcode-69/
        int num=x;
        if (num < 2) { // Since, 0^0=0,1^1=1
            return num;
        }

        int left = 1;
        int right = num;

        while (left < right) {
            long long int mid = left + (right - left) / 2;

            if (mid * mid == num) {
                return mid;
            } else if (mid * mid > num) {
              right = mid; // as per video
            } else if (mid * mid < num) {
              left = mid + 1; // normal
            }
        }

      return left - 1;// since we need the floor value
}
        
};
