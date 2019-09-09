'''
no. 20
'''
def isValid(s: str) -> bool:
    # initialize list as stack
    stack = []
    # deal with str
    for i in range(len(s)):
        
        if s[i] == '(' or s[i] =='{' or s[i] =='[':
            stack.append(s[i])
        elif s[i] == ')':
            if len(stack) != 0 and stack[-1] == '(': stack.pop()
            else: return False
        elif s[i] == '}':
            if len(stack) != 0 and stack[-1] == '{': stack.pop()
            else: return False
        elif s[i] == ']':
            if len(stack) != 0 and stack[-1] == '[': stack.pop()
            else: return False

    if len(stack) != 0: return False
    else: return True


if __name__ == "__main__":
    print(isValid(']'))