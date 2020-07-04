

#ifndef GtkHit_h
#define GtkHit_h 1

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
// GtkHit Class
//--------------------------------------------------

class GtkHit : public G4VHit
{
  public:
    GtkHit();
    GtkHit(G4ThreeVector pExit, G4ThreeVector pArrive, G4double pTime);
    virtual ~GtkHit();

    GtkHit(const GtkHit &right);
    const GtkHit& operator=(const GtkHit& right);

    G4bool operator==(const GtkHit& right) const;

    inline void *operator new(size_t);
    inline void operator delete(void *aHit);

    inline void SetArrivalPos(G4ThreeVector xyz) { fPosArrive = xyz; }
    inline G4ThreeVector GetArrivalPos() { return fPosArrive; }

    inline void SetExitPos(G4ThreeVector xyz) { fPosExit = xyz; }
    inline G4ThreeVector GetExitPos() { return fPosExit; }

    inline void SetArrivalTime(G4double t) { fArrivalTime = t; }
    inline G4double GetArrivalTime() { return fArrivalTime; }
 
  private:

    G4double      fArrivalTime;
    G4ThreeVector fPosArrive;
    G4ThreeVector fPosExit;

};

//--------------------------------------------------
// Type Definitions
//--------------------------------------------------

typedef G4THitsCollection<GtkHit> GtkHitsCollection;

extern G4ThreadLocal G4Allocator<GtkHit>* GtkHitAllocator;

//--------------------------------------------------
// Operator Overloads
//--------------------------------------------------

inline void* GtkHit::operator new(size_t)
{
  if(!GtkHitAllocator)
      GtkHitAllocator = new G4Allocator<GtkHit>;
  return (void *) GtkHitAllocator->MallocSingle();
}

inline void GtkHit::operator delete(void *aHit)
{
  GtkHitAllocator->FreeSingle((GtkHit*) aHit);
}

#endif
