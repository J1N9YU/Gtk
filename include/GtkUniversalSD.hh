#ifndef GtkUniversalSD_hh
#define GtkUniversalSD_hh 1

#include "G4VSensitiveDetector.hh"
#include "string"

using namespace std;

class GtkUniversalSD:public G4VSensitiveDetector{

    public:

    GtkUniversalSD();
    ~GtkUniversalSD();

    virtual void Initialize(G4HCofThisEvent* );
    virtual G4bool ProcessHits(G4Step* , G4TouchableHistory* );

    protected:

    string targetParticleName;
    

    



};









#endif