# -*- coding: utf-8 -*-
"""
Created on Fri Jun  8 10:48:11 2018

@author: antoine.bralet
Group : A
Authors : METEYER Paul & BRALET Antoine
Date : 08/06/2018
Content: Estimation de pi par méthode arc-tangente
"""

import time
import os
import multiprocessing as mp
import sys
import random
from math import *

def MonoProcess(pas):
    S = 0 
    for k in range(1,pas+1) :
        S += (1/pas) * 4/(1+((k-0.5)/pas)**2)
    return S

def PluriProcess(pas,debut,fin):
    S = 0 
    for k in range(debut,fin) :
        S += (1/pas) * 4/(1+((k-0.5)/pas)**2)
    Sem.acquire()
    Pifin.value += S
    Sem.release()

#Calcul en monoprocess
increment = 10000000
td = time.time()
picalcul = MonoProcess(increment)
tf = time.time()
print("Valeur estimée Pi par la méthode Mono−Processus : ", picalcul, "et j'ai mis ", tf-td,"secondes")

#Calcul en pluriprocess
Sem = mp.Lock()
Pifin = mp.Value('f',0)
nb_process = 9
liste_pid = []

td2 = time.time()
liste_pid.append(mp.Process(target = PluriProcess, args=(increment,1,floor(increment/nb_process),)))
liste_pid[-1].start()

for k in range(1,nb_process-1):
    liste_pid.append(mp.Process(target = PluriProcess, args=(increment,floor(increment*k/nb_process),floor(increment*(k+1)/nb_process),)))
    liste_pid[-1].start()

liste_pid.append(mp.Process(target = PluriProcess, args=(increment,floor(increment-increment/nb_process),increment,)))
liste_pid[-1].start()

for k in liste_pid : 
    k.join()

tf2 = time.time()

print("Valeur estimée Pi par la méthode Pluri−Processus : ", Pifin.value, "et j'ai mis ", tf2-td2,"secondes")


