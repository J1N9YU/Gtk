#include "GtkSDtFactory.hh"


GtkSDtFactory::GtkSDtFactory(){

}

GtkSDtFactory::~GtkSDtFactory(){

}

void GtkSDtFactory::AddSDt(){

}

void GtkSDtFactory::BuildG4SD(){

    G4SDManager* SDman = G4SDManager::GetSDMpointer();

    auto iter = theSDt.begin();
    for( ;iter!=theSDt.end();iter++){
        
        string nameOfSD = iter->GetNameOfSD();
        string nameOfLv = iter->GetNameOfLogicVol();
        string type = iter->GetTypeOfSD();









    }


}