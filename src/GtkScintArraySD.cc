#include "GtkScintArraySD.hh"
#include "GtkDetectorConstruction.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4RunManager.hh"

#include "G4SDManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4LogicalVolumeStore.hh"


#include "G4VProcess.hh"
#include "G4OpticalPhoton.hh"
#include "G4MuonPlus.hh"
#include "G4MuonMinus.hh"
#include "G4NeutrinoMu.hh"
#include "G4AntiNeutrinoMu.hh"
#include "G4tgbVolumeMgr.hh"


#include "G4Threading.hh"
#include "globals.hh"
#include "G4SystemOfUnits.hh"

#include "tools/histo/h1d"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <cmath>

using CLHEP::HepRandom;
using CLHEP::RandExponential;

GtkScintArraySD::GtkScintArraySD(const G4String& SDname):
    G4VSensitiveDetector(SDname)
{

    G4SDManager::GetSDMpointer()->AddNewDetector(this);
}

GtkScintArraySD::~GtkScintArraySD()
{

}
void GtkScintArraySD::Initialize(G4HCofThisEvent* HCTE)
{
    
    auto SDmgr = G4SDManager::GetSDMpointer();
    
    //Initialize theHCs 
    for(auto cn:collectionName){
        auto hc = new GtkHitsCollection(SensitiveDetectorName,cn);
        int id = SDmgr->GetCollectionID(hc);
        HCTE->AddHitsCollection(id,hc);
    }
    
}

void GtkScintArraySD::SetComposition(vector<string> names){
    for(auto na:names){
        collectionName.push_back(na);
    }
}


void GtkScintArraySD::EndOfEvent(G4HCofThisEvent *hitCollection){

}

G4bool GtkScintArraySD::ProcessHits(G4Step* step, G4TouchableHistory*)
{
//the return value of this function is currently researved and
//it may be used in the future update of Geant4 application.
    
    auto ParticleNow = step->GetTrack()->GetParticleDefinition();
    const G4int VolumeCpyNb = step->GetPreStepPoint()->GetTouchableHandle()->GetCopyNumber();
    //the case that a opticalphoton generated in the scintillator
/*
    Notice: 
            When optical photons Generated in the Scintillator hits the aluminum foil, 
        which means the boundary process has happened, and G4 considered that the optical
        photon has entered the foil(PostStepPoint) and will be reflected in the Scintillator
        in the next step or will be absorbed by the foil.
            As a result, the IsFirstStepInVolume() method will not work! We must compare the TrackID to 
        indentify whether the particle has been counted or not.
*/
    if( *ParticleNow == *G4OpticalPhoton::Definition() )
    {
        if( /*step->GetTrack()->GetTrackID() != FormerID*/1 )
        {
            const G4double aPhotonEneg = step->GetTrack()->GetKineticEnergy();
            const G4double GlobalTime = step->GetPreStepPoint()->GetGlobalTime();
            if( VolumeCpyNb == 1 )
            {
                //auto pPhotonHitUp = new secScintHit();
                //pPhotonHitUp->SetPhotonEneg(aPhotonEneg).SetPhotonGlobalTime(GlobalTime);
                //pPhotonHCup->insert(pPhotonHitUp);
            }
            else if( VolumeCpyNb == 2 )
            {
                //auto pPhotonHitDown = new secScintHit();
                //pPhotonHitDown->SetPhotonEneg(aPhotonEneg).SetPhotonGlobalTime(GlobalTime);
                //pPhotonHCdown->insert(pPhotonHitDown);

            }
            //update the id
            step->GetTrack()->SetTrackStatus(fStopAndKill);
            return false;
        }
    }
//the case that a muon hit the scintillator
    else if( *ParticleNow == *G4MuonPlus::Definition() ||
             *ParticleNow == *G4MuonMinus::Definition() )
    {
        G4double aStepEdep = step->GetTotalEnergyDeposit();
        G4double GlobalTime = step->GetPreStepPoint()->GetGlobalTime();
        G4double MuonVelocity = step->GetPreStepPoint()->GetVelocity();
        
        if( VolumeCpyNb == 1 )
        {
            if( step->IsFirstStepInVolume() )
            {
                //MuonArriveTime += RandExponential::shoot( HepRandom::getTheEngine(), 2.*s );
            }
            //get energy disposit

            //save to hits collection
            //auto pMuonHitUp = new secScintHit();
            //pMuonHitUp->SetMuonGlobalTime(GlobalTime).SetMuonVelocity(MuonVelocity);
            //pMuonHCup->insert(pMuonHitUp);
        }
        else if( VolumeCpyNb == 2 )
        {
            //get energy deposit
            //save to hits collection
            //auto pMuonHitDown = new secScintHit();
            //pMuonHitDown->SetMuonGlobalTime(GlobalTime).SetMuonVelocity(MuonVelocity);
            //pMuonHCdown->insert(pMuonHitDown);
	    }
    }
    else if( *ParticleNow == *G4NeutrinoMu::Definition() || 
	         *ParticleNow == *G4AntiNeutrinoMu::Definition() )
    {
        if( step->IsFirstStepInVolume() && VolumeCpyNb == 2)
        {
            std::cout << "****Decayed!!****" << '\n';
            step->GetTrack()->SetTrackStatus(fStopAndKill);
        }
    }
    return true;
    
}









