# -*- coding: utf-8 -*-
"""
Created on Fri Jun  8 11:36:16 2018

@author: antoine.bralet
Group : A
Authors : METEYER Paul & BRALET Antoine
Date : 08/06/2018
Content: Estimation de pi par méthode d'espérance
"""

import time
import os
import multiprocessing as mp
import sys
import random
from math import *

def Monoprocess(tirage):
    S = 0
    for k in range(tirage):
        a = random.random()
        S+= sqrt(1-a**2)
    return S

def MultiProcess(tirage):
    S = 0
    for k in range(tirage):
        a = random.random()
        S+= sqrt(1-a**2)
    Sem.acquire()
    Stot.value += S
    Sem.release()

#Calcul monoprocessus
N = 10000000
td = time.time()
Sfin= Monoprocess(N)
tf = time.time()
print("Valeur estimée Pi par la méthode Mono−Processus : ", 4*Sfin/N, "et j'ai mis ", tf-td,"secondes")

#Calcul Multiprocess
Sem = mp.Lock()
Stot = mp.Value('f',0)
nb_process = 10
liste_pid = []

td2 = time.time()
for k in range(1,nb_process):
    liste_pid.append(mp.Process(target = MultiProcess, args= (floor(N/nb_process),)))
    liste_pid[-1].start()

liste_pid.append(mp.Process(target = MultiProcess, args= (N-(nb_process-1)*floor(N/nb_process),)))
liste_pid[-1].start()

for k in liste_pid :
    k.join()

tf2 = time.time()
    
print("Valeur estimée Pi par la méthode Pluri−Processus : ", 4*Stot.value / N, "et j'ai mis ", tf2-td2,"secondes")

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    