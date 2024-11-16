import time
from turtle import Screen

from player import Player
from car_manager import CarManager
from scoreboard import Scoreboard
import random

screen = Screen()
screen.setup(width=600, height=600)
screen.tracer(0)

scoreboard = Scoreboard()
player = Player()
level = 0
cars = []

screen.listen()
screen.onkey(player.move, "Up")

game_is_on = True
while game_is_on:
    if random.randint(1,3) == 1:
        car_manager = CarManager()
        cars.append(car_manager)
    time.sleep(0.1)
    screen.update()
    if player.level_over():
        player.reset_position()
        scoreboard.update_scoreboard()
        level += 1
    for car in cars:
        if car.distance(player) < 20:
            game_is_on = False
            scoreboard.game_over()
        car.move(level)

screen.exitonclick()