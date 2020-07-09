#include "GtkPhysicsList.hh"

#include "G4OpticalPhysics.hh"
#include "G4SpinDecayPhysics.hh"
#include "G4DecayPhysics.hh"
#include "G4EmStandardPhysics.hh"
#include "G4HadronElasticPhysics.hh"
#include "G4IonPhysics.hh"
#include "G4StepLimiterPhysics.hh"

#include "G4MuonPlus.hh"
#include "G4MuonMinus.hh"
#include "G4Electron.hh"
#include "G4Positron.hh"
#include "G4Region.hh"
#include "G4RegionStore.hh"
#include "G4SystemOfUnits.hh"
#include "globals.hh"

GtkPhysicsList::GtkPhysicsList() : G4VModularPhysicsList(){
    RegisterPhysics(new G4DecayPhysics);
    RegisterPhysics(new G4EmStandardPhysics);
    RegisterPhysics(new G4HadronElasticPhysics);
    RegisterPhysics(new G4IonPhysics);
    RegisterPhysics(new G4StepLimiterPhysics);
    auto opticalPhysics = new G4OpticalPhysics;
    opticalPhysics->SetTrackSecondariesFirst(kScintillation, true);
    opticalPhysics->SetTrackSecondariesFirst(kCerenkov,      true);
    opticalPhysics->SetTrackSecondariesFirst(kWLS,           true);
//Scintillation
    opticalPhysics->SetScintillationYieldFactor(1.);
    opticalPhysics->SetScintillationExcitationRatio(0.);
//Cerenkov light
    opticalPhysics->SetMaxNumPhotonsPerStep(50);
//wave length shifting (WLS)
    opticalPhysics->SetWLSTimeProfile("delta");
    RegisterPhysics(opticalPhysics);
}

GtkPhysicsList::~GtkPhysicsList(){

}


void GtkPhysicsList::SetCuts(){
    G4VUserPhysicsList::SetCuts();
    SetCutValue(0.1*mm, "e+", "sci_reg2");
    SetCutValue(0.1*mm, "e-", "sci_reg2");
}

