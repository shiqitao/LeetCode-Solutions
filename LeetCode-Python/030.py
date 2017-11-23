class Solution:
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        dic = {}
        for word in words:
            if word not in dic:
                dic[word] = 1
            else:
                dic[word] += 1
        step = len(words[0])
        length = len(s)
        num = len(words)
        result = []
        for i in range(length-step*num+1):
            d = {}
            right = True
            for j in range(num):
                stemp = s[i+j*step:i+(j+1)*step]
                if stemp not in dic:
                    right = False
                    break
                elif stemp not in d:
                    d[stemp] = 1
                else:
                    d[stemp] += 1
                    if d[stemp] > dic[stemp]:
                        right = False
                        break
            if right == True:
                result.append(i)
        return result