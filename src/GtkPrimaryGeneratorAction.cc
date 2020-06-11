

#include "GtkPrimaryGeneratorAction.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"



GtkPrimaryGeneratorAction::GtkPrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction(),
  fParticleGun(0)
{
  G4int n_particle = 1;
  fParticleGun  = new G4ParticleGun(n_particle);

  // default particle kinematic
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName;
  G4double waveLength = 235.5*nm;
  G4double energy = CLHEP::h_Planck*CLHEP::c_light/waveLength;
  G4cout<<"energy is :"<<energy/eV<<G4endl;
  G4ParticleDefinition* particle
    = particleTable->FindParticle(particleName="opticalphoton");
  fParticleGun->SetParticleDefinition(particle);
  fParticleGun->SetParticleEnergy(energy);
  isTestMode=false;

  myHelper=MyDataAnalysisHelper::GetInstance();
}



GtkPrimaryGeneratorAction::~GtkPrimaryGeneratorAction()
{
  delete fParticleGun;
}



void GtkPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  //code for each inital event
  if(!isTestMode){
    fParticleGun->SetParticleMomentumDirection(GetRandomDirection());
    fParticleGun->SetParticlePosition(GetRandomPosition());
  }else{
    fParticleGun->SetParticleMomentumDirection(GetSpecificDirection());
    fParticleGun->SetParticlePosition(GetSpecificPosition());
  }

  SetRandomOptPhotonPolar();

  

  fParticleGun->GeneratePrimaryVertex(anEvent);

}

G4ThreeVector GtkPrimaryGeneratorAction::GetRandomDirection(){
  
  

  G4double theta = G4UniformRand()*2*CLHEP::pi;
  G4double phi = CLHEP::pi-asin(G4UniformRand());                               //generate phi basing on lambert light source assumption
  G4double x = cos(theta)*sin(phi);
  G4double z = sin(theta)*sin(phi);
  G4double y = cos(phi);
  G4ThreeVector direction(x,y,z);
  return direction;
}

//Generate position of light source
G4ThreeVector GtkPrimaryGeneratorAction::GetRandomPosition(){
  GtkDetectorConstruction* dc = (GtkDetectorConstruction*)(G4RunManager::GetRunManager()->GetUserDetectorConstruction());
  G4double theta = G4UniformRand()*2*CLHEP::pi;
  G4double maxR = 2.49*cm;                     //width
  G4double R2 = G4UniformRand()*maxR*maxR;
  G4double R = sqrt(R2);
  G4double x = R*cos(theta);
  G4double z = R*sin(theta);
  G4double y = 0.36*cm;                        //altitude
  return G4ThreeVector(x,y,z);
}

G4ThreeVector GtkPrimaryGeneratorAction::GetSpecificDirection(){
  G4double theta = 0.01;
  G4double phi = 0.55*CLHEP::pi;                               
  G4double x = cos(theta)*sin(phi);
  G4double z = sin(theta)*sin(phi);
  G4double y = cos(phi);
  G4ThreeVector direction(x,y,z);
  return direction;
}

G4ThreeVector GtkPrimaryGeneratorAction::GetSpecificPosition(){
  GtkDetectorConstruction* dc = (GtkDetectorConstruction*)(G4RunManager::GetRunManager()->GetUserDetectorConstruction());
  G4double x = 0.2*cm;
  G4double z = 0;
  G4double y = 0.30*cm;                        //altitude
  return G4ThreeVector(x,y,z);
}



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void GtkPrimaryGeneratorAction::SetRandomOptPhotonPolar()
{
 if (fParticleGun->GetParticleDefinition()->GetParticleName()!="opticalphoton")
   {
     G4cout << "--> warning from PrimaryGeneratorAction::SetOptPhotonPolar() :"
               "the particleGun is not an opticalphoton" << G4endl;
     return;
   }

 G4double angle = G4UniformRand() * 360.0*deg;
 G4ThreeVector normal (1., 0., 0.);
 G4ThreeVector kphoton = fParticleGun->GetParticleMomentumDirection();
 G4ThreeVector product = normal.cross(kphoton);
 G4double modul2       = product*product;
 
 G4ThreeVector e_perpend (0., 0., 1.);
 if (modul2 > 0.) e_perpend = (1./std::sqrt(modul2))*product;
 G4ThreeVector e_paralle    = e_perpend.cross(kphoton);
 
 G4ThreeVector polar = std::cos(angle)*e_paralle + std::sin(angle)*e_perpend;
 fParticleGun->SetParticlePolarization(polar);
}
