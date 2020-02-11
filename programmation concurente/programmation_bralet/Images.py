# -*- coding: utf-8 -*-
"""
Created on Fri Jun 15 08:01:48 2018

@author: antoine.bralet
"""

from PIL import Image # Importation de la librairie d’image PIL
from math import sqrt # Importation de la fonction sqrt de la librairie math
import multiprocessing as mp
import time

image_ = None
# sera chargée dans la partie Mian (ici,  on la ’pré−déclare’)
width, height = None,  None # respectivement,  la largeur et la hauteur de l’image

def GetPixel(x, y):  return matrice_pixels[x, y]
    
def PutPixel(x, y, r, g, b): matrice_pixels[x, y]= int(r),  int(g),  int(b) # Il faut des ints !

def PutRegion(x, y, width, height, triplet_color):
    for i in range(x,   x+width):
        for j in range(y,  y+height):
            PutPixel(i, j, triplet_color[0], triplet_color[1], triplet_color[2])

def Average(corner_x,  corner_y, region_w, region_h):
    sum_red,  sum_green,  sum_blue = 0, 0, 0    #Initialisation des compteurs
    area = region_w*region_h
    #Calcul de la superficie de la région
    for i in range(corner_x,  corner_x+region_w):
        for j in range(corner_y,  corner_y+region_h):
            r, g, b=GetPixel(i, j)# Nous lisons les données r, v, b d’un pixel
            sum_red += r
            # somme de chaque composant
            sum_green += g
            sum_blue += b
    #Normalisation
    sum_red/=area
    sum_green/=area
    sum_blue/=area
    return(sum_red,  sum_green, sum_blue)   #Retour des valeurs r, g, b moyennes

def Mesures_Std_et_Mu(corner_x,  corner_y,  region_w,  region_h):
    av_red,  av_blue,  av_green = Average(corner_x, corner_y, region_w, region_h)
    sum_red2, sum_green2, sum_blue2 = 0.0,  0.0,  0.0
    for i in range(corner_x,  corner_x+region_w):
        for j in range(corner_y,  corner_y+region_h):
            red, green, blue = GetPixel(i, j)
            sum_red2  += (red**2)
            sum_green2 += (green**2)
            sum_blue2 += (blue**2)
            area=region_w*region_h*1.0
            r, g, b=0, 0, 0
            r = sqrt(abs(sum_red2 / area - av_red**2))
            g= sqrt(abs(sum_green2 / area - av_green**2))
            b = sqrt(abs(sum_blue2 / area - av_blue**2))
    return ((av_red,  av_blue,  av_green),  (r+b+g)/3.0)

def Decouper_en4(x, y, width, height, threshold_alpha):
    if height*width < 4 :  return   # rien à découper
#Cas de région uniforme : une couleur uniforme est affectée à la partition
    color, rm = Mesures_Std_et_Mu(x,  y,  width,  height)
    if rm < threshold_alpha:  #Affectation de la couleur moyenne à la partition
        PutRegion(x, y, width, height, color)
    else: #Dans le cas contraire,  la partition non−uniforme est coupée en 4 (récursivement)
        Decouper_en4(x, y, width//2, height//2, threshold_alpha)
        Decouper_en4(x + width//2,  y,  width//2,  height//2, threshold_alpha)
        Decouper_en4(x,  y + height//2,  width//2,  height//2, threshold_alpha)
        Decouper_en4(x+width//2,  y+height//2,  width//2, height//2, threshold_alpha)

def Decouper_en4_mul(x, y, width, height, threshold_alpha):
    global liste_process
    if height*width < 4 :  return   # rien à découper
#Cas de région uniforme : une couleur uniforme est affectée à la partition
    color, rm = Mesures_Std_et_Mu(x,  y,  width,  height)
    if rm < threshold_alpha:  #Affectation de la couleur moyenne à la partition
        PutRegion(x, y, width, height, color)
    else: #Dans le cas contraire,  la partition non−uniforme est coupée en 4 (récursivement)        
        liste_process.append(mp.Process(target = Decouper_en4_mul, args= (x, y, width//2, height//2, threshold_alpha,)))
        liste_process[-1].start()       
        liste_process.append(mp.Process(target =Decouper_en4_mul, args = (x + width//2,  y,  width//2,  height//2, threshold_alpha,)))
        liste_process[-1].start()        
        liste_process.append(mp.Process(target = Decouper_en4_mul, args = (x,  y + height//2,  width//2,  height//2, threshold_alpha,)))
        liste_process[-1].start()        
        Decouper_en4_mul(x+width//2,  y+height//2,  width//2, height//2, threshold_alpha)


#−−−−−−−−−−−−−−−−−−−−Principale−−−−−−−−−−−−−−−−−−−−−−−−−−
if __name__ == '__main__':
    global liste_process
    
    liste_process = []
    # nom_fic_in="Image8.bmp"    
    nom_fic_in="steve.png"
    image_ = Image.open(nom_fic_in).convert("RGB") # conversion nécessaire pour une image "png"
    matrice_pixels = image_.load()    # Importation des pixels de l’image
    width, height=image_.size
    image_.show()   # Montrez l’image originale
    td = time.time()
    Decouper_en4(0, 0, width, height, 60) # tester avec les seuils différents 3,  10,  15,  20,  ...
    tf = time.time()    
    image_.show()
    print("En Monoprocessus, l'image a ete traitee en ", tf-td," secondes")
    nom_fic_out="out_"+nom_fic_in   # On construit le nom de l’image sauvegardée
    image_.save(nom_fic_out)
    
    
    Verroumat = mp.Lock()
    nom_fic_in="steve.png"
    image_ = Image.open(nom_fic_in).convert("RGB") # conversion nécessaire pour une image "png"
    matrice_pixels = image_.load()    # Importation des pixels de l’image
    width, height=image_.size
    image_.show()   # Montrez l’image originale
    td1 = time.time()
    Decouper_en4_mul(0, 0, width, height, 60) # tester avec les seuils différents 3,  10,  15,  20,  ...
    tf1 = time.time()    
    image_.show()
    print("En Pluriprocessus, l'image a ete traitee en ", tf1-td1," secondes")
    
    
   
    
    
    