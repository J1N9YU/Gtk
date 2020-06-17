

#include "GtkDetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4Tubs.hh"
#include "G4RotationMatrix.hh"
#include "GtkPhotonDetSD.hh"
#include "G4SDManager.hh"
#include "G4Colour.hh"
#include "G4OpticalSurface.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4SurfaceProperty.hh"
#include "GtkDetectorConstructionMessnger.hh"


GtkDetectorConstruction::GtkDetectorConstruction()
: G4VUserDetectorConstruction()
{
  G4cout<<"detectorconstruction constructor is called"<<G4endl;
  fMaterials = GtkMaterials::GetInstance();
  fDCM = new GtkDetectorConstructionMessenger(this);
  


}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

GtkDetectorConstruction::~GtkDetectorConstruction()
{ 
  delete fDCM;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* GtkDetectorConstruction::Construct()
{    

  G4cout<<"Construct() is called"<<G4endl;
  
  
  //ascii-----------------------------------------------------------------
  
  ConstrcutAsciimodels();

  return physAscWorld;

}

G4Material* GtkDetectorConstruction::FindMaterial(G4String name) {
    G4Material* material = G4Material::GetMaterial(name,true);
    return material;
}

void GtkDetectorConstruction::ConstructSDandField(){
  
}


void GtkDetectorConstruction::ConstrcutAsciimodels(){
  volmgr = G4tgbVolumeMgr::GetInstance();
  volmgr->AddTextFile("../ascii_models/g4geom_simple.txt");
  physAscWorld = volmgr->ReadAndConstructDetector();
}



