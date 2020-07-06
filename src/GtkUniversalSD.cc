#include "GtkUniversalSD.hh"


GtkUniversalSD::GtkUniversalSD(const G4String &SDname):G4VSensitiveDetector(SDname){

};

GtkUniversalSD::~GtkUniversalSD(){

};

void GtkUniversalSD::Initialize(G4HCofThisEvent* HCTE){
    
    auto SDmgr = G4SDManager::GetSDMpointer();
    for(int i=0;i<copyNum;i++){
        auto hc = new GtkUniHC("GtkUniversalSD","GtkUniHC_"+to_string(i));
        G4int id = SDmgr->GetCollectionID(hc);
        HCTE->AddHitsCollection(id,hc);
        theHCs.push_back(hc);
    }
}


G4bool GtkUniversalSD::ProcessHits(G4Step* step, G4TouchableHistory* history){
    
    auto particleDef = step->GetTrack()->GetParticleDefinition();
    int copyID = step->GetPreStepPoint()->GetTouchable()->GetCopyNumber();
    G4double energy = step->GetPreStepPoint()->GetKineticEnergy();
    
    //filter particle
    if(particleDef == G4OpticalPhoton::Definition()){
        
        //construct hit object, set properties
        auto hit = new GtkUniversalHit;
        
        //add to collection
        theHCs[copyID]->insert(hit);
        
        //kill the track
        step->GetTrack()->SetTrackStatus(fStopAndKill);
        return true;
    }


}