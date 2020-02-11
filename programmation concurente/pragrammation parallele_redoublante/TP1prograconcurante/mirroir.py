# -*- coding: utf-8 -*-
"""
Created on Thu May  4 08:28:54 2017

@author: mateo.lopez
"""

import sys 

res=""
for arg in sys.argv[1:]:
    mot=""
    for l in arg:
        mot= l + mot
    res =res + ' ' + mot     

print (res)