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

    ReInitializeGeometryCmd = new G4UIcmdWithoutParameter("/Construction/ReInitializeGeometry",this);

    ClearCmd = new G4UIcmdWithoutParameter("/Construction/Clear",this);
    
    TestCmd = new G4UIcmdWithoutParameter("/Construction/Test",this);

    ConstructFromFileCmd = new G4UIcmdWithAString("/Construction/ConstructFromFile",this);
    ConstructFromFileCmd->SetGuidance("Add a detector component according to a txt file");
    ConstructFromFileCmd->SetParameterName("File name",true,true);

}

GtkDetectorConstructionMessenger::~GtkDetectorConstructionMessenger(){
    delete directory;
    delete SetPMMAThicknessCmd;
    delete SetSiPDEdgeCmd;
    delete ReInitializeGeometryCmd;
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
        fDetectorConstruction->SetphotodiodeEdge(SetSiPDEdgeCmd->GetNewDoubleValue(newValues));./G  
        */
    }

    if(command==ReInitializeGeometryCmd){
        G4cout<<"reinitializing geometry ...";
        //delete fDetectorConstruction->physAscWorld;
        
        //G4RunManager::GetRunManager()->ReinitializeGeometry(true);
        fDetectorConstruction->ConstrcutAsciimodels();
        G4RunManager::GetRunManager()->GeometryHasBeenModified();
        //G4UImanager::GetUIpointer()->ApplyCommand("/control/execute vis.mac");
        G4cout<<" complete!"<<G4endl;
        
    }

    if(command == ClearCmd){
        G4tgrRotationMatrixFactory::GetInstance()->DumpRotmList();
        G4tgbVolumeMgr::GetInstance()->DumpSummary();
        G4tgbVolumeMgr::GetInstance()->~G4tgbVolumeMgr();
    }

    if(command == TestCmd){
        //GtkMaterials::GetInstance()->ImportPorpertyFromFolder("../Property Data/");
        GtkMaterials::GetInstance()->ReadTextFile("../Property Data/scintFastComponent.txt");


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
    
}