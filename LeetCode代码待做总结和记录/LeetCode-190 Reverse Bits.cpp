class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        for (int i=0;i<32;i++)
        {
            if (n&1) 
            {
                ans=(ans<<1)|1;
            }
            else ans<<=1;
            n>>=1;
        }
        return ans;
    }
};
//把要翻转的数从右向左一位位的取出来，如果取出来的是1，我们将结果res左移一位并且加上1；如果取出来的是0，我们将结果res左移一位，然后将n右移一位即可
//下面给出斯坦福大学给出的一个解决方案，这个方案很巧，放发类似于递归，一半一半的翻转。
//斯坦福大学关于位操作的链接：http://graphics.stanford.edu/~seander/bithacks.html
/*有些方法的确让人称赞，其中对于位翻转有这样的一种方法，将数字的位按照整块整块的翻转，例如32位分成两块16位的数字，16位分成
两个8位进行翻转，这样以此类推知道只有一位。对于一个8位数字abcdefgh来讲，处理的过程如下
abcdefgh -> efghabcd -> ghefcdab -> hgfedcba*/ 
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);//这些十六进制都是转化成二进制都是对应移动位数的1和0交错排列。 
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};
//下面的方法有点懵，不知道咋个来的，不过我觉的和第一个方法很像，因为mask&n也是一位一位的在判断啊。
//重新理解了下就是这个意思，（n&mask）>>i就是从右向左一位一位在比较判断，只是将第一个方法的两个判断融合在一起了。 
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t value = 0;
        uint32_t mask = 1;
        for (uint32_t i = 0; i < 32; ++i) {
            value = (value << 1 ) | ((n & mask) >> i);
            mask <<=1;
        }
        return value;
    }
};
 
