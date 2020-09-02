import sys


def CheckString(test):
    stack = ""
    for bracket in test:
        if bracket == '(' or bracket == '[':
            stack += bracket
        elif bracket == ')':
            bracket = '('
            if stack.__len__() > 0:
                if stack[-1] == bracket:
                    stack = stack[0:-1]
                else:
                    return False
            else:
                return False
        elif bracket == ']':
            bracket = '['
            if stack.__len__() > 0:
                if stack[-1] == bracket:
                    stack = stack[0:-1]
                else:
                    return False
            else:
                return False
        else:
            return False
    if stack == "":
        return True
    else:
        return False


if __name__ == '__main__':
    #f = open("infile.txt", "r")
    # iterations = int(f.readline())
    iterations = int(input())
    for i in range(iterations):
        data = input().strip()
        # data = f.readline().strip()
        result = CheckString(data)
        if result:
            print("Yes")
        else:
            print("No")
        i += 1
    sys.exit()
