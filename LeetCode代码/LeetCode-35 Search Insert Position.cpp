#include <stdio.h>
#include <vector>
//#include <>
using namespace std;

    int searchInsert(vector<int>& nums, int target) {
        vector<int>::iterator left;
        vector<int>::iterator right;
        vector<int>::iterator mid;
        left=nums.begin();
        right=nums.end();
        while(left<right)
        {
            mid=left+(right-left)/2;//Ϊ�˷�ֹleft+right̫�󳬽����������ַ��� 
            //if(target==*mid) return mid-nums.begin();
            else if(target>*mid)
            {
                left=mid+1;
            }
            else
            {
                right=mid;
            }
        }
        return left-nums.begin();
    }   
    //��Ҫ��ϸ�ܽ���ַ��ľ��裬��������������������������ҵ���һ�����ڵ���target��ֵ��λ�á� 
