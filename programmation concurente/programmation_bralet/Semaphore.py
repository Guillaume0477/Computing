# -*- coding: utf-8 -*-
"""
Created on Fri Jun  1 08:04:44 2018

@author: antoine.bralet
"""

import multiprocessing as mp
import sys
import os

#Exercice 1 : 

Somme = mp.Value('d',0)

def impair(Somme,L,N) :
    i = 1
    SommeImpairs = 0
    while i <= N : 
        SommeImpairs += int(L[i])
        i = i+2
    Somme.value = Somme.value +SommeImpairs

def pair(Somme,L,N) :
    i = 0
    SommePairs = 0
    while i <= N : 
        SommePairs += int(L[i])
        i = i+2
    Somme.value = Somme.value +SommePairs

L = list(sys.argv[1 :])
print(L)
N = len(L)-1
print(N)

P1 = mp.Process(target = pair, args = (Somme,L,N))
P2 = mp.Process(target = impair, args = (Somme,L,N))

P1.start()
P2.start()
P1.join()
P2.join()

print(Somme.value)

