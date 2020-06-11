

#ifndef GtkPhotonDetSD_h
#define GtkPhotonDetSD_h 1

#include "GtkPhotonDetHit.hh"

#include "G4VSensitiveDetector.hh"

class G4Step;
class G4HCofThisEvent;

class GtkPhotonDetSD : public G4VSensitiveDetector
{
  public:

    GtkPhotonDetSD(G4String );
    virtual ~GtkPhotonDetSD();

    virtual void Initialize(G4HCofThisEvent* );

    virtual G4bool ProcessHits(G4Step* , G4TouchableHistory* );

  private:

    GtkPhotonDetHitsCollection* fPhotonDetHitCollection;
};

#endif
