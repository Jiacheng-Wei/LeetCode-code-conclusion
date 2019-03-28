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
					res.push_back( j );
					res.push_back( i );
				}  else {
					res.push_back( i );
					res.push_back( j );
				}
				return res;
			}
 		}
    }
};
