# -*- coding: utf-8 -*-

"""

Split d’une image (Mono−Process )


"""
from PIL import Image # Importation de la  l i b r a i r i e  d ’ image PIL
from math import  sqrt # Importation de la  fonction  sqrt de la  l i b r a i r i e  math
import multiprocessing as mp
import SharedArray as sa
import time




#Objet permmettant de "spliter une image en .png
#Fonction pricipale:
#                   .Show_Image pour afficher l'image actuel
#                   .Reload_Original pour recharger l'image original
#                   .Split_Image(threshold,multiproc), pour spliter l'image avec le seuil threshold,
#                                                     si multiproc = 0 -> monoprocessing
#                                                     si multiproc = 1 -> multiprocessing (4 proc)


class SplitedImage:

    def __init__(self, ImagePath):
        self.path=ImagePath
        self.image_ = Image.open(ImagePath).convert("RGB")
        self.matrice_pixels = self.image_.load()          

        self.width, self.height = self.image_.size #respectivement, la largeur et la hauteur de l’image
        
        
        #Calcul du nombre de valeur dans la matrice des pixel de l'image et creation d'un shared array de cette taille
        lenght=3*self.width*self.height
        #ici on utilise time.time() pour etre certaint d'avoir un nom unique, ainsi on peut crée 2 objet chargant la meme image        
        self.shared_name="shm://"+self.path+str(time.time())
        self.shared_pixels=sa.create(self.shared_name, lenght, dtype=int)        
        #On copie la matrice des pixels  dans le shared array    
        self.Transfer_To_Shared()
        
        
    def __del__(self):
        #pour ne pas polluer la memoire avec des shared array non utiliser 
        sa.delete(self.shared_name)
        
        
    #Permet de recharge l'image original    
    def Reload_Original(self):
        self.image_ = Image.open(self.path).convert("RGB")
        self.matrice_pixels = self.image_.load()   
        
        self.Transfer_To_Shared()
        
    #Sauvegarde l'image entant que name
    def Save_Image(self, name):
        self.image_.save(name)

        
    #Montre l'image actuel    
    def Show_Image(self):
        self.image_.show()
        
        
    #Copie la liste partager self.shared_pixels dans self.matrice_pixels
    def Transfer_Shared_Pixels(self):
        for y in range(self.height):
            for x in range(self.width):
                n=(y*self.width+x)*3
                self.matrice_pixels[x,y]=self.shared_pixels[n],self.shared_pixels[n+1],self.shared_pixels[n+2]
                
                                 
    #Copie self.matrice_pixels dans la liste partager self.shared_pixels
    def Transfer_To_Shared(self):
        for y in range(self.height):
            for x in range(self.width):
                n=(y*self.width+x)*3
                self.shared_pixels[n],self.shared_pixels[n+1],self.shared_pixels[n+2]=self.matrice_pixels[x,y]
                

    def Get_Pixel(self, x, y):  return  self.matrice_pixels[x, y]
        
        
    #multiproc == 1 => Methode multi-processing
    #multiproc == 0 => Methode mono-processing   
    def Put_Pixel(self, x, y, r, g, b,multiproc): 
        #multiproc=1
        if multiproc==0: #affectation en mono-process
            self.matrice_pixels[x, y] = int(r), int(g), int(b)
            
        if multiproc==1: #affectation en multi-process, on utilise le Shared Array
            n=(self.width*y+x)*3
            
            self.shared_pixels[n]=int(r)
            self.shared_pixels[n+1]=int(g)
            self.shared_pixels[n+2]=int(b)
            
            
    #multiproc == 1 => Methode multi-processing
    #multiproc == 0 => Methode mono-processing   
    def Put_Region(self, x, y, width, height, color,multiproc):
        for i in range(int( x ), int(x+width)):
            for j in range(int(y), int(y+height)):
                self.Put_Pixel(i,j,color[0],color[1],color[2],multiproc)
                
                
    def Average(self,corner_x,  corner_y, region_w, region_h):
        sum_red , sum_green , sum_blue = 0 ,0 ,0#Initialisation  des compteurs
        area = region_w * region_h
        #Calcul de la superficie de la région
        for i in range(int(corner_x), int(corner_x + region_w)):
                for j in range(int(corner_y), int(corner_y + region_h)):
                    r, g, b = self.Get_Pixel(i, j) # Nous lisons  les données r, v, b d’un pixel
                    sum_red += r # somme de chaque composant
                    sum_green += g
                    sum_blue += b
        #Normalisation
        sum_red /= area
        sum_green /= area
        sum_blue /= area
        return (sum_red, sum_green, sum_blue)    #Retour des valeurs r, g, b moyennes
        
    
    def Mesutes_Std_et_Mu(self, corner_x, corner_y, region_w, region_h):
        av_red,  av_blue, av_green = self.Average(corner_x, corner_y, region_w, region_h)
        sum_red2, sum_green2, sum_blue2 = 0.0, 0.0, 0.0
        
        for i in range(int(corner_x), int(corner_x + region_w)):
            for j in range(int(corner_y), int(corner_y + region_h)) :
                red, green, blue = self.Get_Pixel(i, j)
                sum_red2 += (red**2)
                sum_green2 += (green**2)
                sum_blue2 += (blue**2)

        area=region_w*region_h*1.0
        r , g , b = 0 ,0 ,0
        
        r = sqrt(abs(sum_red2 / area-av_red**2))
        g = sqrt(abs(sum_green2 / area-av_green**2))
        b = sqrt(abs(sum_blue2 / area-av_blue**2))

        return ((av_red, av_blue, av_green), (r+b+g) / 3.0)
    
        
    #multiproc == 1 => Methode multi-processing
    #multiproc == 0 => Methode mono-processing    
    def Decouper_en4(self, x, y, width, height, threshold, multiproc):
        if  height * width < 4 :   return    # rien à découper
        
        #Cas de région uniforme : une couleur uniforme est affect ée à la partition
        color, rm = self.Mesutes_Std_et_Mu(x, y, width, height)
        if rm < threshold :  # Affectation de la  couleur moyenne à la partition
            self.Put_Region(x, y, width, height, color,multiproc)
        else : #Dans le cas contraire, la partition non−uniforme est coupée en 4 (récursivement)
            self.Decouper_en4(x, y, width/2 , height/2, threshold, multiproc)
            self.Decouper_en4(x + width/2, y, width/2, height/2, threshold, multiproc)
            self.Decouper_en4(x, y + height/2, width/2, height/2, threshold, multiproc)
            self.Decouper_en4(x+width/2 , y+height/2, width/2, height/2, threshold, multiproc)
        
        
    #multiproc == 1 => Methode multi-processing
    #multiproc == 0 => Methode mono-processing
    def Split_Image(self,threshold,multiproc):  
        x,y,width,height=0,0,self.width,self.height
        
        
        # en momo-processing
        if multiproc==0: 
            
            self.Decouper_en4(0, 0,width,height, threshold,0) 
            
        # en multi-processing les resultats sont placer dans la memoire partagée self.shared_pixels
        if multiproc ==1:
            
            
            if  height * width < 4 :   return    # rien à découper
    
            #Cas de région uniforme : une couleur uniforme est affectée à la partition
            color, rm = self.Mesutes_Std_et_Mu(x, y, width, height)
            if rm < threshold :  # Affectation de la  couleur moyenne à la partition
                self.Put_Region(x, y, width, height, color,0)          
                
            else:                #Création de 3 processus qui s'occuperons de traiter chacun un quart du cercle  
                process = [] 
                process.append(mp.Process(target=self.Decouper_en4, args=(x + width/2, y, width/2, height/2, threshold, 1)))
                process.append(mp.Process(target=self.Decouper_en4, args=(x, y + height/2, width/2, height/2, threshold, 1)))
                process.append(mp.Process(target=self.Decouper_en4, args=(x+width/2 , y+height/2, width/2, height/2, threshold, 1)))
                
                for p in process:
                    p.start()
                
                self.Decouper_en4(x, y, width/2 , height/2, threshold, 1)
                
                
                for p in process:
                    p.join()
                
                # on transfert la matrice self.shared_pixels a la matrice des pixels de l'imag pour actualiser l'image
                self.Transfer_Shared_Pixels()
            
            
            
         
                    
#−−−−−−−−−−−−−−−−−−−−Principale−−−−−−−−−−−−−−−−−−−−
nom_fic_in="steve.png"

steve=SplitedImage(nom_fic_in)

steve.Show_Image()

threshold=60


print("Démarrage du traitement de l'image en multi-processing de",nom_fic_in)

t0=time.time()
steve.Split_Image(threshold,1)
t1=time.time()

print("fin du traitement")
print("Temps mis en multi-processing:",round(t1-t0,3),"s.")

steve.Show_Image()

mono_fic_out=" out_multi_proc_ "+nom_fic_in    #On construit  le nom de l ’ image sauvegardée
steve.Save_Image(mono_fic_out)

steve.Reload_Original()

print("Démarrage du traitement de l'image en mono-processing de",nom_fic_in)

t0=time.time()
steve.Split_Image(threshold,0)
t1=time.time()

print("fin du traitement")
print("Temps mis en mono-processing:",round(t1-t0,3),"s.")

steve.Show_Image()


mono_fic_out=" out_mono_proc_ "+nom_fic_in    #On construit  le nom de l ’ image sauvegardée
steve.Save_Image(mono_fic_out)

#SplitedImage(nom_fic_out).ShowImage()