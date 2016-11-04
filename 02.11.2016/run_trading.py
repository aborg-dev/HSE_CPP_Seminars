import time
import datetime
import sys

while True:
    sys.stdout.write("{}: Still trading...\n".format(datetime.datetime.now()))
    sys.stdout.flush()
    time.sleep(3)
