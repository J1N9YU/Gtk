#include "GtkUniversalHit.hh"

G4ThreadLocal G4Allocator<GtkUniversalHit>* GtkUniHitAllocator = 0;

GtkUniversalHit::GtkUniversalHit(){

}

GtkUniversalHit::GtkUniversalHit(G4double energy,G4double arrivalTime){
    fArrivalTime = arrivalTime;
    fEnergy = energy;
}

GtkUniversalHit::~GtkUniversalHit(){

}

const GtkUniversalHit& GtkUniversalHit::operator=(const GtkUniversalHit &right)
{

  fArrivalTime = right.fArrivalTime;
  return *this;
}



G4bool GtkUniversalHit::operator==(const GtkUniversalHit& right) const
{
  return fArrivalTime == right.fArrivalTime;  
}
