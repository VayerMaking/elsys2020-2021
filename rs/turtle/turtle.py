class Turtle():
    def __init__(self, rows, columns):
        self.rows = rows
        self.columns = columns
        self.canvas = []
        self.canvas = [[0 for i in range(rows)] for j in range(columns)]
        self.orientation = 0
        self.curr_pos_x = None
        self.curr_pos_y = None

    def print_rows_columns(self):
        print("rows: {}, columns: {}".format(self.rows, self.columns))

    def spawn_at(self, rows, columns):
        self.canvas[rows][columns] = self.canvas[rows][columns] + 1
        self.curr_pos_x = rows
        self.curr_pos_y = columns

    def print_turtle(self):
        print("##################")
        for list in self.canvas:
            print(list)
        print("##################")

    def check_orientation(self):
        return abs(self.orientation/90)

        # 0 = nadqsno
        # 1 = nadolu
        # 2 = nalqwo
        # 3 = nagore

    def move(self):
        if self.curr_pos_y == None or self.curr_pos_x == None:
            raise RuntimeError("you have to spawn the turtle first")

        if(self.orientation == 0):
            #print("nadqsno gleda")
            self.curr_pos_y += 1
            if self.curr_pos_y + 1 > self.rows:
                self.curr_pos_y = 0

        elif(self.orientation == 1):
            #print("nadolu gleda")
            self.curr_pos_x += 1
            if self.curr_pos_x + 1 > self.columns:
                self.curr_pos_x = 0

        elif(self.orientation == 2):
            #print("nalqwo gleda")
            self.curr_pos_y -= 1
            if self.curr_pos_y + 1 > self.rows:
                self.curr_pos_y = 0

        elif(self.orientation == 3):
            #print("nagore gleda")
            self.curr_pos_x -= 1
            if self.curr_pos_x + 1 > self.columns:
                self.curr_pos_x = 0

        self.canvas[self.curr_pos_x][self.curr_pos_y] += 1

    def reset_if_360(self):
        if(self.orientation == 360):
            self.orientation = 0


    def turn_right(self):
        self.orientation += 1
        if(self.orientation > 3):
            self.orientation = 0

    def turn_left(self):
        self.orientation -= 1
        if(self.orientation < 0):
            self.orientation = 3

class SimpleCanvas():
    def __init__(self, canvas, symbol_list):
        self.canvas = canvas
        self.symbol_list = symbol_list
    def draw(self):
        print("draw canvas",self.canvas)
        maxx = max(map(max, self.canvas))
        intensity = 0
        for row in range(len(self.canvas)):
            for column in range(len(self.canvas[row])):
                intensity = self.canvas[row][column] / maxx
                print("row cloomn",type(self.canvas[row][column]))
                print("maxx: ",type(maxx))

                if intensity == 0:
                    self.canvas[row][column] = self.symbol_list[0]
                elif intensity > 0 and intensity <= 0.3:
                    self.canvas[row][column] = self.symbol_list[1]
                elif intensity > 0.3 and intensity <= 0.6:
                    self.canvas[row][column] = self.symbol_list[2]
                elif intensity > 0.6 and intensity <= 1:
                    self.canvas[row][column] = self.symbol_list[3]


        #print(self.canvas)

        return self.canvas
