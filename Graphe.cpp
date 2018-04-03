#include "Graphe.hpp"
#include <iostream>

Graphe::Graphe()
{
  m_odre=0;
  m_nom="";
}

void Graphe:: reset_marquages_som()
{
  for(int i=0;i<m_sommets.size();i++)
  {
    m_sommets[i].m_marque=false;
  }
}

void Graphe:: reset_actif_som()
{
  for(int i=0;i<m_sommets.size();i++)
  {
    m_sommets[i].m_actif=true;
  }
}

void Graphe:: reset_marquages_arc()
{
  for(int i=0;i<m_arcs.size();i++)
  {
    m_arcs[i].m_marque=false;
  }
}

void Graphe:: reset_actif_arc()
{
  for(int i=0;i<m_arcs.size();i++)
  {
    m_arcs[i].m_marque=true;
  }
}
