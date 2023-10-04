class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        # for simplicity, I am using python so that array increase 
        # in len can be taken care with less code
        reversed_list = digits[::-1]
        i = 0
        carry = 0
        for val in reversed_list:
            summ= val + 1  #carry=1
            if (summ == 10): 
                reversed_list[i] = 0
                carry = 1
            else :
                reversed_list[i] = summ
                carry = 0
                break
            i = i + 1

        if (carry == 1):
            reversed_list.append(1)

        return reversed_list[::-1]
