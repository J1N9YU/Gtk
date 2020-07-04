#ifndef dcm
#define dcm 1
#include "G4UImessenger.hh" 
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithoutParameter.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UImanager.hh"
#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4tgbVolumeMgr.hh"
#include "G4tgrRotationMatrixFactory.hh"
#include "G4tgrFileReader.hh"

#include "globals.hh"
#include "G4String.hh"
#include "string"

#include "iostream"

class G4ParticleGun; 
class G4ParticleTable; 
class G4UIcommand; 
class G4UIdirectory; 
class G4UIcmdWithoutParameter; 
class G4UIcmdWithAString; 
class G4UIcmdWithADoubleAndUnit; 
class G4UIcmdWith3Vector; 
class G4UIcmdWith3VectorAndUnit;
class G4string;
class GtkDetectorConstruction;
class G4RunManager;
class G4UImanager;
class G4tgbVolumeMgr;
class G4tgrRotationMatrixFactory;
class G4tgrFileReader;

using namespace std;

class GtkDetectorConstructionMessenger:public G4UImessenger{
    public:
    GtkDetectorConstructionMessenger(GtkDetectorConstruction* fDC);
    ~GtkDetectorConstructionMessenger();

    void SetNewValue(G4UIcommand* command,G4String newValues); 
    G4String GetCurrentValue(G4UIcommand* command);

    private:
    GtkDetectorConstruction* fDetectorConstruction;
    G4UIdirectory* directory;
    G4UIcmdWithADoubleAndUnit* SetPMMAThicknessCmd;
    G4UIcmdWithADoubleAndUnit* SetSiPDEdgeCmd;
    G4UIcmdWithoutParameter* ReInitializeGeometryCmd;
    G4UIcmdWithAString* ConstructFromFileCmd;
    G4UIcmdWithoutParameter* ClearCmd;
    G4UIcmdWithoutParameter* TestCmd;

    void ConstructFromFile(std::string);

};

#endif
