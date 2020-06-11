#include "GtkDetectorConstructionMessnger.hh"
#include "GtkDetectorConstruction.hh"



class GtkDetectorConstruction;
class G4String;

GtkDetectorConstructionMessenger::GtkDetectorConstructionMessenger(GtkDetectorConstruction* fdc):fDetectorConstruction(fdc){
    directory = new G4UIdirectory("/Construction/");
    directory->SetGuidance("Commands to change geometry");

    SetPMMAThicknessCmd = new G4UIcmdWithADoubleAndUnit("/Construction/SetPMMAThickness",this);
    SetPMMAThicknessCmd->SetParameterName("thicknessOfPMMA",true,true);
    SetPMMAThicknessCmd->SetDefaultUnit("cm");
    SetPMMAThicknessCmd->SetGuidance("change the thickness of PMMA");

    SetSiPDEdgeCmd = new G4UIcmdWithADoubleAndUnit("/Construction/SetSiPDEdge",this);
    SetSiPDEdgeCmd->SetGuidance("change the edge of SiPD");
    SetSiPDEdgeCmd->SetParameterName("photodiodeEdge",true,true);
    SetSiPDEdgeCmd->SetDefaultUnit("cm");

    HellowWorldCmd = new G4UIcmdWithoutParameter("/Construction/HellowWorld",this);

}

GtkDetectorConstructionMessenger::~GtkDetectorConstructionMessenger(){
    delete directory;
    delete SetPMMAThicknessCmd;
    delete SetSiPDEdgeCmd;
    delete HellowWorldCmd;
}

void GtkDetectorConstructionMessenger::SetNewValue(G4UIcommand * command,G4String newValues){
    if(command==SetPMMAThicknessCmd){
        /*
        fDetectorConstruction->SetThicknessOfPMMA(SetPMMAThicknessCmd->GetNewDoubleValue(newValues));
        G4cout<<"Now thickness is"<<fDetectorConstruction->GetThicknessOfPMMA()<<G4endl;
        */  
    }
    if(command==SetSiPDEdgeCmd){
        /*
        fDetectorConstruction->SetphotodiodeEdge(SetSiPDEdgeCmd->GetNewDoubleValue(newValues));
        */
    }
    if(command==HellowWorldCmd){
        G4cout<<"Hellow World"<<G4endl;
    }
    //G4UImanager::GetUIpointer()->ApplyCommand("/control/execute init_vis.mac");
}

G4String GtkDetectorConstructionMessenger::GetCurrentValue(G4UIcommand* command){
    G4String cv;
    return cv;
}
