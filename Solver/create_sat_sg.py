import numpy as np
import datetime

class create_sat:
    def __init__(self):
        print(" ")

    def create(self,semaine,nb_groupe,taille_groupe,name="null"):
        #semaine = 2
        self.semaine = semaine
        #nb_groupe = 3
        self.nb_groupe = nb_groupe
        #taille_groupe = 2
        self.taille_group = taille_groupe

        self.clause = 0
        self.variable = 0
        nb_joueur = self.taille_group * nb_groupe

        self.nb_joueur = nb_joueur

        p = nb_joueur*nb_groupe
        self.p = p
        self.affich = ""

        for i in range(0,semaine):

            c = ""
            for g in range(1,nb_joueur*nb_groupe+1):
                self.variable +=1
                passage = g+p*i
                c+=str(passage)+" "
                if g % nb_groupe == 0:
                    self.clause +=1
                    c += "0\n"
            #print(c)
            self.affich+=c
            tab = np.zeros((nb_groupe,nb_joueur+1))
            c = 0
            for g in range(1,nb_groupe*nb_joueur+1):
                if(g % nb_groupe == 1 and g !=1):
                    c += 1
                k = g % nb_groupe
                tab[k,c] = g+p*i
            #print(tab)
            for ip in tab:
                for jp in ip:
                    self.affich+=str(jp.astype(int))+" "
                self.affich+="\n"
                self.clause += 1
            #print(self.affich)

            c = 0
            for g in range(1,nb_joueur+1):
                for g0 in range(nb_groupe):
                    for g1 in range(nb_groupe):
                        if (g0<g1):
                            self.clause += 1
                            self.affich+="-"+str(g0+nb_groupe*c+1+p*i)+" -"+str(g1+nb_groupe*c+1+p*i)+" 0\n"
                            #print(g0+nb_groupe*c+1+p*i,g1+nb_groupe*c+1+p*i)
                c += 1

            #print(self.affich)
        tab =[]
        """
        print("etape 0")
        print(self.nb_groupe)
        for g in range(1,nb_groupe+1):
            self.recur_create(self.nb_groupe,np.append(tab,g),2)
        """

        #print("etape 1")
        self.matrice_controle = np.zeros(nb_joueur)
        for h in range(nb_joueur):
            self.matrice_controle[h] = 1+nb_groupe*h

        #print(self.matrice_controle)
        #print("etape 0")
        for j in range(len(self.matrice_controle)):
            self.recur_once(taille_groupe-1,np.append(tab,self.matrice_controle[j]),j)
        #print(self.clause)
        #print("etape 2")
        tab=[]
        for j in range(len(self.matrice_controle)):
            self.recur_tite(taille_groupe-1,np.append(tab,self.matrice_controle[j]),j)

        entete = "p cnf "+str(self.variable)+" "+str(self.clause)+"\n"
        self.affich = entete + self.affich
        #print(self.affich)
        date = datetime.datetime.now().strftime("(%m_%d_%Y,%H:%M:%S)")
        if name == "null":
            name = "golf_s" + str(semaine) + "_g" + str(self.nb_groupe) +"_"+date+"v"+ ".cnf"
        f = open(name, "w")
        f.write(self.affich)
        f.close()
        print("Finis")

        #print("nb clause = ",self.clause," nb variable = ",self.variable)

    def recur_once(self,taille_groupe,tab,k):
        if taille_groupe!=0:
            for i in range(k+1,len(self.matrice_controle)):
                self.recur_once(taille_groupe-1,np.append(tab,self.matrice_controle[i]),i)
        else:
            for sp in range(self.semaine-1):
                for m in range(self.nb_groupe):
                    for i in range(len(tab)):
                        for j in range(i+1,len(tab)):
                            for s in range(sp+1,self.semaine):

                                tob = tab+(m)+sp*self.nb_joueur*self.nb_groupe
                                #print(tob)
                                for gi in range(-m,self.nb_groupe-m):
                                    self.clause += 1
                                    toub = np.append(tob,m+tab[i]+self.nb_groupe*self.nb_joueur*s+gi)
                                    toub = np.append(toub,m+tab[j]+self.nb_groupe*self.nb_joueur*s+gi).astype(int)
                                    #print(toub,m)
                                    c = ""
                                    for y in toub:
                                        c += "-" + str(y) + " "
                                    c += "0\n"
                                    self.affich += c
                            #print(tab+m,m+tab[j]+self.nb_groupe*self.nb_joueur*s,m+tab[i]+self.nb_groupe*self.nb_joueur*s)
                       # print(c)
                            #self.affich += "-" + str(ip.astype(int)) + " "
                        #self.affich+="0\n"
                        #print(np.append(tab,self.matrice_controle[i])+g+s*self.nb_groupe*self.nb_joueur)
            #for i in range (k ,self.)


    def recur_tite(self,taille_groupe,tab,k):
        if taille_groupe!=0:
            for i in range(k+1,len(self.matrice_controle)):
                self.recur_tite(taille_groupe-1,np.append(tab,self.matrice_controle[i]),i)
        else:
            for i in range(k+1,len(self.matrice_controle)):
                for s in range(0,self.semaine):
                    for g in range(self.nb_groupe):
                        self.clause+=1
                        tob = np.append(tab,self.matrice_controle[i])+g+s*self.nb_groupe*self.nb_joueur
                        for ip in tob:
                            self.affich += "-" + str(ip.astype(int)) + " "
                        self.affich+="0\n"
                        #print(np.append(tab,self.matrice_controle[i])+g+s*self.nb_groupe*self.nb_joueur)
            #for i in range (k ,self.)


    def recur_create(self,variation,tab,profondeur):
        if(profondeur < self.nb_joueur):
            for i in range(variation+1,variation+self.nb_groupe+1):
                self.recur_create(variation+self.nb_groupe,np.append(tab,i),profondeur+1)
                #print("prof= ", profondeur, " tab = ", tab)
        else :
            for i in range(variation+1, variation + self.nb_groupe + 1):
                tob = np.append(tab, i)
                #print("prof= ", profondeur, " tab = ", tob)

                for h in range(1,self.semaine):
                    tib = tob + (h * self.nb_joueur * self.nb_groupe)
                    tob = np.append(tob,tib)
                for ip in tob:
                    self.affich+="-"+str(ip.astype(int))+" "
                self.affich+="0\n"
                self.clause += 1
                #print(self.clause)
                #print(tob)



#h = create_sat()
#h.create(2,3,2,"test.cnf")
#h.create(2,4,2,"mouais.cnf")