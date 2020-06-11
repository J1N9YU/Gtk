

#include "GtkActionInitialization.hh"
#include "GtkPrimaryGeneratorAction.hh"
#include "GtkRunAction.hh"
#include "GtkEventAction.hh"




//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

GtkActionInitialization::GtkActionInitialization()
 : G4VUserActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

GtkActionInitialization::~GtkActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void GtkActionInitialization::BuildForMaster() const
{
  GtkRunAction* runAction = new GtkRunAction;
  SetUserAction(runAction);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void GtkActionInitialization::Build() const
{
  SetUserAction(new GtkPrimaryGeneratorAction);

  GtkRunAction* runAction = new GtkRunAction;
  SetUserAction(runAction);
  
  GtkEventAction* eventAction = new GtkEventAction(runAction);
  SetUserAction(eventAction);
  
}  

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
