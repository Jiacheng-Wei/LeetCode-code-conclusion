class Solution {
public:
	const static string THOUS[];
	const static string HUNDS[];
	const static string TENS[];
	const static string ONES[];
    string intToRoman(int num) {
		string result;
		result += THOUS[(int)(num/1000)%10];
		result += HUNDS[(int)(num/100)%10];
		result += TENS[(int)(num/10)%10];
		result += ONES[num%10];
		return result;
    }
};

const string Solution::THOUS[]	= {"","M","MM","MMM"};
const string Solution::HUNDS[]	= {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
const string Solution::TENS[]	= {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
const string Solution::ONES[]	= {"","I","II","III","IV","V","VI","VII","VIII","IX"};
//能用简单方法就用简单方法吧，这个如果用循环的方法太绕了
//给出一般方法，就是一位一位的给出判断，且由于表示方法不一样还不能分装成函数 
class Solution {
public:
    string intToRoman(int num) {
        string res;
        int qianwei=num/1000;
        int baiwei=(num-qianwei*1000)/100;
        int shiwei=(num-qianwei*1000-baiwei*100)/10;
        int gewei=num%10;
        while(qianwei>0)
        {
                res.push_back('M');
                qianwei--;
        }
         while(baiwei>0)
        {
             if(baiwei>=9)
             {
                res.push_back('C');
                res.push_back('M');
                baiwei=baiwei-9; 
             }
             else if(baiwei>=5)
             {
                res.push_back('D');
                baiwei=baiwei-5;
             }
             else if(baiwei>=4)
             {
                 res.push_back('C');
                 res.push_back('D');
                 baiwei=baiwei-4;
             }
             else
             {
                 res.push_back('C');
                 baiwei=baiwei-1;
             }
        }
        while(shiwei>0)
        {
            if(shiwei>=9)
             {
                res.push_back('X');
                res.push_back('C');
                shiwei=shiwei-9; 
             }
            else if(shiwei>=5)
             {
                res.push_back('L');
                shiwei=shiwei-5;
             }
             else if(shiwei>=4)
             {
                 res.push_back('X');
                 res.push_back('L');
                 shiwei=shiwei-4;
             }
             else
             {
                 res.push_back('X');
                 shiwei=shiwei-1;
             }
        }
        while(gewei>0)
        {
            if(gewei>=9)
             {
                res.push_back('I');
                res.push_back('X');
                gewei=gewei-9; 
             }
            else if(gewei>=5)
             {
                res.push_back('V');
                gewei=gewei-5;
             }
             else if(gewei>=4)
             {
                 res.push_back('I');
                 res.push_back('V');
                 gewei=gewei-4;
             }
             else
             {
                 res.push_back('I');
                 gewei=gewei-1;
             }
        }
        return res;
    }
}; 
