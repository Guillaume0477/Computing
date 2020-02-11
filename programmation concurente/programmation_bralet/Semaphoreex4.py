# -*- coding: utf-8 -*-
"""
Created on Fri Jun  1 11:26:08 2018

@author: antoine.bralet
"""

import multiprocessing as mp
import sys
import os
import time 
import random

Q1 = mp.Queue()
Q2 = mp.Queue()
semC1 = mp.Semaphore(0)
semC2 = mp.Semaphore(0)

def production1() : 
    for l in range(10):
        k = random.randint(0, 3)
        print("Je suis P1 et j'envoie la valeur",k)
        Q1.put(k)

def consommateur1() :
    for p in range(10):
        a = Q1.get()
        time.sleep(a)
        print("Je suis C1 et je lis la valeur", a, "je suis a l'iteration", p)
        semC2.release()
        semC1.acquire()

def production2() : 
    for l in range(10):
        k = random.randint(0, 3)
        print("Je suis P2 et j'envoie la valeur",k)
        Q2.put(k)

def consommateur2() :
    for p in range(10):
        a = Q2.get()
        time.sleep(a)
        print("Je suis C2 et je lis la valeur", a, "je suis a l'iteration", p)
        semC1.release()
        semC2.acquire()

P1 = mp.Process(target = production1, args = ())
P2 = mp.Process(target = production2, args = ())
C1 = mp.Process(target = consommateur1, args = ())
C2 = mp.Process(target = consommateur2, args = ())

P1.start()
P2.start()
C1.start()
C2.start()
    