

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
  fMaterials = GtkMaterials::GetInstance();
  photodiodeEdge = 0.26*cm;
  SiPD_pv = NULL;
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
  //----------------------------------------------------------------------    
  // World
  
  G4VPhysicalVolume* physWorld;

  {
  G4double world_sizeXY = 12.0*cm;
  G4double world_sizeZ  = 12.0*cm;
  G4Material* world_mat = FindMaterial("G4_AIR");
  
  G4Box* solidWorld =    
    new G4Box("World",                       //its name
       0.5*world_sizeXY, 0.5*world_sizeXY, 0.5*world_sizeZ);     //its size
      
  logicWorld =                         
    new G4LogicalVolume(solidWorld,          //its solid
                        world_mat,           //its material
                        "World");            //its name
                                   
  physWorld = 
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      logicWorld,            //its logical volume
                      "World",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      false);        //overlaps checking

  }
  //----------------------------------------------------------------------
  
  //SiPD------------------------------------------------------------------    
  ConstructSiPD();
  //----------------------------------------------------------------------
  
  



  return physWorld;
}

G4Material* GtkDetectorConstruction::FindMaterial(G4String name) {
    G4Material* material = G4Material::GetMaterial(name,true);
    return material;
}

void GtkDetectorConstruction::ConstructSDandField(){
  /*
    if (!fmppcSD.Get()) {
     G4String mppcSDName = "GeppFac/PhotonDet";
     GtkPhotonDetSD* mppcSD = new GtkPhotonDetSD(mppcSDName);
     G4SDManager::GetSDMpointer()->AddNewDetector(mppcSD);
     fmppcSD.Put(mppcSD);
  }
  SetSensitiveDetector("SiPD_lv", fmppcSD.Get(), true);
  */
}



void GtkDetectorConstruction::ConstructSiPD(){
  if(SiPD_pv!=NULL)delete SiPD_pv;
  G4double dim_x = photodiodeEdge;
  G4double dim_y = 0.05*cm;
  G4double dim_z = photodiodeEdge;
  G4ThreeVector pos = G4ThreeVector(0*cm, dim_y, 0*cm);

  G4Material* SiPD_mat = FindMaterial("SiPD");

  G4Box* SiPDbox = new G4Box("SiPDsolid",dim_x,dim_y,dim_z);
                      
  G4LogicalVolume* SiPD_lv =                         
    new G4LogicalVolume(SiPDbox,         //its solid
                        SiPD_mat,          //its material
                        "SiPD_lv");           //its name
               
  SiPD_pv = new G4PVPlacement(0,                       //no rotation
                    pos,                    //at position
                    SiPD_lv,             //its logical volume
                    "SiPD_pl",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    false);          //overlaps checking


}



