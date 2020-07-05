#include "GtkSDManager.hh"

GtkSDManager::GtkSDManager(){
    if(instance == NULL){
        instance = new GtkSDManager;
    }    

}

GtkSDManager::~GtkSDManager(){

}

GtkSDManager* GtkSDManager::GetInstance(){
    if(instance == NULL){
        instance = new GtkSDManager;
    }   
    return instance;
}

void GtkSDManager::AssociateSDtoLogicVolume(G4VSensitiveDetector* sd, string LVname, string name){

    G4SDManager* SDman = G4SDManager::GetSDMpointer();
    G4LogicalVolume* lv = G4tgbVolumeMgr::GetInstance()->FindG4LogVol("LVname");
    
    if(lv){
        SDman->AddNewDetector(sd);
        lv->SetSensitiveDetector(sd);
    }else{
        cout<<"lv does not exist"<<endl;
    }

}