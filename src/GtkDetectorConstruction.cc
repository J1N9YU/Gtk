

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




GtkDetectorConstruction::~GtkDetectorConstruction()
{ 
  delete fDCM;
}




G4VPhysicalVolume* GtkDetectorConstruction::Construct()
{    

  ConstrcutAscii();

  return physAscWorld;

}



void GtkDetectorConstruction::ConstructSDandField(){

  GtkSDManager::GetInstance()->AssignSDtoLogicVolume(new GtkPhotonDetSD("/mySD/photonSD"),"sipm","/mySD/photonSD");
  
}




void GtkDetectorConstruction::ConstrcutAscii(){

  
  //impoty ascii modles
  //volmgr->AddTextFile("../ascii_modles/g4geom_material.txt");
  volmgr->AddTextFile("../ascii_modles/g4geom_simple.txt");
  

  //Chose Gtk detector builder inorder to invoke Gtk LineProcessor
  GtktgbDetectorBuilder* gtb = new GtktgbDetectorBuilder;
  volmgr->SetDetectorBuilder(gtb);
  
  const G4tgrVolume* tgrVoltop = gtb->ReadDetector();
  physAscWorld = gtb->ConstructDetector(tgrVoltop);

  //Add properties
  fMaterials->AddPropertyToMaterial();
}

void GtkDetectorConstruction::ConstrcutAsciiSDandField(){
  
}

