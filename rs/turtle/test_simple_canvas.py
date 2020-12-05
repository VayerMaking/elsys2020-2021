from turtle import Turtle
from turtle import SimpleCanvas


turtle = Turtle(3, 3)
turtle.spawn_at(0, 0)
for i in range(9):
    turtle.move()
turtle.turn_right()
for i in range(4):
    turtle.move()
turtle.turn_left()
turtle.move()
turtle.move()
turtle.turn_right()
turtle.move()

print("turtle", turtle.print_turtle())
#turtle <turtle.Turtle object at 0x7f03aeaad6a0>
##################
#[5, 3, 3]
#[2, 1, 1]
#[1, 0, 1]
##################

canvas = SimpleCanvas(turtle.canvas, [' ', '*', '@', '#'])
print(canvas.draw())
