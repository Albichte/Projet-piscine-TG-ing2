#include "Graphe.h"
#include "Sommet.h"
#include "Arc.h"
#include <iostream>
#include <fstream>

Graphe::Graphe()
{
  m_ordre=0;
  m_nom="";
}

Graphe::Graphe(string nom_fich)
{
    //variables temporaires pour les constructeurs
    //ligne sert aux conversions
    string titre,ligne,nimage;
    int ordre,nbarcs,num,degre,x,y,k,n,s1,s2;
    float poids,r;

    //ouverture du fichier en mode lecture
    ifstream fichier (nom_fich,ios::in);
    //si fichier trouvï¿½
    if(fichier)
    {
        //lecture des informations en tete de fichier
        getline (fichier,titre);
        m_nom=titre;
        //conversions
        getline (fichier,ligne);
        ordre=atoi(ligne.c_str());
        getline (fichier,ligne);
        nbarcs=atoi(ligne.c_str());
        m_ordre=ordre;
        //boucle qui parcourt les sommets
        for(int i=0;i<ordre;i++)
        {
            //et qui lit les information ligne par ligne
            //en effectuant ensuite la conversion necessaire
            getline (fichier,nimage);
            getline (fichier,ligne);
            num=atoi(ligne.c_str());
            getline (fichier,ligne);
            degre=atoi(ligne.c_str());
            getline (fichier,ligne);
            x=atoi(ligne.c_str());
            getline (fichier,ligne);
            y=atoi(ligne.c_str());
            getline (fichier,ligne);
            k=atoi(ligne.c_str());
            getline (fichier,ligne);
            n=atoi(ligne.c_str());
            getline (fichier,ligne);
            r=atof(ligne.c_str());
            m_sommets.push_back(Sommet(nimage,num,degre,x,y,k,n,r));
        }
        //boucle qui parcourt les sommets
        for(int i=0;i<nbarcs;i++)
        {
            //et qui lit les information ligne par ligne
            //en effectuant ensuite la conversion necessaire
            getline (fichier,ligne);
            s1=atoi(ligne.c_str());
            getline (fichier,ligne);
            s2=atoi(ligne.c_str());
            getline (fichier,ligne);
            poids=atof(ligne.c_str());
            m_arcs.push_back(Arc(m_sommets[s1],m_sommets[s2],poids,i));

        }
    }
    else cerr<<"Probleme de fichier"<<endl;
    fichier.close();

    //widgets pour allegro
    m_cadre.set_frame(0, 0, 1024, 800);//dimensions du cadre
    m_cadre.set_bg_color(VERT);//couleur du cadre

    m_cadre.add_child( m_barreoutil );//bloc barre outils
    m_barreoutil.set_frame(10, 10, 1004, 50);//dimensions barre outil
    m_barreoutil.set_bg_color(ROUGE);//couleur barre outil

    m_barreoutil.add_child( m_menu );//case menu
    m_menu.set_bg_color(BLEU);//couleur menum_menu.set_frame(15, 15, 85, 45);//dimensions
    m_menu.set_frame(15, 5, 180, 40);//dimensions
    //m_img.set_pic_name("tree0.bmp"); pour chaque image

    m_barreoutil.add_child( m_sauvegarder );//case sauvegarder
    m_sauvegarder.set_bg_color(CYAN);//couleur sauvegarder
    m_sauvegarder.set_frame(210, 5, 180, 40);//dimensions

    m_barreoutil.add_child( m_connexite );//case connexite
    m_connexite.set_bg_color(ORANGE);//couleur connexite
    m_connexite.set_frame(405, 5, 180, 40);//dimensions

    m_barreoutil.add_child( m_kconnexite );//case kconnexite
    m_kconnexite.set_bg_color(JAUNE);//couleur kconnexite
    m_kconnexite.set_frame(600, 5, 180, 40);//dimensions

    m_barreoutil.add_child( m_simulation );//case simulation
    m_simulation.set_bg_color(VIOLET);//couleur simulation
    m_simulation.set_frame(795, 5, 180, 40);//dimensions

    //if ( m_bouton1.clicked() )//pour l'activation des boutons
}

void Graphe:: reset_marquages_som()
{
  for(unsigned int i=0;i<m_sommets.size();i++)
  {
    m_sommets[i].m_marque=false;
  }
}

void Graphe:: reset_actif_som()
{
  for(unsigned int i=0;i<m_sommets.size();i++)
  {
    m_sommets[i].m_actif=true;
  }
}

void Graphe:: reset_marquages_arc()
{
  for(unsigned int i=0;i<m_arcs.size();i++)
  {
    m_arcs[i].m_marque=false;
  }
}

void Graphe:: reset_actif_arc()
{
  for(unsigned int i=0;i<m_arcs.size();i++)
  {
    m_arcs[i].m_marque=true;
  }
}

