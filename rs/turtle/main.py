from turtle import Turtle
from turtle import SimpleCanvas

turtle = Turtle(3,3)
turtle.spawn_at(0,0)

turtle.turn_right()
turtle.print_turtle()
turtle.move()
turtle.print_turtle()
turtle.move()
turtle.print_turtle()
turtle.move()
turtle.print_turtle()
'''
print("default orientation", turtle.orientation)
turtle.turn_left()
print("changed orientation", turtle.orientation)
turtle.turn_right()
print("changed orientation", turtle.orientation)
turtle.turn_right()
print("changed orientation", turtle.orientation)
turtle.turn_right()
print("changed orientation", turtle.orientation)
turtle.turn_right()
print("changed orientation", turtle.orientation)
turtle.turn_right()
print("changed orientation", turtle.orientation)
turtle.turn_right()
print("changed orientation", turtle.orientation)
turtle.turn_right()
print("changed orientation", turtle.orientation)
'''
turtle.move()

print("turtle curr_pos_x : {}, turtle curr_pos_y : {}".format(turtle.curr_pos_x, turtle.curr_pos_y))
