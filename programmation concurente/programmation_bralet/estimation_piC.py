# -*- coding: utf-8 -*-
"""
Created on Fri Jun  8 11:26:25 2018

@author: antoine.bralet
Group : A
Authors : METEYER Paul & BRALET Antoine
Date : 08/06/2018
Content: Estimation de pi par méthode de l'aiguille de Buffon
"""

import time
import os
import multiprocessing as mp
import sys
import random
from math import *

def MonoProcess(aiguilles,a,lbd):
    for k in range(aiguilles):
        x = a*random.rand()
        theta = pi*random.rand()
        