# -*- coding: utf-8 -*-
"""
Created on Thu May  4 10:56:50 2017

@author: mateo.lopez
"""

import os, sys
import multiprocessing as mp
import time

df1 = os.open("entree" ,os.O_RDONLY)
df2 = os.open("sortie" , os.O_WRONLY | os.O_CREAT)
df3 = os.open("trace" , os.O_WRONLY | os.O_CREAT)

pid = os.fork()
car=os.read(df1,1)
while car != b""
    if pid==0:
        os.write(df3,b"#" + car)
    else :
        os.write(df3,b"$" + car)
    os.write(df2,car)
    car = os.read(df1,1)

os.close(df1)
os.close(df2) 