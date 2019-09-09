'''
no. 32 
my original solution: use extra space as method 1
'''

def longestValidParentheses(s: str):
    '''method 1
    '''
    # use two stack to store
    ans = 0
    record = [0]*len(s)
    stack = []

    if not s: return 0

    for i in range(len(s)):
        # deal with first parenthese
        if s[i] == '(' or s[i] == '{' or s[i] == '[':
            stack.append(tuple([s[i], i])) # value-index storage
        elif s[i] == ')' and stack:
            if stack[-1][0] == '(': 
                v = stack.pop()[1]
                record[v] = 1
                record[i] = 1
    
    # calculate longest 
    print(record)
    i = 0
    tmp = 0
    while i < len(s):
        if not record[i]:
            ans = max(ans, tmp)
            tmp = 0
            i += 1
        elif record[i]:
            tmp += 1
            i += 1
    ans = max(ans, tmp)
    return ans

def dp(s: str):
    '''method 2: dynamic programming
    '''

if __name__ == "__main__":
    print(longestValidParentheses(')()())'))