void Graphe::sauvegarde(string nom_fich)
{
    //ouverture du fichier en mode ecriture en effacant le contenu
    ofstream fichier("deux.txt",ios::out|ios::trunc);
    //si fichier trouvï¿½
    if(fichier)
    {
        //ecriture des informations en tete de fichier
        //nom du graphe ordre et nombre d'arcs
        fichier<<m_nom<<endl;
        fichier<<m_ordre<<endl;
        fichier<<m_arcs.size()<<endl;

        //boucle qui parcourt les sommets
        for (int i=0 ; i<m_ordre;i++)
        {
            //et qui ecrit chaque information ligne par ligne
            fichier<<m_sommets[i].m_nom_im<<endl;
            fichier<<m_sommets[i].m_num_sommet<<endl;
            fichier<<m_sommets[i].m_deg<<endl;
            fichier<<m_sommets[i].m_x<<endl;
            fichier<<m_sommets[i].m_y<<endl;
            fichier<<m_sommets[i].m_stable<<endl;
            fichier<<m_sommets[i].m_N<<endl;
            fichier<<m_sommets[i].m_rythme<<endl;
        }
        //boucle qui parcourt les arcs
        for (unsigned int i=0 ; i<m_arcs.size();i++)
        {
            //et qui ecrit chaque information ligne par ligne
            fichier<<m_arcs[i].m_som_debut->m_num_sommet<<endl;
            fichier<<m_arcs[i].m_som_fin->m_num_sommet<<endl;
            fichier<<m_arcs[i].m_weight<<endl;

        }
    }
    //en cas d'erreur
    else cerr<<"Probleme fichier"<<endl;
    //fermeture du fichier
    fichier.close();
}


//Fonctions d'ajout et suppression de sommet et arcs
void Graphe:: ajout_som(string m_nom_im, int m_num_sommet, int x, int y, int k, int n, float r)
{
    m_sommets.push_back( *new Sommet(m_nom_im, m_num_sommet,0, x, y, k, n, r));
    this->m_ordre++;
}

void Graphe:: supr_som(Sommet& s)
{
  m_ordre--;
  vector<Sommet>::iterator it_som;
  it_som=m_sommets.begin();
  while(&(*it_som)!=&s)
  {
    it_som++;
  }

<<<<<<< HEAD
  //appel surp ar pour les arï¿½tes adjacentes avec un for
=======
  //appel surp ar pour les arètes adjacentes avec un for
>>>>>>> 327114f0d83d20a6b3516e3c6a4b408a1729a9d3
  m_sommets.erase(it_som,it_som);
}

void Graphe:: ajout_arc(Sommet& s1, Sommet& s2, float weight, int num_arc)
{
  m_arcs.push_back(*new Arc(s1, s2,  weight, num_arc));
  s1.m_succe.push_back(&s2);
  s2.m_prede.push_back(&s1);
  s1.m_deg++;
  s2.m_deg++;
  s1.m_arc_adj.push_back(&m_arcs[m_arcs.size()-1]);
  s2.m_arc_adj.push_back(&m_arcs[m_arcs.size()-1]);
}
<<<<<<< HEAD
/*
=======

/*

>>>>>>> 327114f0d83d20a6b3516e3c6a4b408a1729a9d3
void Graphe:: supr_arc(Arc&a)
{
  a.m_som_debut->m_deg--;
  a.m_som_fin->m_deg--;
  vector<Arc*>::iterator it_arc;
  vector<Sommet*>:: iterator it_som;


<<<<<<< HEAD
  // On efface le pointeur dans les diffï¿½rents sommets
=======
  // On efface le pointeur dans les différents sommets
>>>>>>> 327114f0d83d20a6b3516e3c6a4b408a1729a9d3
  *it_som= a.m_som_debut->m_succe[0];
  while(*it_som!=a.m_som_fin and *it_som!=a.m_som_debut->m_succe[a.m_som_debut->m_succe.size()-1])
  {
    it_som++;
  }
  a.m_som_debut->m_succe.erase(it_som);

  *it_som=a.m_som_fin->m_prede[0];
  while(*it_som!=a.m_som_debut and *it_som!=a.m_som_fin->m_prede[a.m_som_fin->m_prede.size()-1])
  {
    it_som++;
  }
  a.m_som_fin->m_prede.erase(it_som,it_som);

<<<<<<< HEAD
  //on efface le pointeur dans les vecteurs d'arï¿½tes adjacentes
=======
  //on efface le pointeur dans les vecteurs d'arètes adjacentes
>>>>>>> 327114f0d83d20a6b3516e3c6a4b408a1729a9d3
  //s1
  *it_arc=a.m_som_debut->m_arc_adj[0];
  while (*it_arc!=&a and *it_arc!=a.m_som_debut->m_arc_adj[a.m_som_debut->m_arc_adj.size()-1])
  {
    it_arc++;
  }
  a.m_som_debut->m_arc_adj.erase(it_arc,it_arc);

  //s2
  *it_arc=a.m_som_fin->m_arc_adj[0];
  while (*it_arc!=&a and *it_arc!=a.m_som_fin->m_arc_adj[a.m_som_fin->m_arc_adj.size()-1])
  {
    it_arc++;
  }
  a.m_som_fin->m_arc_adj.erase(it_arc,it_arc);

  // on efface ensuite dans le m_arcs du graphe
  *it_som=a.m_s[0];
  while(*it_som!=&s)
  {
    it_som++;
  }
  a.m_sommets.erase(it_som,it_som);


}*/

//actualiser tous les widgets
void Graphe::update()
{
    m_cadre.update();
}
<<<<<<< HEAD
=======

>>>>>>> 327114f0d83d20a6b3516e3c6a4b408a1729a9d3
