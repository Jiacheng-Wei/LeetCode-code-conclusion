/*
�������ķ����ǣ��ҵıȽϸ��ӣ�ͨ���������������飬Ȼ���ÿһ��Ԫ��ȥѰ����������ӵ���target��ֵ��Ѱ��ֵ�ķ�����
���ö��ַ�ȥ��������������ʱ�临�Ӷ�Ӧ����O(nlogn)�� 
*/ 
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        if(numbers.empty()||numbers.size()==1) return res;
        for (int i=0;i<numbers.size();i++)
        {
            if (numbers[i]>target) break;
            else if(binarySearch(numbers,i+1,target-numbers[i])!=-1)
            {
                res.push_back(i+1);
                res.push_back(binarySearch(numbers,i+1,target-numbers[i])+1);
                break;
            }
            else continue;
        }
        return res;
    }
    int binarySearch(vector<int>& numbers, int left, int target){
        int right=numbers.size()-1;
        while (left<=right)
        {
            int mid=left+(right-left)/2;
            if(numbers[mid]==target) return mid;
            else if(numbers[mid]>target) right=mid-1;
            else left=mid+1;
        }
        return -1;
    }
};
//����һ������������СO(nlgn)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int t = target - numbers[i], left = i + 1, right = numbers.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (numbers[mid] == t) return {i + 1, mid + 1};
                else if (numbers[mid] < t) left = mid + 1;
                else right = mid;
            }
        }
        return {};
    }
};
/*
�����������ַ�������efficient��ʱ�临�Ӷ���O(nlgn)������������һ��O(n)�Ľⷨ������ֻ��Ҫ����ָ�룬һ��ָ��ͷ��
һ��ָ��ĩβ��Ȼ�����м���������ָ���������������õ���target�Ļ���ֱ�ӷ�������ָ���λ�ü��ɣ���С��target��
��ָ������һλ��������target����ָ������һλ���Դ�����ֱ������ָ������ֹͣ���μ��������£�
*/ 
// O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) return {l + 1, r + 1};
            else if (sum < target) ++l;
            else --r;
        }
        return {};
    }
};
