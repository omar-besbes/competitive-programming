import sys
import os
import random

sys.stdout = open("testcase.txt", "w")

class RandomGenerator():
    def __init__(self):
        pass

    def integer(self, lower_bound, upper_bound):
        ret = random.randint(lower_bound, upper_bound)
        return ret

    def array(self, array_size, lower_bound, upper_bound):
        l = [0]*array_size
        for index, element in enumerate(l):
            l[index] = self.integer(lower_bound, upper_bound)
        return l


if __name__ == "__main__":
    rand = RandomGenerator()

    t = 1
    print(t)
    for __ in range(t):
        n = rand.integer(1, 2*1000)

        print(n, end=" ")
        print()

        for ele in rand.array(n, 1, n):
            print(ele, end=" ")
        print()