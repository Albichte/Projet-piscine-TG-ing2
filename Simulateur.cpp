#include "Simulateur.h"
#include "Sommet.h"

Simulateur::Simulateur(Sommet* s,int temps)
{
    int m_mx=mouse_x;
    int m_my=mouse_y;
    m_fond.set_frame(0,0,1024,800);
    m_fond.add_child(m_bouton);//cadre graphe simulation
    m_bouton.set_frame(0,0,1024,800);
    m_bouton.set_bg_color(SABLECLAIR);

    m_fond.add_child(m_casx);
    m_casx.set_frame(150,650,200,20);
    m_casx.set_bg_color(BLANC);

    m_casx.add_child(m_x);
    m_x.set_message( std::to_string(m_mx));
    m_x.set_gravity_xy(grman::GravityX::Right,grman::GravityY::Down);

    m_fond.add_child(m_casy);
    m_casy.set_frame(130,450,20,200);
    m_casy.set_bg_color(BLANC);

    m_casy.add_child(m_y);
    m_y.set_vertical();
    m_y.set_message( std::to_string(m_my));
    m_y.set_gravity_xy(grman::GravityX::Left,grman::GravityY::Up);

    m_bouton.add_child(m_cadresimu);
    m_cadresimu.set_frame(150,150,724,500);
    m_cadresimu.set_bg_color(BLANC);

    for(int j=0;j<temps;j++)
    {

        grman::WidgetBox * point = new grman::WidgetBox();
        m_elements.push_back(point);
        m_cadresimu.add_child( *point );
        point->set_frame(j*724/temps,490-s->m_N_histo[j],10,10);
        point->set_bg_color(GRIS);
    }

}

Simulateur::~Simulateur(){}

bool Simulateur::update()
{

    //affichage des coordonnes
    m_mx=mouse_x-150;
    if (m_mx<0)m_mx=0;if (m_mx>500)m_mx=724;
    m_my=(800-mouse_y)-150;
    if (m_my<0)m_my=0;if (m_my>500)m_my=500;
    m_x.set_message( std::to_string(m_mx));
    m_y.set_message( std::to_string(m_my));

    m_fond.update();
    if (m_bouton.clicked()||m_cadresimu.clicked())
        return true;
    else return false;

}
