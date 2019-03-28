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
//��Ҫ��ת������������һλλ��ȡ���������ȡ��������1�����ǽ����res����һλ���Ҽ���1�����ȡ��������0�����ǽ����res����һλ��Ȼ��n����һλ����
//�������˹̹����ѧ������һ���������������������ɣ��ŷ������ڵݹ飬һ��һ��ķ�ת��
//˹̹����ѧ����λ���������ӣ�http://graphics.stanford.edu/~seander/bithacks.html
/*��Щ������ȷ���˳��ޣ����ж���λ��ת��������һ�ַ����������ֵ�λ������������ķ�ת������32λ�ֳ�����16λ�����֣�16λ�ֳ�
����8λ���з�ת�������Դ�����֪��ֻ��һλ������һ��8λ����abcdefgh����������Ĺ�������
abcdefgh -> efghabcd -> ghefcdab -> hgfedcba*/ 
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);//��Щʮ�����ƶ���ת���ɶ����ƶ��Ƕ�Ӧ�ƶ�λ����1��0�������С� 
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};
//����ķ����е��£���֪��զ�����ģ������Ҿ��ĺ͵�һ������������Ϊmask&nҲ��һλһλ�����жϰ���
//����������¾��������˼����n&mask��>>i���Ǵ�������һλһλ�ڱȽ��жϣ�ֻ�ǽ���һ�������������ж��ں���һ���ˡ� 
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
 
