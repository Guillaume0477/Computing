# -*- coding: utf-8 -*-
"""
Created on Fri Jun  8 08:37:18 2018

@author: antoine.bralet
"""

import multiprocessing as mp
variable_partagee = mp.Value("i", 0) # ce sera un entier initialisé à0
verrou = mp.Semaphore() # Val init=1

def count2_SC_sem(nb_iterations):
    """ Chacun écrit àson rythme (non protégée)"""
    global variable_partagee
    for i in range(nb_iterations):
        verrou.acquire()
        variable_partagee.value += 1
        verrou.release()
def test_SC_protege_par_Sem():
    # if __name__ == ’__main__’ :
    nb_iterations = 5000
    # La variable partagée : placée hors cette fonction (sinon, la passr en param)
    # variable_partagee = mp.Value(’i’,0) # ce sera un entier initialisé à0
    print("la valeur de variable_partagee AVANT les incrémentations : ",
    variable_partagee.value)
    # On crée 2 process
    pid1 = mp.Process(target=count2_SC_sem, args=(nb_iterations,))
    pid1.start()
    pid2 = mp.Process(target=count2_SC_sem, args=(nb_iterations,))
    pid2.start()
    pid1.join()
    pid2.join()
    print("la valeur de variable_partagee APRES les incrémentations %d (attendu %d) " % (
    variable_partagee.value, nb_iterations*2))
test_SC_protege_par_Sem()