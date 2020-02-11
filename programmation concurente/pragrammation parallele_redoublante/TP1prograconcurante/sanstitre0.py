# -*- coding: utf-8 -*-
"""
Created on Thu May  4 08:19:18 2017

@author: mateo.lopez
"""

import sys 
print ("Nom du programme:",sys.argv[0])
print ("Nombre d'arguments:",len(sys.argv)-1)
print ("les arguments sont:")
for arg in sys.argv[1:]:
    print (arg)