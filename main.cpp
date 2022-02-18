#include <iostream>
#include "sculptor.h"
#include "interpretador.h"
#include "putVoxel.h"
#include "putBox.h"
#include "putSphere.h"
#include "putEllipsoid.h"
#include "cutVoxel.h"
#include "cutBox.h"
#include "cutSphere.h"
#include "cutEllipsoid.h"

using namespace std;

int main()
{
    vector<FiguraGeometrica*> figs;
    Interpretador parser;
    Sculptor *escultura;

    figs = parser.parse("C:\\Users\\franc\\Documents\\entrada.txt");

    escultura = new Sculptor(parser.getDimx(), parser.getDimy(), parser.getDimz());

    for(size_t i=0; i<figs.size(); i++){
        cout << "draw\n";
        figs[i]->draw(*escultura); // polimorfisno
    }

    escultura->writeOFF("C:\\Users\\franc\\Documents\\saida.off");

    for(size_t i=0; i<figs.size(); i++){
        delete figs[i];
    }
    delete escultura;
    return 0;
}
