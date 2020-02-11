# -*- coding: utf-8 -*-
"""
Created on Mon Jun 12 13:38:13 2017

@author: mateo.lopez
"""

import time, sys
import multiprocessing as mp
import numpy as np

def calculbase(N):
    S=0
    liste = np.ones(N)
    t1=time.time()
    for i in range (len(liste)):
        S=S+liste[i]
    t2=time.time()
    Temps=t2-t1
    return [S, Temps]
    
def sommepartielle(N,Sem,Somme):
    S=0
    liste = np.ones(N)
    for i in range (len(liste)):
        S=S+liste[i]
    S=int(S)
    Sem.acquire()
    Somme.value=Somme.value + S
    Sem.release()
    return S    
    
    
    
    
    

N=10000000
P=2
n1=N//P
n2=N%P

SOMME=mp.Value('i',0)
Sem=mp.Semaphore(1)


Process=[]
for i in range (P):
    if i == P-1:
        Process.append(mp.Process(target = sommepartielle, args=(n1+n2,Sem,SOMME)))
    else:
        Process.append(mp.Process(target = sommepartielle, args=(n1,Sem,SOMME)))
t1=time.time()    
for i in Process:
    i.start()    

for i in Process:
    i.join()   
t2=time.time()

print ([SOMME.value,t2-t1])
    
