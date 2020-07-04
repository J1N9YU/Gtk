#include "GtkEventAction.hh"
#include "GtkRunAction.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"
#include "GtkHit.hh"


//Constructor
GtkEventAction::GtkEventAction(GtkRunAction* runAction)
: G4UserEventAction(),
  fRunAction(runAction)
{
   fMDAH = MyDataAnalysisHelper::GetInstance();
} 


//destructor
GtkEventAction::~GtkEventAction()
{

}



void GtkEventAction::BeginOfEventAction(const G4Event*)
{
}



void GtkEventAction::EndOfEventAction(const G4Event* evt)
{   
 

  // Get Hits from the detector if any
  G4SDManager * SDman = G4SDManager::GetSDMpointer();
  G4String colName = "PhotonDetHitCollection";
  fMPPCCollID = SDman->GetCollectionID(colName);

  G4HCofThisEvent* HCE = evt->GetHCofThisEvent();
  GtkHitsCollection* mppcHC = 0;

  // Get the hit collections
  if (HCE)
  {
     if (fMPPCCollID>=0) mppcHC = (GtkHitsCollection*)(HCE->GetHC(fMPPCCollID));
  }

  // Get hit information about photons that reached the detector in this event
  if (mppcHC)
  {
     G4int n_hit = mppcHC->entries();
     if(n_hit!=0){
        fRunAction->AddHits();
      }
  }
}


