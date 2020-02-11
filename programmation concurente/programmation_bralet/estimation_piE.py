# -*- coding: utf-8 -*-
"""
Created on Fri Jun  8 11:53:04 2018

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

def MonoProcess(Nmax,pas):
    S = 0
    for k in range(int(Nmax/pas)):
        S+= exp(-((k*pas)**2)/2)*pas
    return S
    
N = 100000
pas = 0.01
td = time.time()
Sfin = MonoProcess(N,pas)
tf = time.time()
print(Sfin)
print("Valeur estimée Pi par la méthode Mono−Processus : ", 2*(Sfin**2), "et j'ai mis ", tf-td,"secondes")



































