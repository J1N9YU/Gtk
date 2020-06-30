

#include "GtkDetectorConstruction.hh"
#include "GtkScintArraySD.hh"

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
  volmgr = G4tgbVolumeMgr::GetInstance();



  //Material helper class
  fMaterials = GtkMaterials::GetInstance();

  //UI messager
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
  /*
  auto SDArray = new GtkScintArraySD("GtkSD/Scintillator_array");
  SetSensitiveDetector("scintlv",SDArray);
  */
  
}


void GtkDetectorConstruction::ConstrcutAsciimodels(){

  
  //impoty ascii modles
  volmgr->AddTextFile("../ascii_modles/g4geom_simple.txt");

  //Chose Gtk detector builder inorder to invoke Gtk LineProcessor
  cout<<"setting custom detector builder"<<endl;
  GtktgbDetectorBuilder* gtb = new GtktgbDetectorBuilder;
  volmgr->SetDetectorBuilder(gtb);
  const G4tgrVolume* tgrVoltop = gtb->ReadDetector();
  physAscWorld = gtb->ConstructDetector(tgrVoltop);

  //Use default line processor
  //physAscWorld = volmgr->ReadAndConstructDetector();
}



