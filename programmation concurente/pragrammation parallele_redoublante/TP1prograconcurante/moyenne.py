# -*- coding: utf-8 -*-
"""
Created on Thu May  4 08:50:13 2017

@author: mateo.lopez
"""
import sys
moyenne =0
for arg in sys.argv[1:]:    
    i=1
    try:
        arg = int(arg)
        if arg<0 or arg>20:
            print ("Note non valide")
            i=0
        else:
            moyenne = moyenne + int(arg)
            
    except:
        print ("Entrer des réels compris entre 0 et 20")

moyenne = moyenne/(len(sys.argv)-1)
if i==1:
    print ("Moyenne est : ", round(moyenne,2))