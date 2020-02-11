# -*- coding: utf-8 -*-
"""
Created on Mon May 15 13:39:43 2017

@author: mateo.lopez
"""

import os,sys,time
import multiprocessing as mp

def send(dfw):
    a = 12
    dfw.send(a)
    sys.exit(0)


dfr,dfw = mp.Pipe()


pid = mp.Process(target=send, args=(dfw,))



pid.start()
dfw.close()
pid.join()

print("On a recu :", str(dfr.recv()))

dfr.close()