#include"Sommet.h"
#include"Arc.h"
#include"Graphe.h"
#define LARG 110
#define HAUT 80

using namespace std;
Sommet::Sommet()
{
  m_nom_im="";
  m_num_sommet= 0;
  m_deg= 0;
  m_x= 0;
  m_y= 0;
  m_stable= 0;
  m_newstable= 0;
  m_N= 0;
  m_rythme= 0;
  m_N_histo.push_back(m_N);
}
Sommet :: Sommet(string nom_im, int num_sommet, int deg, int x, int y, int k, int n, float r,Graphe*graph)
{
    m_nom_im=nom_im;
    m_num_sommet= num_sommet;
    m_deg= deg;
    m_x= x;
    m_y= y;
    m_stable= k;
    m_newstable= k;
    m_N= n;
    m_rythme= r;
    m_N_histo.push_back(m_N);

    //widgets pour allegro
    //case contenant tous les elements dans l'element global cadre de graphe
    graph->m_cadre.add_child( m_case);

    //case placee en x y de sommet avec taille predefinie
    m_case.set_frame(m_x,m_y,LARG,HAUT+15);
    m_case.set_bg_color(BLANC);//couleur de la case
    m_case.set_moveable();//rendre deplacable

    //ajout bouton dans la case
    m_case.add_child( m_sommet_bt );
    m_sommet_bt.set_bg_color(BLANC);//couleur du bouton
    m_sommet_bt.set_frame(0,15,HAUT,HAUT);//dimensions

    //ajout d'une image dans le bouton
    m_sommet_bt.add_child( m_sommet_im );
    m_sommet_im.set_pic_name(m_nom_im);//nom image

    //ajout slider dans la case
    m_case.add_child( m_slider);
    m_slider.set_range(0,500,true);//valeurs du slider
    m_slider.set_bg_color(SABLECLAIR);//couleur slider
    m_slider.set_frame(HAUT,15,30,65);

    //valeur slider
    m_case.add_child( m_valeur );
    m_valeur.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Down);


    //ajout supprimer dans la case
    m_case.add_child( m_supprimer);
    m_supprimer.set_bg_color(ROUGECLAIR);//couleur slider
    m_supprimer.set_frame(0,0,20,15);

    //ajouter le num du sommet dans la case
    m_case.add_child( m_numero );
    m_numero.set_message(to_string( m_num_sommet));
    m_numero.set_gravity_xy(grman::GravityX::Right,grman::GravityY::Up);

}

Sommet::Sommet(Sommet* copie)
{
    m_nom_im=copie->m_nom_im;
  m_num_sommet= copie->m_num_sommet;
  m_deg= copie->m_deg;
  m_x= copie->m_x;
  m_y= copie->m_y;
  m_stable= copie->m_stable;
  m_N= copie->m_N;
  m_rythme= copie->m_rythme;
  m_N_histo=copie->m_N_histo;
}

Sommet ::~Sommet(){};

void Sommet::reset_N_histo()
{
  m_N_histo.clear();
  m_N_histo.push_back(m_N);
}


void Sommet:: evol_n1_som()
{
    float sommevoisins=0.0;
    float effectif=m_N;

    m_newstable=m_stable-(sommevoisins/m_stable);

    for(unsigned int i=0; i<m_arc_adj.size();i++)
    {
    if(m_arc_adj[i]->m_som_debut==this)
        sommevoisins=sommevoisins+m_stable+(m_arc_adj[i]->m_weight/10)*(m_arc_adj[i]->m_som_fin->m_N*(-1));
    else
        sommevoisins=sommevoisins+m_stable+(m_arc_adj[i]->m_weight/10)*m_arc_adj[i]->m_som_debut->m_N;

    }


    m_N_histo.push_back(m_N);
    m_N= effectif + m_rythme/1000*effectif*(1-(float)effectif/(float)m_stable-(m_newstable/sommevoisins));//



}
