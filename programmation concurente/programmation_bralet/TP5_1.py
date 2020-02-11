# -*- coding: utf-8 -*-
"""
Created on Fri Jun  8 08:02:47 2018

@author: antoine.bralet
"""

import multiprocessing as mp
# Incrémentation sans protéger la variable partagée
def count1_on_se_marche_sur_les_pieds(nb_iterations):
    """ Chacun écrit àson rythme (non protégée)"""
    global variable_partagee
    for i in range(nb_iterations):
        variable_partagee.value += 1
#−−−−−−−−−−−PARTIE principale (le point d’entrée de cet exemple−−−−−−−
if __name__ == '__main__' :
    nb_iterations = 5000
    # La variable partagée
    variable_partagee = mp.Value('i',0) # ce sera un entier initialisé à0
    print("la valeur de variable_partagee AVANT les incrémentations : ", variable_partagee.value)
    # On crée 2 process
    pid1=mp.Process(target=count1_on_se_marche_sur_les_pieds, args=(nb_iterations,)); pid1.start()
    pid2=mp.Process(target=count1_on_se_marche_sur_les_pieds, args=(nb_iterations,)); pid2.start()
    pid1.join(); pid2.join()
    print("la valeur de variable_partagee APRES les incrémentations %d (attendu %d) " \
       % (variable_partagee.value,nb_iterations*2))
       
def f(x) : x = x + 1
    
import dis # pour voir les détails

dis.dis(f)

