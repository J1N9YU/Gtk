

#ifndef GtkPrimaryGeneratorAction_h
#define GtkPrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "GtkDetectorConstruction.hh"

#include "G4ParticleGun.hh"
#include "globals.hh"

#include"MyDataAnalysisHelper.hh"
#include "G4GeneralParticleSource.hh"

class G4ParticleGun;
class G4Event;
class G4Box;

/// The primary generator action class with particle gun.
///
/// The default kinematic is a 6 MeV gamma, randomly distribued 
/// in front of the phantom across 80% of the (X,Y) phantom size.

class GtkPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    GtkPrimaryGeneratorAction();    
    virtual ~GtkPrimaryGeneratorAction();

    // method from the base class
    virtual void GeneratePrimaries(G4Event*);         
  
    // method to access particle gun
    const G4ParticleGun* GetParticleGun() const { return fParticleGun; }

    G4ThreeVector GetRandomDirection();
    G4ThreeVector GetRandomPosition();
    G4ThreeVector GetSpecificDirection();
    G4ThreeVector GetSpecificPosition();
    void SetRandomOptPhotonPolar();
    inline void SetTestMode(bool mode){isTestMode=mode;}
    MyDataAnalysisHelper* myHelper;
  
  private:
    G4ParticleGun*  fParticleGun; // pointer a to G4 gun class
    G4GeneralParticleSource* fparticleSource;
    
    bool isTestMode;              // in test mode, particle gun shoot photon with specific positiong and direction instead of random generating them.



};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
