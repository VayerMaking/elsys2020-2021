class Turtle():
    def __init__(self, rows, columns):
        self.rows = rows
        self.columns = columns
        self.canvas = []
        self.canvas = [[0 for i in range(rows)] for j in range(columns)]
        self.orientation = 0
        self.curr_pos_x = 0
        self.curr_pos_y = 0

    def print_rows_columns(self):
        print("rows: {}, columns: {}".format(self.rows, self.columns))

    def spawn_at(self, rows, columns):
        self.canvas[rows][columns] = self.canvas[rows][columns] + 1
        self.curr_pos_x = rows
        self.curr_pos_y = columns

    def print_turtle(self):
        print("##################")
        for list in turtle.canvas:
            print(list)
        print("##################")

    def check_orientation(self):
        return abs(self.orientation/90)



    def move(self):
        if(abs(self.orientation/90) == 0):
            print("nadqsno gleda")
            self.curr_pos_y += 1
            if self.curr_pos_y + 1 > self.rows:
                self.curr_pos_y = 0

        elif(abs(self.orientation/90) == 1):
            print("nadolu gleda")
            self.curr_pos_x += 1
            if self.curr_pos_x + 1 > self.columns:
                self.curr_pos_x = 0

        elif (abs(self.orientation/90) == 2):
            print("nalqwo gleda")
            self.curr_pos_y -= 1
            if self.curr_pos_y + 1 > self.rows:
                self.curr_pos_y = 0

        elif (abs(self.orientation/90) == 3):
            print("nagore gleda")
            self.curr_pos_x -= 1
            if self.curr_pos_x + 1 > self.columns:
                self.curr_pos_x = 0

        self.canvas[self.curr_pos_x][self.curr_pos_y] += 1

    def reset_if_360(self):
        if(self.orientation == 360):
            self.orientation = 0

    def turn_left(self):
        self.reset_if_360()
        self.orientation = self.orientation - 90

    def turn_right(self):
        self.reset_if_360()
        self.orientation = self.orientation + 90

# 0 = nadqsno
# 1 = nadolu
# 2 = nalqwo
# 3 = nagore

turtle = Turtle(3,3)
turtle.spawn_at(0,0)
turtle.print_rows_columns()
turtle.print_turtle()
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
print(turtle.check_orientation())
turtle.move()

print("turtle curr_pos_x : {}, turtle curr_pos_y : {}".format(turtle.curr_pos_x, turtle.curr_pos_y))