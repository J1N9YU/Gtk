

#ifndef GtkMaterials_h
#define GtkMaterials_h 1

#include "globals.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "GtkDetectorConstruction.hh"

class GtkMaterials
{
  public:

    virtual ~GtkMaterials();
 
    static GtkMaterials* GetInstance();

    G4Material* GetMaterial(const G4String);
 
  private:
 
    GtkMaterials();

    void CreateMaterials();

  private:

    static GtkMaterials* fInstance;

    G4NistManager*     fNistMan;

    G4Material*        fAir;

    G4Material*        fPMMA;
    G4Material*        fPCB;
    G4Material*        fMetal;
    G4Material*        fSiPD;

};

#endif /*GtkMaterials_h*/
