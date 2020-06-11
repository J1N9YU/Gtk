

#ifndef GtkPhotonDetHit_h
#define GtkPhotonDetHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"

#include "G4ThreeVector.hh"
#include "G4Transform3D.hh"
#include "G4RotationMatrix.hh"

#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"

#include "tls.hh"

class G4VTouchable;

//--------------------------------------------------
// GtkPhotonDetHit Class
//--------------------------------------------------

class GtkPhotonDetHit : public G4VHit
{
  public:
    GtkPhotonDetHit();
    GtkPhotonDetHit(G4ThreeVector pExit, G4ThreeVector pArrive, G4double pTime);
    virtual ~GtkPhotonDetHit();

    GtkPhotonDetHit(const GtkPhotonDetHit &right);
    const GtkPhotonDetHit& operator=(const GtkPhotonDetHit& right);

    G4bool operator==(const GtkPhotonDetHit& right) const;

    inline void *operator new(size_t);
    inline void operator delete(void *aHit);

    inline void SetArrivalPos(G4ThreeVector xyz) { fPosArrive = xyz; }
    inline G4ThreeVector GetArrivalPos() { return fPosArrive; }

    inline void SetExitPos(G4ThreeVector xyz) { fPosExit = xyz; }
    inline G4ThreeVector GetExitPos() { return fPosExit; }

    inline void SetArrivalTime(G4double t) { fArrivalTime = t; }
    inline G4double GetArrivalTime() { return fArrivalTime; }
 
  private:

    // the arrival time of the photon
    G4double      fArrivalTime;
    // where the photon hit the detector (detector's coordinate)
    G4ThreeVector fPosArrive;
    // where the photon exited the fiber (world's coordinate)
    G4ThreeVector fPosExit;

};

//--------------------------------------------------
// Type Definitions
//--------------------------------------------------

typedef G4THitsCollection<GtkPhotonDetHit> GtkPhotonDetHitsCollection;

extern G4ThreadLocal G4Allocator<GtkPhotonDetHit>* GtkPhotonDetHitAllocator;

//--------------------------------------------------
// Operator Overloads
//--------------------------------------------------

inline void* GtkPhotonDetHit::operator new(size_t)
{
  if(!GtkPhotonDetHitAllocator)
      GtkPhotonDetHitAllocator = new G4Allocator<GtkPhotonDetHit>;
  return (void *) GtkPhotonDetHitAllocator->MallocSingle();
}

inline void GtkPhotonDetHit::operator delete(void *aHit)
{
  GtkPhotonDetHitAllocator->FreeSingle((GtkPhotonDetHit*) aHit);
}

#endif
