# -*- coding: utf-8 -*-
"""
Created on Fri May 12 10:52:41 2017

@author: mateo.lopez
"""

import os, time, random, sys

for i in range(4) :

    if os.fork() != 0 :

        break

random.seed()

delai = random.randint(0,4)

time.sleep(delai)
try:
    os.wait()
except:
    pass

print   (str(i)+ " Mon  nom  est  "  +  chr(ord('A')+i)  +  "  j  ai  dormi  "  + str(delai) +  " secondes")

os._exit(0)