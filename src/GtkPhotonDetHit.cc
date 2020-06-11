//
// ********************************************************************

//
//
#include "GtkPhotonDetHit.hh"

G4ThreadLocal G4Allocator<GtkPhotonDetHit>* GtkPhotonDetHitAllocator=0;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

GtkPhotonDetHit::GtkPhotonDetHit()
{
  fArrivalTime = 0.;
  fPosArrive   = G4ThreeVector(0., 0., 0.);
  fPosExit     = G4ThreeVector(0., 0., 0.);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

GtkPhotonDetHit::GtkPhotonDetHit(G4ThreeVector pExit,
                                 G4ThreeVector pArrive,
                                 G4double pTime)
{
  fPosExit     = pExit;
  fPosArrive   = pArrive;
  fArrivalTime = pTime;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

GtkPhotonDetHit::~GtkPhotonDetHit() { }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

GtkPhotonDetHit::GtkPhotonDetHit(const GtkPhotonDetHit &right)
  : G4VHit()
{
  *this = right;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

const GtkPhotonDetHit& GtkPhotonDetHit::operator=(const GtkPhotonDetHit &right)
{
  fPosExit     = right.fPosExit;
  fPosArrive   = right.fPosArrive;
  fArrivalTime = right.fArrivalTime;

  return *this;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4bool GtkPhotonDetHit::operator==(const GtkPhotonDetHit& right) const
{
  return fPosExit     == right.fPosExit    &&
         fPosArrive   == right.fPosArrive  &&
         fArrivalTime == right.fArrivalTime;  
}
