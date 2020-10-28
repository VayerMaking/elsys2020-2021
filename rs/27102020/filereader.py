class FileRead:
    def __init__(self, filename):
        self.file = open(filename, 'r')
    def __iter__(self):
        return self
    def __next__(self):
        line = self.file.readline()
        if line:
            return line
        raise StopIteration()
    def __del__(self):
        self.file.close()

fr = FileRead("sometextfile.txt")

for i in fr:
    print(i)
