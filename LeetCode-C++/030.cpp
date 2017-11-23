class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		int len = s.size();
		int m = words.size();
		int step = words[0].size();
		unordered_map<string, int> wordMap;
		for (int i = 0; i < m; i++) {
			wordMap[words[i]] += 1;
		}
		int stop = len - m*step + 1;
		vector<int> result;
		result.reserve(stop);
		for (int i = 0; i < stop; i++) {
			unordered_map<string, int> tempMap = wordMap;
			int j;
			for (j = 0; j < m; j++) {
				string temp = "";
				int start = i + j*step;
				int end = i + (j + 1)*step;
				for (int k = start; k < end; k++) {
					temp += s[k];
				}
				if (tempMap[temp] != 0) {
					tempMap[temp]--;
				}
				else {
					break;
				}
			}
			if (j == m) {
				result.push_back(i);
			}
		}
		return result;
	}
};