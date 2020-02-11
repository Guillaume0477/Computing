# -*- coding: utf-8 -*-
"""
Created on Fri Jun  1 10:35:45 2018

@author: antoine.bralet
"""
import multiprocessing as mp
import sys
import os
import time 

verrou = mp.Semaphore(1)
verrou2 = mp.Semaphore(0)
verrou3 = mp.Semaphore(0)


def A() : 
    verrou.acquire()
    print("Vive le dodo de A")
    time.sleep(2)
    print("Coucou je suis le processus A et j'ai attendu 2 secondes")
    verrou.release()
    verrou.release()
    verrou.release()

def B() : 
    verrou.acquire()
    print("Vive le dodo de B")
    time.sleep(3)
    print("Coucou je suis le processus B et j'ai attendu 3 secondes")
    verrou2.release()

def C() : 
    verrou.acquire()
    print("Vive le dodo de C")
    time.sleep(6)
    print("Coucou je suis le processus C et j'ai attendu 6 secondes")
    verrou2.release()
    
def D() : 
    verrou.acquire()
    print("Vive le dodo de D")
    time.sleep(4)
    print("Coucou je suis le processus D et j'ai attendu 4 secondes")
    verrou3.release()

def E() : 
    verrou2.acquire()
    verrou2.acquire()
    print("Vive le dodo de E")
    time.sleep(1)
    print("Coucou je suis le processus E et j'ai attendu 1 secondes")
    verrou3.release()

def F() : 
    verrou3.acquire()
    verrou3.acquire()
    print("Vive le dodo de F")
    time.sleep(3)
    print("Coucou je suis le processus F et j'ai attendu 3 secondes")
    
PA = mp.Process(target = A, args =())
PB = mp.Process(target = B, args=())
PC = mp.Process(target = C, args =())
PD = mp.Process(target = D, args =())
PE = mp.Process(target = E, args =())
PF = mp.Process(target = F, args =())

PA.start()
PB.start()
PC.start()
PD.start()
PE.start()
PF.start()
