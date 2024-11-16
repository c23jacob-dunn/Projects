from turtle import Turtle
import random

from turtlecrossing.player import MOVE_DISTANCE

COLORS = ["red", "orange", "yellow", "green", "blue", "purple"]
STARTING_MOVE_DISTANCE = 5
MOVE_INCREMENT = 10

class CarManager(Turtle):
    def __init__(self):
        super().__init__()
        self.shape("square")
        self.shapesize(1,2)
        self.penup()
        self.color(random.choice(COLORS))
        self.goto(300, random.randint(-260, 300))
        self.setheading(180)

    def move(self, level):
        self.forward(STARTING_MOVE_DISTANCE + (MOVE_INCREMENT * level))

