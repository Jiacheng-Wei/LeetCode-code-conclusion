//格雷码和二进制之间的转换 
/*
//        The purpose of this function is to convert an unsigned
//        binary number to reflected binary Gray code. 
//        The operator >> is shift right. The operator ^ is exclusive or.

unsigned int binaryToGray(unsigned int num)
{
        return (num >> 1) ^ num;
}
 

//        The purpose of this function is to convert a reflected binary
//      Gray code number to a binary number.

unsigned int grayToBinary(unsigned int num)
{
    unsigned int mask;
    for (mask = num >> 1; mask != 0; mask = mask >> 1)
    {
        num = num ^ mask;
    }
    return num;
}
Int    Grey Code    Binary
 　　  000        000
 　　  001        001
  　 　011        010
  　 　010        011
  　 　110        100
  　 　111        101
  　 　101        110
  　　 100        111
*/
//方法一：先生成二进制然后在转换成格雷码，然后再转换成十进制
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for (int i = 0; i < pow(2,n); ++i) {
            res.push_back((i >> 1) ^ i);
        }
        return res;
    }
}; 

