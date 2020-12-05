class Turtle():
    def __init__(self, rows, columns):
        self.rows = rows
        self.columns = columns
        self.canvas = []
        self.canvas = [[0 for i in range(rows)] for j in range(columns)]
        self.orientation = 0
        self.curr_pos_x = None
        self.curr_pos_y = None

    def spawn_at(self, rows, columns):
        self.canvas[rows][columns] = self.canvas[rows][columns] + 1
        self.curr_pos_x = rows
        self.curr_pos_y = columns

    def move(self):
        if self.curr_pos_y == None or self.curr_pos_x == None:
            raise RuntimeError("you have to spawn the turtle first")

        if(self.orientation == 0):
            self.curr_pos_y += 1
            if self.curr_pos_y + 1 > self.rows:
                self.curr_pos_y = 0

        elif(self.orientation == 1):
            self.curr_pos_x += 1
            if self.curr_pos_x + 1 > self.columns:
                self.curr_pos_x = 0

        elif(self.orientation == 2):
            self.curr_pos_y -= 1
            if self.curr_pos_y + 1 > self.rows:
                self.curr_pos_y = 0

        elif(self.orientation == 3):
            self.curr_pos_x -= 1
            if self.curr_pos_x + 1 > self.columns:
                self.curr_pos_x = 0

        self.canvas[self.curr_pos_x][self.curr_pos_y] += 1

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
        self.pixel = []
        self.canvas = canvas
        self.symbol_list = symbol_list

    def draw(self):
        maxx = max(map(max, self.canvas))
        intensity = 0
        res = ""
        self.pixel = [[0 for i in range(len(self.canvas))] for j in range(len(self.canvas[0]))]

        for row in range(len(self.canvas)):
            for column in range(len(self.canvas[row])):
                intensity = self.canvas[row][column] / maxx
                if intensity == 0:
                    self.pixel[row][column] = self.symbol_list[0]
                elif intensity > 0 and intensity <= 0.3:
                    self.pixel[row][column] = self.symbol_list[1]
                elif intensity > 0.3 and intensity <= 0.6 and self.symbol_list[2]:
                    self.pixel[row][column] = self.symbol_list[2]
                elif intensity > 0.6 and intensity <= 1 and self.symbol_list[3]:
                    self.pixel[row][column] = self.symbol_list[3]

        string = [0 for i in range(len(self.canvas))]
        for i in range(len(self.canvas)):
            string[i]= ''.join(self.pixel[i])
        res = "\n".join(string)
        return res
