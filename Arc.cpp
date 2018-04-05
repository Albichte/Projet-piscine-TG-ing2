#include "Arc.h"
#include "Sommet.h"
#include "Graphe.h"

Arc::Arc()
{
    m_som_debut= nullptr;
  m_som_fin= nullptr;
  m_weight=0;
  m_num_arc=0;
}
Arc::Arc(Sommet* s1, Sommet* s2, float weight, int num_arc,Graphe*graph)
{
  m_som_debut= s1;
  m_som_fin= s2;
  m_weight=weight;
  m_num_arc=num_arc;

  //sommets ajdacents

    s1->m_succe.push_back(s2);
    s2->m_prede.push_back(s1);

    //augmentation des degr�s des arcs
    s1->m_deg++;
    s2->m_deg++;
    //liste d'arcs adjacents
    s1->m_arc_adj.push_back(this);
    s2->m_arc_adj.push_back(this);


  //widgets pour allegro
    graph->m_cadre.add_child( m_arc);
    m_arc.attach_from(s1->m_case);
    m_arc.attach_to(s2->m_case);
    m_arc.reset_arrow_with_bullet();

    // Une boite pour englober les widgets de réglage associés
    m_arc.add_child(m_case);
    m_case.set_dim(25,50);
    m_case.set_bg_color(BLANCBLEU);

    // Le slider de réglage de valeur
    m_case.add_child( m_slider);
    m_slider.set_range(-10, 10,true); // Valeurs arbitraires, à adapter...
    m_slider.set_frame(0,10,15,44);
    //m_slider.set_gravity_y(grman::GravityY::Down);

    // Label de visualisation de valeur
    m_case.add_child( m_valeur);
    m_valeur.set_vertical();
    m_valeur.set_gravity_x(grman::GravityX::Right);

    m_case.add_child( m_supprimer);
    m_supprimer.set_frame(0,0,15,10);
    m_supprimer.set_bg_color(ROUGECLAIR);

}

Arc::Arc(Arc* copie)
{
  m_som_debut=copie->m_som_debut;
  m_som_fin=copie->m_som_fin;
  m_weight=copie->m_weight;
  m_num_arc=copie->m_num_arc;
}

Arc::~Arc(){} // demander prof si destruction pointeur
