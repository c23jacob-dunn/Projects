# from turtle import Turtle, Screen
#
# tim = Turtle()
# screen = Screen()
# tim.speed("fastest")
# heading = 0
#
# def move_forward():
#     tim.forward(10)
#
# def move_backward():
#     tim.backward(10)
#
# def turn_right():
#     global heading
#     heading -= 10
#     tim.setheading(heading)
#
# def turn_left():
#     global heading
#     heading += 10
#     tim.setheading(heading)
#
# def clear_screen():
#     tim.penup()
#     tim.clear()
#     tim.home()
#
# screen.listen()
#
# screen.onkey(key = "w", fun = move_forward)
# screen.onkey(key = "s", fun = move_backward)
# screen.onkey(key = "a", fun = turn_left)
# screen.onkey(key = "d", fun = turn_right)
# screen.onkey(key = "c", fun = clear_screen)
#
# screen.exitonclick()

from turtle import Turtle, Screen
import random

screen = Screen()
red = Turtle()
red.shape("turtle")
red.color("red")
red.penup()
red.goto(-300, 125)

orange = Turtle()
orange.shape("turtle")
orange.color("orange")
orange.penup()
orange.goto(-300, 75)

yellow = Turtle()
yellow.shape("turtle")
yellow.color("yellow")
yellow.penup()
yellow.goto(-300, 25)

green = Turtle()
green.shape("turtle")
green.color("green")
green.penup()
green.goto(-300, -25)

blue = Turtle()
blue.shape("turtle")
blue.color("blue")
blue.penup()
blue.goto(-300, -75)

purple = Turtle()
purple.shape("turtle")
purple.color("purple")
purple.penup()
purple.goto(-300, -125)

game_over = False
winner = ""
guess = screen.textinput(title = "Make your bet", prompt = "Who is going to win: ")

while not game_over:
    red.forward(random.randint(5, 35))
    orange.forward(random.randint(5, 35))
    yellow.forward(random.randint(5, 35))
    green.forward(random.randint(5, 35))
    blue.forward(random.randint(5, 35))
    purple.forward(random.randint(5, 35))

    if red.xcor() >= 300:
        game_over = True
        winner = "red"
    elif orange.xcor() >= 300:
        game_over = True
        winner = "orange"
    elif yellow.xcor() >= 300:
        game_over = True
        winner = "yellow"
    elif green.xcor() >= 300:
        game_over = True
        winner = "green"
    elif blue.xcor() >= 300:
        game_over = True
        winner = "blue"
    elif purple.xcor() >= 300:
        game_over = True
        winner = "purple"

if winner == guess:
    print(f"You win, {winner} won the race!")
else:
    print(f"You lose, {winner} won the race.")

screen.exitonclick()