//hashmap实现 
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    	vector<int> res;
		if(numbers.size() <= 1) return res;
		unordered_map<int, int> m;
		for(int i = 0; i < numbers.size(); ++i) {
			m[ numbers[i] ] = i;
		}
		for(int i = 0; i < numbers.size(); ++i) {
			int rest = target - numbers[i];
			if( m.find(rest) != m.end() ) {
				int j = m[rest];
				if(i == j) continue;
				if( i > j ) {
					res.push_back( j+1 );
					res.push_back( i+1 );
				}  else {
					res.push_back( i+1 );
					res.push_back( j+1 );
				}
				return res;
			}
 		}
    }
};
//lower_bound实现 
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int sz = numbers.size();
        int i,j;
        for(i = 0 ; i < sz; i++){
            int t = target - numbers[i];
            int pos = lower_bound(&numbers[i+1], &numbers[sz -1],t) - (&numbers[i + 1]);
            pos+=i+1;
            if(pos < sz && numbers[pos] + numbers[i] == target){
                ans.push_back(i+1);
                ans.push_back(pos+1);
                return ans;
            }
        }
    }
};
