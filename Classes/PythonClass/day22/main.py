from turtle import Screen

from paddle import Paddle
from ball import Ball
from scoreboard import Scoreboard
import time
import pandas

screen = Screen()
screen.bgcolor("black")
screen.setup(800, 600)
screen.title("Pong")
screen.tracer(0)

l_paddle = Paddle((-350, 0))
r_paddle = Paddle((350, 0))

ball = Ball()
scoreboard = Scoreboard()

screen.listen()
screen.onkey(l_paddle.go_up, "w")
screen.onkey(l_paddle.go_down, "s")
screen.onkey(r_paddle.go_up, "Up")
screen.onkey(r_paddle.go_down, "Down")

game_over = False
while not game_over:
    time.sleep(ball.ball_speed)
    ball.move()
    screen.update()
    if ball.ycor() > 287 or ball.ycor() < -280:
        ball.bounce_y()
    if (ball.distance(r_paddle) < 50 and ball.xcor() > 340) or (ball.distance(l_paddle) < 50 and ball.xcor() < -340):
        ball.bounce_x()
    if ball.xcor() > 360:
        scoreboard.l_point()
        ball.reset_position()
    if ball.xcor() < -360:
        scoreboard.r_point()
        ball.reset_position()
    if scoreboard.l_score == 3 or scoreboard.r_score == 3:
        game_over = True

screen.exitonclick()
