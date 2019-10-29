from threading import Thread, Condition
import time
import random

queue = []
condition = Condition()

class ProducerThread(Thread):
    def run(self):
        nums = range(5) #Will create the list [0, 1, 2, 3, 4]
        global queue
        while True:
            num = random.choice(nums) #Selects a random number from list [0, 1, 2, 3, 4]
            condition.acquire()
            queue.append(num)
            print ("Produced", num)
            condition.notify()
            condition.release()
            time.sleep(random.random())


class ConsumerThread(Thread):
    def run(self):
        global queue
        while True:
            condition.acquire()
            if not queue:
                print ("Nothing in queue, but consumer will try to consume")
                condition.wait()
                print("Wait for the producer to produce an item")
            num = queue.pop(0)
            print ("Consumed", num)
            condition.release()
            time.sleep(random.random())


ProducerThread().start()
ConsumerThread().start()