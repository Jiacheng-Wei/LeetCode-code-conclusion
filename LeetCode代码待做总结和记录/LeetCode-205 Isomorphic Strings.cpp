class Solution {
public:
    bool _isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        int length1=s.length();
        int length2=t.length();
        if (length1!=length2) return false;
        if (length1==0&&length2==0) return true;
        else if (length1==0||length2==0) return false;
        for (int i=0;i<length1;i++)
        {
            if (mp.find(s[i])!=mp.end()&&mp.find(s[i])->second!=t[i]) return false;
            else 
            {
                mp[s[i]]=t[i];
            }
        }
        return true;
    }
    bool isIsomorphic(string s, string t){
        return _isIsomorphic(s, t)&&_isIsomorphic(t, s);
    }
};
/*给定两个字符串s和t，判断它们是否是同构的。如果字符串s可以通过字符替换的方式得到字符
串t，则称s和t是同构的。字符的每一次出现都必须被其对应字符所替换，同时还需要保证原始顺
序不发生改变。两个字符不能映射到同一个字符，但是字符可以映射到其本身。*/
/*上面的方法是直接用的map方法，判断对应的映射，但是在输入为("ab","aa")时本应该是错误的，但是入过只通过映射判断的话就是正确的;
但是输入交换一下，输入为("aa","ab")，这样的输出就是错误的了，所以在判断时要交换输入顺序判断，并去并的结果*/
//下面给出另一个思路，用一个set集判断出t中的值是否反复出现。 
/*使用一个哈希表map维护两个字符串中字符的映射关系，同时用一个set保存映射的值。(s[i], t[i])，如是s[i]键没有在map中出现过并
且t[i]没有在set中出现过，就加入到映射关系中，t[i]值已经出现过，说明是多对一映射，不符合返回false。s[i]键如果已经出现过，
设为s[k]，对应的映射值为t[k]),即s[i]==s[k],则找出s[k]的对对应值t[k]，如果t[i]!=t[k],说明一个同一个字符存在两个不同的映射，
两个字符串不是同构的，返回false，继续处理下一个字符，直到结束。*/


