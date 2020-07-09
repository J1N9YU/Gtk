#ifndef GtkUniversalSD_hh
#define GtkUniversalSD_hh 1

#include "G4VSensitiveDetector.hh"
#include "GtkUniversalHit.hh"
#include "G4SDManager.hh"
#include "G4OpticalPhoton.hh"
#include "GtkUniversalHit.hh"
#include "string"
#include "vector"
#include "map"

using namespace std;

class GtkUniversalSD:public G4VSensitiveDetector{

    public:

    GtkUniversalSD(const G4String &SDname);
    ~GtkUniversalSD();

    virtual void Initialize(G4HCofThisEvent* );
    virtual G4bool ProcessHits(G4Step* , G4TouchableHistory* );

    protected:

    string targetParticleName;
    int copyNum = 1;
    vector<GtkUniHC*> theHCs;
    



};









#endif