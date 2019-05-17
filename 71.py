class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        
        stack = []
        for d in path.split('/'):
            if len(d) > 0:
                if d == '.':
                    continue
                elif d == '..':
                    if len(stack) > 0:
                        stack.pop()
                else:
                    stack.append(d)
        # print(stack)
        
        ans = '/' + '/'.join(stack)
        
        return ans
