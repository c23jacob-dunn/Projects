import sys

def CheckPathsFunc():
    completePaths = ''
    for x in range():
        for y in range():
            if arr[2-x][y] == '*':
                print("!")
            elif arr[2-x][y].isalpha():
                completePaths += arr[2-x][y]
            elif arr[2-x][y] == '║':
                print("!")
            elif arr[2-x][y] == '╔':
                print("!")
            elif arr[2-x][y] == '╗':
                print("!")
            elif arr[2-x][y] == '╚':
                print("!")
            elif arr[2-x][y] == '╝':
                print("!")
            elif arr[2-x][y] == '╠':
                print("!")
            elif arr[2-x][y] == '╣':
                print("!")
            elif arr[2-x][y] == '╦':
                print("!")
            elif arr[2-x][y] == '╩':
                print("!")
            else:
                print("Uh oh")

file = open(sys.argv[1], "r", encoding="utf-8")
numLines = len(file.readlines())
file.close()

above = ['║', '╔', '╗', '╠', '╣', '╦']
below = ['║', '╚', '╝', '╠', '╣', '╩']
left  = ['═', '╔', '╚', '╠', '╦', '╩']
right = ['═', '╗', '╝', '╣', '╦', '╩']

rows, cols = (3, 6)
arr = [['' for i in range(cols)] for j in range(rows)]

file = open(sys.argv[1], "r", encoding="utf-8")
for i in range(numLines):
    content = file.readline()
    content = content.strip()
    content = content.split(' ')

    char = content[0]
    yCoord = int(content[1])
    xCoord = int(content[2])
    
    arr[2-xCoord][yCoord] = char

print(arr)

file.close()

answer = CheckPathsFunc()