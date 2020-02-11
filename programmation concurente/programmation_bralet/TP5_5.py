# -*- coding: utf-8 -*-
"""
Created on Fri Jun  8 08:44:32 2018

@author: antoine.bralet
"""

import time
import os
import multiprocessing as mp
import sys
import random
from math import *

nb_process = 3
verrou = mp.Semaphore(1)
Sglobal = mp.Value('i',0)

N = sys.argv[1]
tableau = [1 for k in range(int(N))]

tdepart = time.time()
S = sum(tableau)
tfin = time.time()

print (S, tfin - tdepart)

tdepart2 = time.time()
def compte(liste):
    S = sum(liste)
    print(S)
    verrou.acquire()
    Sglobal.value += S
    verrou.release()
    os._exit(0)

pid1 = mp.Process(target=compte, args=(tableau[: floor(len(tableau)/nb_process)],))
pid2 = mp.Process(target = compte, args = (tableau[floor(len(tableau)/nb_process):floor(len(tableau)*2/nb_process)],))
pid3 = mp.Process(target = compte, args = (tableau[floor(len(tableau)*2/nb_process):],))

pid1.start()
pid2.start()
pid3.start()

pid1.join()
pid2.join()
pid3.join()
tfin2 = time.time()

print(Sglobal.value, tfin2 - tdepart2)
    