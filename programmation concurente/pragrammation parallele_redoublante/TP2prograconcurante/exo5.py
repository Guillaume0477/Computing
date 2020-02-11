# -*- coding: utf-8 -*-
"""
Created on Fri May 12 08:37:44 2017

@author: mateo.lopez
"""

import sys,os,time
arg= sys.argv[1:]
for i in arg :    
    pid = os.fork()
    if pid == 0 :
        try:        
            os.execlp('gcc','gcc','-c',i)
        except:
            sys.exit(1)
    
for i in arg :  
    
    if exitcode[1]>0:
        print("problem during compilation")
        sys.exit(1)

arg=sys.argv
for i in range(len(arg)) :
    arg[i]=arg[i].replace(".c",".o")
    
arg[0]='gcc'

arg.append('-o')
arg.append('denis')

os.execvp('gcc',arg)