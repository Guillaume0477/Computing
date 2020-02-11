# -*- coding: utf-8 -*-
"""
Created on Mon May 29 16:21:27 2017

@author: mateo.lopez
"""

import sys
import multiprocessing as mp

def message(nb,Type,recep,emet,N):
    if Type == "E":
        print("Le Processus ",nb," créé un message et se met en attente")
        
        for i in range(N):        
            recep.acquire()
        for i in range(N):
            emet.release()
        
        
        print("emetteur", nb ," se debloque")
    
    
    if Type == "R":
        
        print("Le Processus ",nb," se met en attente")
        recep.release()
        emet.acquire()
        print("recepteur", nb ," se debloque")
    
N = 3
arg = sys.argv
emet=mp.Semaphore(0)
recep=mp.Semaphore(0)
Process=[mp.Process(target = message, args=(i,arg[i+1],recep,emet,N)) for i in range(len(arg)-1)]
for i in Process:
    i.start()






