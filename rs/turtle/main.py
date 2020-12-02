class Turtle():
    def __init__(self, rows, columns):
        self.rows = rows
        self.columns = columns
        self.canvas = []
        self.canvas = [[0 for i in range(columns)] for j in range(rows)]
        self.pos = 0

    def print_rows_columns(self):
        print("rows: {}, columns: {}".format(self.rows, self.columns))

    def spawn_at(self, rows, columns):
        self.canvas[columns][rows] = self.canvas[columns][rows] + 1

    def print_turtle(self):
        print("##################")
        for list in turtle.canvas:
            print(list)
        print("##################")

    def check_pos(self):
        if(self.pos == 360):
            self.pos = 0
        if(abs(self.pos/90) == 0):
            print("nadqsno gleda")
        elif(abs(self.pos/90) == 1):
            print("nadolu gleda")
        elif (abs(self.pos/90) == 2):
            print("nalqwo gleda")
        elif (abs(self.pos/90) == 3):
            print("nagore gleda")
        return abs(self.pos/90)

    def move(self):
        pass
        #self.check_pos()
        #self.canvas[1][1] = 1

    def turn_left(self):
        self.pos = self.pos - 90

    def turn_right(self):
        self.pos = self.pos + 90

# 0 = nadqsno
# 1 = nadolu
# 2 = nalqwo
# 3 = nagore

turtle = Turtle(3,3)
turtle.spawn_at(0,0)
turtle.print_rows_columns()
turtle.print_turtle()
turtle.move()
turtle.print_turtle()
print("default pos", turtle.pos)
turtle.turn_left()
print("changed pos", turtle.pos)
turtle.turn_right()
print("changed pos", turtle.pos)
turtle.turn_right()
print("changed pos", turtle.pos)
turtle.turn_right()
print("changed pos", turtle.pos)
turtle.turn_right()
print("changed pos", turtle.pos)

print(turtle.check_pos())
