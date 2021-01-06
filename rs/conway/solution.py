from time import sleep


def next_generation(grid):
    new = [[0 for n in range(len(grid))] for k in range(len(grid))]

    for i in range(len(grid)):
        for j in range(len(grid)):

            total = 0
            for a in range(-1, 2):
                for b in range(-1, 2):
                    c = (i + a + len(grid)) % len(grid)
                    r = (j + b + len(grid)) % len(grid)
                    total += grid[c][r]
            total -= grid[i][j]

            if grid[i][j] == 0:
                if total == 3:
                    new[i][j] = 1
            else:
                if total < 2 or total > 3:
                    new[i][j] = 0
                else:
                    new[i][j] = grid[i][j]
    return new
'''

def print_grid(grid):
    for row in grid:
        for cell in row:
            print('■' if cell else '□', end=' ')
        print('')


def animate(grid):
    generation = grid
    while True:
        print('')
        print('')
        print_grid(generation)
        sleep(1)
        generation = next_generation(generation)


g = [[0 for i in range(15)] for k in range(15)]
g[2][1] = 1
g[2][2] = 1
g[2][3] = 1
g[1][3] = 1
g[0][2] = 1

animate(g)
'''
