/*



Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).



class Solution:
    def numDecodings(self, digits: str) -> int:
        if(digits[0]=='0'):
            return 0
        count = [0] * (len(digits) + 1) 
        count[0] = 1;  
        count[1] = 1;  
        for i in range(2, len(digits) + 1):  
            count[i] = 0;  
            if (digits[i - 1] > '0'):  
                count[i] = count[i - 1];    
            if (digits[i - 2] == '1' or (digits[i - 2] == '2' and digits[i - 1] < '7') ):  
                count[i] += count[i - 2];  

        return count[len(digits)];  
                
            
    

*/