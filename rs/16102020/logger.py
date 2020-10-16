class Logger:
    def log(self, msg):
        raise NotImplementedError("neshtasnik")
        #print(msg)
class StdOutLogger(Logger):
    def log(self, msg):
        print(msg)
#logger = Logger()
logger2 = StdOutLogger()
logger2.log("qwerty")
#logger.log("asdf")
