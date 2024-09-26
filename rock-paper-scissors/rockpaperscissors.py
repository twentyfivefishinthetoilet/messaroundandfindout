# the first rock paper scissors i've ever made... it's beautiful...
# DATE MADE: 1/3/2024

import random
import time

Goodbye = ["See you next time!", "Hope to see you soon.", "Adios, amigo!", "Thanks for playing!"]
see_ya = random.choice(Goodbye)

print("ROCK, PAPER, SCISSORS!")
print("-----------------------------")
time.sleep(1)
print("HOW TO PLAY:")
print("-----------------------------")
time.sleep(1)
print("Type out your move in the output and i'll throw one back at you!")
print("Good luck!")
print("-----------------------------")
time.sleep(1)
print("And now that thats over with...")
while True:
    choices = ["rock", "paper", "scissors"]
    computer = random.choice(choices)
    player = None
    while player not in choices:
        player = input("Rock, Paper Scissors, SHOOT! ").lower()

        if player == computer:
            print("CPU:", computer)
            print("You:", player)
            print("Tie!")

        elif player == "rock":

            if computer == "paper":

                print("CPU:", computer)
                print("You:", player)
                print("You Lose!")

            if computer == "scissors":
                print("CPU:", computer)
                print("You:", player)
                print("You Win!")

        elif player == "paper":
            if computer == "scissors":
                print("CPU:", computer)
                print("You:", player)
                print("You Lose!")

            if computer == "rock":
                print("CPU:", computer)
                print("You:", player)
                print("You Win!")

        elif player == "scissors":
            if computer == "paper":
                print("CPU:", computer)
                print("You:", player)
                print("You Win!")

            if computer == "rock":
                print("CPU:", computer)
                print("You:", player)
                print("You Lose!!")


    play_again = input("Play again? (y/n): ").lower()

    if play_again != "y":
        print("-----------------------------")
        print(see_ya)
        print("-----------------------------")
        time.sleep(5)
        break