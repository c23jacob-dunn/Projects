answertoQ = ""
guessednumber = 50 
done = True
prevAnswer = ""
count = 1

while(done):
    print("Im guessing is", guessednumber, "is it higher, lower or correct?: ")
    answertoQ = (input())
    if(count == 1):
        prevAnswer = answertoQ
        other = high
        count += 1
    else: 
        prev 

    if(answertoQ == "low" and prevAnswer == "low"):
        guessednumber //= 2
    elif((answertoQ == "high" and prevAnswer == "low") or (answertoQ == "low" and prevAnswer == "high")):
        guessednumber = (prevAnswer + guessednumber) // 2
    elif(answertoQ == "high" and prevAnswer == "high"):
        guessednumber = guessednumber // 2 + 50
    elif(answertoQ == "correct"):
        print("you win")
        done = False
    else:
        print("dumbass")