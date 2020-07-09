#ifndef GtkUniversalHit_hh
#define GtkUniversalHit_hh 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"

class GtkUniversalHit:public G4VHit{

    public:

    GtkUniversalHit();
    GtkUniversalHit(G4double energy,G4double arrivalTime);
    ~GtkUniversalHit();
    
    //operators
    const GtkUniversalHit& operator=(const GtkUniversalHit& right);
    G4bool operator==(const GtkUniversalHit& right) const;
    inline void *operator new(size_t);
    inline void operator delete(void *aHit);

    protected:

    G4double fArrivalTime;
    G4double fEnergy;


};


//--------------------------------------------------
// Type Definitions
//--------------------------------------------------

typedef G4THitsCollection<GtkUniversalHit> GtkUniHC;

extern G4ThreadLocal G4Allocator<GtkUniversalHit>* GtkUniHitAllocator;




//--------------------------------------------------
// Operator Overloads
//--------------------------------------------------



inline void* GtkUniversalHit::operator new(size_t)
{
  if(!GtkUniHitAllocator)
      GtkUniHitAllocator = new G4Allocator<GtkUniversalHit>;
  return (void *) GtkUniHitAllocator->MallocSingle();
}

inline void GtkUniversalHit::operator delete(void *aHit)
{
  GtkUniHitAllocator->FreeSingle((GtkUniversalHit*) aHit);
}

#endif