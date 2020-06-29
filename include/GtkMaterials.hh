

#ifndef GtkMaterials_h
#define GtkMaterials_h 1

#include "globals.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "GtkDetectorConstruction.hh"

#include "map"
#include "vector"

using namespace std;

class GtkMaterials
{
  public:

    virtual ~GtkMaterials();
    static GtkMaterials* GetInstance();
    G4Material* GetMaterial(const G4String);

    void ReadTextFile(string fileName);
    void AddPropertyToMaterial(G4Material* mat,string propertyName,string vecName1,string vecName2);
    void ImportPorpertyFromFolder(string path);

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
    G4Material*        fScintillator;

    map<string,vector<G4double>> parV;
    

};

#endif
