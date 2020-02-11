# -*- coding: utf-8 -*-
"""
Created on Mon May 29 14:31:51 2017

@author: mateo.lopez
"""
import time
import multiprocessing as mp
def T1(sem):
    print("processus t1 lancé")
    time.sleep(1)
    print("fin processus T1")
    sem.release()
    print(sem)
def T2(sem):
    print("processus t2 lancé")
    sem.acquire()
    
    print("fin processus T2")
    sem.release()
    
sem= mp.Semaphore(0)
P1 = mp.Process(target=T1,args=(sem,))
P2 = mp.Process(target=T2,args=(sem,))

P1.start()
P2.start()