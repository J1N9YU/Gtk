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

    ConstructFromFileCmd = new G4UIcmdWithAString("/Construction/ConstructFromFile",this);
    ConstructFromFileCmd->SetGuidance("Add a detector component according to a txt file");
    ConstructFromFileCmd->SetParameterName("File name",true,true);

}

GtkDetectorConstructionMessenger::~GtkDetectorConstructionMessenger(){
    delete directory;
    delete SetPMMAThicknessCmd;
    delete SetSiPDEdgeCmd;
    delete HellowWorldCmd;
    delete ConstructFromFileCmd;
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

    if(command==ConstructFromFileCmd){
        string fileName = newValues;
        if(fileName.empty()){
            return;
        }
        ConstructFromFile(fileName);






    }


    //G4UImanager::GetUIpointer()->ApplyCommand("/control/execute init_vis.mac");
}

G4String GtkDetectorConstructionMessenger::GetCurrentValue(G4UIcommand* command){
    G4String cv;
    return cv;
}

void GtkDetectorConstructionMessenger::ConstructFromFile(string fileName){
    ifstream file(fileName);
    if(!file.is_open()){
        G4cout<<"File "<<fileName<<" not found !"<<G4endl;
        return;
    }
    string temp;
    vector<string> sv;
    while(getline(file,temp,' ')){
        sv.push_back(temp);
    }
    file.close();

    for(auto s:sv){
        G4cout<<s<<G4endl;
    }

    //parameters
    G4double pos_x;
    G4double pos_y;
    G4double pos_z;
    G4double dim_x;
    G4double dim_y;
    G4double dim_z;
    string type;
    string material;

    int i=0;
    while(i<sv.size()){
        if(sv[i]=="pos"){
            i+=3;
            if(i>=sv.size()){
                G4cout<<"Invalid syntax"<<G4endl;
                return;
            }
            pos_x = stod(sv[i-2]);
            pos_y = stod(sv[i-1]);
            pos_z = stod(sv[i]);
            i++;
        }
        else if(sv[i]=="type"){
            i+=1;
            if(i>=sv.size()){
                G4cout<<"Invalid syntax"<<G4endl;
                return;
            }
            type = sv[i];
            i++;
        }
        else if(sv[i]=="dim"){
            i+=3;
            if(i>=sv.size()){
                G4cout<<"Invalid syntax"<<G4endl;
                return;
            }
            dim_x = stod(sv[i-2]);
            dim_y = stod(sv[i-1]);
            dim_z = stod(sv[i]);
            i++;
        }
        else if(sv[i]=="material"){
            i+=1;
            if(i>=sv.size()){
                G4cout<<"Invalid syntax"<<G4endl;
                return;
            }
            material = sv[i];
            i++;
        }
    }

    





}