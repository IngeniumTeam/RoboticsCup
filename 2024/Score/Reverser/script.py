scoreFinal = int(input("Score final: "))
esti = int(input("Estimation: "))
score = 0
for i in range (100):
    if (esti - score + score == scoreFinal or score - esti + score == scoreFinal):
        print(score)
    score += 0.5
input("Tap enter to close")
