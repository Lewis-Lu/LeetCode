'''
no. 71
'''
def simplifyPath(path: str) -> str:
    s = [p for p in path.split('/') if p != '' and p != '.']
    stack = []
    for p in s:
        if p == '..':
            if stack: stack.pop()
        else:
            stack.append(p)
    ans = '/' + '/'.join(stack)
    return ans


if __name__ == "__main__":
    
    print(simplifyPath("/a//b////c/d//././/.."), end='\n')