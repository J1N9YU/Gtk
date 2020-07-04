#ifndef gtkScintArraySD_hh
#define gtkScintArraySD_hh
#include "G4VSensitiveDetector.hh"
#include "globals.hh"
#include "GtkHit.hh"
#include "vector"
#include "map"



class G4Step;
class G4HCofThisEvent;

using namespace std;

class GtkScintArraySD : public G4VSensitiveDetector
{
    public:

        GtkScintArraySD(const G4String &SDname);
        virtual ~GtkScintArraySD();

        virtual void Initialize(G4HCofThisEvent *hitCollection);
        virtual void EndOfEvent(G4HCofThisEvent *hitCollection);
        virtual G4bool ProcessHits(G4Step *step, G4TouchableHistory *history);

        void SetComposition(vector<string> names = vector<string>(1,"no name"));    

    private:

        G4LogicalVolume* theLogicalVol;
        int theHCNum;

   
};



#endif
