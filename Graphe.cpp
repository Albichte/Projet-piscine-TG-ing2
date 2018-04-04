#include "Graphe.hpp"
#include <iostream>

Graphe::Graphe()
{
  m_odre=0;
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
    //si fichier trouvé
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
    //si fichier trouvé
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
