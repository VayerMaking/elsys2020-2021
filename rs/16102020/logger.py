class Logger:
    def log(self, msg):
        raise NotImplementedError("neshtasnik")
        #print(msg)
class StdOutLogger(Logger):
    def log(self, msg):
        print(msg)
class FileLogger(Logger):
    def __init__(self, filename):
        self.file = open(filename, 'a')

    def log(self, msg):
        self.file.write(msg)

    def __del__(self):
        self.file.close()
#logger = Logger()
logger2 = StdOutLogger()
logger3 = FileLogger("log.txt")
logger3.log("234\n")
logger2.log("qwerty")
#logger.log("asdf")
