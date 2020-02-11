# -*- coding: utf-8 -*-
"""
Created on Mon May 29 15:05:13 2017

@author: mateo.lopez
"""


import multiprocessing as mp
import time



def prod1(Q1):
    N=10
    while N !=0:
        Q1.put(N)
        N=N-1
    Q1.put(-1)  

def prod2(Q2):
    N=10
    while N !=0:
        Q2.put(N*100)
        N=N-1
    Q2.put(-1)   

def cons1(Q1,sem1,sem2):
    n=0    
    while n!=-1:
        
        sem2.acquire()
        n=Q1.get()
        print(n)
        
        sem1.release()

def cons2(Q2,sem1,sem2):
    n=0    
    while n!=-1:
        
        sem1.acquire()
        n=Q2.get()
        print(n)
        
        sem2.release()
         
    






Q1=mp.Queue()
Q2=mp.Queue()

sem1=mp.Semaphore(1)
sem2=mp.Semaphore(0)

P1=mp.Process(target=prod1,args=(Q1,))
P2=mp.Process(target=prod2,args=(Q2,))

C1=mp.Process(target=cons1,args=(Q1,sem1,sem2))
C2=mp.Process(target=cons2,args=(Q2,sem1,sem2))

P1.start()
P2.start()
C1.start()
C2.start()

