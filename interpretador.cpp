#include "interpretador.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "putVoxel.h"
#include "putBox.h"
#include "putSphere.h"
#include "putEllipsoid.h"
#include "cutVoxel.h"
#include "cutBox.h"
#include "cutSphere.h"
#include "cutEllipsoid.h"

using namespace std;

Interpretador::Interpretador()
{
}

vector<FiguraGeometrica *> Interpretador::parse(string filename){

    vector<FiguraGeometrica*> figs;
    stringstream ss;
    string nome, linha;
    ifstream arquivo;

    arquivo.open(filename.c_str());

    if(!arquivo.is_open()){
        cout<< "Erro na abertura do arquivo" << filename << endl;
        exit(0);
    }

  while(arquivo.good()){
        getline(arquivo, linha);
        if(arquivo.good()){
            //lan�aa string s no fluxo ss
            ss.clear();
            ss.str(linha);
            ss >> nome;
            if(ss.good()){
                //dimensoes
                if(nome.compare("dim") == 0) {
                    ss >> dimx >> dimy >> dimz;
                }
                else if(nome.compare("putVoxel") == 0){
                    int x, y, z;
                    ss >> x >> y >> z >> r >> g >> b >> a;
                    figs.push_back(new PutVoxel(x, y ,z, r, g, b, a));
                }
                else if(nome.compare("cutVoxel") == 0){
                    int x, y, z;
                    ss >> x >> y >> z; // lendo os elementos da linha
                    figs.push_back(new CutVoxel(x, y ,z));
                }
                else if(nome.compare("putBox") == 0){
                    int x0, x1, y0, y1, z0, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                    figs.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
                }
                 else if(nome.compare("cutBox") == 0){
                    int x0, x1, y0, y1, z0, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0;
                    figs.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
                }
                 else if(nome.compare("putSphere") == 0){
                    int xc, yc, zc, radius;
                    ss >> xc >> yc >> zc >> radius >> r >> g >> b >> a;
                    figs.push_back(new PutSphere(xc, yc, zc, radius, r, g, b, a)); // fun��o para inserir elementos no vetor
                }
                  else if(nome.compare("cutSphere") == 0){
                    int xc, yc, zc, radius;
                    ss >> xc >> yc >> zc >> radius;
                    figs.push_back(new CutSphere(xc, yc, zc, radius));
                }
                else if(nome.compare("putEllipsoid") == 0){
                    int xc, yc, zc, rx, ry, rz;
                    ss >> xc >> yc >> zc >> rx >> ry >> rz >> r >> g >> b >> a;
                    figs.push_back(new PutEllipsoid(xc, yc, zc, rx, ry, rz, r, g, b, a));
                }
                 else if(nome.compare("cutEllipsoid") == 0){
                    int xc, yc, zc, rx, ry, rz;
                    ss >> xc >> yc >> zc >> rx >> ry >> rz;
                    figs.push_back(new CutEllipsoid(xc, yc, zc, rx, ry, rz));
                }
            }
        }
     }
    return(figs);
 }

 int Interpretador::getDimx(){
    return dimx;
 }
 int Interpretador::getDimy(){
    return dimy;
 }
 int Interpretador::getDimz(){
    return dimz;
 }

