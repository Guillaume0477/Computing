# -*- coding: utf-8 -*-
"""
Created on Mon May 15 14:47:02 2017

@author: mateo.lopez
"""

import os,sys,time


pr1,pw1=os.pipe()
pid=os.fork()


if pid == 0:
    fichier= os.open("exo1.py" ,os.O_RDONLY)
    os.dup2(fichier,0)
    #os.close(pr1)
    os.dup2(pw1,1)
    #os.close(pw1)
    os.execlp("sort","sort")

else:
    #os.wait()
    os.close(pw1)
    
    pr2,pw2=os.pipe()
    
    pid = os.fork()
    if pid == 0:
        os.dup2(pr1,0)
        os.close(pr2)
        os.dup2(pw2,1)
        os.close(pw2)
        os.execlp("grep","grep","utf")
    else:
        os.close(pw2)
    
        new= os.open("ehhh.txt"  , os.O_WRONLY | os.O_CREAT )
    
        pid = os.fork()
        
        os.dup2(pr2,0)
        
        os.dup2(new,1)
        
        os.execlp("tail","tail","-n","5")
        

            
        