 
#include <Servo.h>                        // librairie servo
#include <ALLBOT.h>                       // lirairie du robot allbot manuals.velleman.eu

ALLBOT ANIMAT(8);                            // nombre de servomoteur

int Hanche[]={0,1,2,3};   //numéro du servo correspondant 0:avant gauche | 1:avant droit | 2:arrière droit | 3:arrière gauche
int Genou[]={4,5,6,7};    //numéro du servo correspondant 4:avant gauche | 5:avant droit | 6:arrière droit | 7:arrière gauche

// créer des constantes HancheAvantGauche=1,HancheAvantDroite=2,...

int DeplacementRapide = 50;   //100 ms durée d'un mouvement rapide de servo
int DeplacementLent = 200;     //300 ms durée d'un mouvement lent de servo

int GB[]={60,60,60,60};  //angle du genou position basse
int GM[]={90,90,90,90}; //angle du genou position mediane
int GHM[]={100,100,100,100};  //angle du genou position haute moyenne
int GH[]={120,120,120,120}; //angle du genou position haute
int GDD[]={80,100,80,100}; //leve la diagonale droite
int GDG[]={100,80,100,80}; // leve la diagonale gauche

int HMAP[]={45,45,135,135};  //angle médian de la hache en marche avant (pattes perpendiculaires à la marche)
int HD[]={20,20,20,20}; //débattement angulaire de la hanche
int HAV[]={180,180,180,180}; //angle position avant de la hanche
int HAR[]={0,0,0,0}; //angle position arrière de la hanche
int HPL[]={0,0,180,180}; //angle position repliée de la hanche

void setup() 
   { 
    // NAME.attach(numéro, pin, angle initial, inversé (0=non), offset);
    ANIMAT.attach(Hanche[0],   8,  0, 0, 0);
    ANIMAT.attach(Hanche[1],  4,  0, 1, 0);
    ANIMAT.attach(Hanche[2],    2,  180, 1, 0);
    ANIMAT.attach(Hanche[3],     12, 180, 0, 0);
  
    ANIMAT.attach(Genou[0],  9,  90, 0, -10);
    ANIMAT.attach(Genou[1], 7,  90, 1, -17);
    ANIMAT.attach(Genou[2],   3,  90, 0, -8);
    ANIMAT.attach(Genou[3],   13,  90, 1, 5);

    delay(3000);

   }

void loop()
   {
     coucher();
     delay(2000);
     HD[0]=10;
     HD[1]=30;
     HD[2]=30;
     HD[3]=10;
     courir(20);
     HD[0]=20;
     HD[1]=20;
     HD[2]=20;
     HD[3]=20;
     courir(5);
     HD[0]=30;
     HD[1]=10;
     HD[2]=10;
     HD[3]=30;
     courir(20);
     coucher();
     delay(3000);
     HD[0]=20;
     HD[1]=20;
     HD[2]=20;
     HD[3]=20;
     tourner(20);
        
   }
//--------------------------------------------------------------
void coucher()
    {
    for (int i = 0; i < 4; i++)
      {
       ANIMAT.move(Genou[i],GM[i]);//position horizontale
      }
    ANIMAT.animate(DeplacementRapide);
    
    for (int i = 0; i < 4; i++)
      {
       ANIMAT.move(Genou[i],GH[i]); //leve la patte
       ANIMAT.animate(DeplacementRapide);
       ANIMAT.move(Hanche[i],HPL[i]); //hanche position repliée
       ANIMAT.animate(DeplacementRapide);
       ANIMAT.move(Genou[i],GM[i]); //position horizontale
       ANIMAT.animate(DeplacementRapide);
      }

    for (int i = 0; i < 4; i++)
      {
       ANIMAT.move(Genou[i],GH[i]);//leve les pattes
      }
    ANIMAT.animate(DeplacementRapide);
 }
//--------------------------------------------------------------
void courir(int step)
{
 for (int j = 0; j<step;j++)
   {
    for (int i = 0; i < 4; i++)
      {
       ANIMAT.move(Genou[i],GDD[i]);//leve la diagonale droite
      }
    ANIMAT.animate(DeplacementRapide);

    ANIMAT.move(Hanche[0], HMAP[0]-HD[0]); //tourne patte vers l'avant
    ANIMAT.move(Hanche[1], HMAP[1]+HD[1]); //tourne patte vers l'arrière
    ANIMAT.move(Hanche[2], HMAP[2]-HD[2]);
    ANIMAT.move(Hanche[3], HMAP[3]+HD[3]);
    ANIMAT.animate(DeplacementLent);

    for (int i = 0; i <= 4; i++)
      {
       ANIMAT.move(Genou[i],GDG[i]);//leve la diagonale gauche
      }
    ANIMAT.animate(DeplacementRapide);
    ANIMAT.move(Hanche[0], HMAP[0]+HD[0]); //tourne patte vers l'arrière
    ANIMAT.move(Hanche[1], HMAP[1]-HD[1]); //tourne patte vers l'avant
    ANIMAT.move(Hanche[2], HMAP[2]+HD[2]);
    ANIMAT.move(Hanche[3], HMAP[3]-HD[3]);
    ANIMAT.animate(DeplacementLent);
   }
}

//--------------------------------------------------------------
void tourner(int step)
{
 for (int j = 0; j<step;j++)
   {
    for (int i = 0; i < 4; i++)
      {
       ANIMAT.move(Genou[i],GDD[i]);//leve la diagonale droite
      }
    ANIMAT.animate(DeplacementRapide);

    ANIMAT.move(Hanche[0], HMAP[0]+HD[0]); //tourne patte vers l'avant
    ANIMAT.move(Hanche[1], HMAP[1]+HD[1]); //tourne patte vers l'arrière
    ANIMAT.move(Hanche[2], HMAP[2]-HD[2]);
    ANIMAT.move(Hanche[3], HMAP[3]-HD[3]);
    ANIMAT.animate(DeplacementLent);

    for (int i = 0; i < 4; i++)
      {
       ANIMAT.move(Genou[i],GDG[i]);//leve la diagonale gauche
      }
    ANIMAT.animate(DeplacementRapide);
    
    ANIMAT.move(Hanche[0], HMAP[0]-HD[0]); //tourne patte vers l'arrière
    ANIMAT.move(Hanche[1], HMAP[1]-HD[1]); //tourne patte vers l'avant
    ANIMAT.move(Hanche[2], HMAP[2]+HD[2]);
    ANIMAT.move(Hanche[3], HMAP[3]+HD[3]);
    ANIMAT.animate(DeplacementLent);
   }
}
