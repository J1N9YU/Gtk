
//
/// \file Gtk.cc
/// \brief Main program of the Gtk example



#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif

#include "G4UImanager.hh"
#include "QBBC.hh"
#include "LBE.hh"

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "Randomize.hh"
#include "G4OpticalPhysics.hh"

#include "globals.hh"
#include "G4GeometryManager.hh"

#include "GtkPrimaryGeneratorAction.hh"
#include "GtkDetectorConstruction.hh"
#include "GtkActionInitialization.hh"
#include "MyDataAnalysisHelper.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

int main(int argc,char** argv)
{
  
  // Detect interactive mode (if no arguments) and define UI session
  //
  G4UIExecutive* ui = 0;
  if ( argc == 1 ) {
    ui = new G4UIExecutive(argc, argv);
  }

  // Choose the Random engine
  G4Random::setTheEngine(new CLHEP::RanecuEngine);
  


  //setting thread num


  // Construct the default run manager
#ifdef G4MULTITHREADED
  G4MTRunManager* runManager = new G4MTRunManager;
  runManager->SetNumberOfThreads(1);
#else
  G4RunManager* runManager = new G4RunManager;
#endif

  // Set mandatory initialization classes
  //
  


  // Detector construction
  runManager->SetUserInitialization(new GtkDetectorConstruction());

  // Physics list
  G4VModularPhysicsList* physicsList = new LBE;
  G4OpticalPhysics* opticalPhysics = new G4OpticalPhysics();
  physicsList->RegisterPhysics(opticalPhysics);
  physicsList->SetVerboseLevel(0);
  runManager->SetUserInitialization(physicsList);
  
  // User action initialization
  runManager->SetUserInitialization(new GtkActionInitialization());
  
  // Initialize visualization
  //
  G4VisManager* visManager = new G4VisExecutive;
  // G4VisExecutive can take a verbosity argument - see /vis/verbose guidance.
  // G4VisManager* visManager = new G4VisExecutive("Quiet");
  visManager->Initialize();

  // Get the pointer to the User Interface manager
  G4UImanager* UImanager = G4UImanager::GetUIpointer();

  runManager->SetVerboseLevel(2);
  if(!ui)runManager->Initialize();
  

  if ( ! ui ) { 
    G4String fileName = argv[1];
    G4String command = "/control/execute ";    
    UImanager->ApplyCommand(command+fileName);
  }
  else { 
    // interactive mode
    UImanager->ApplyCommand("/control/execute init_vis.mac");
    UImanager->ApplyCommand("/run/numberOfThreads 1");
    UImanager->ApplyCommand("/control/execute gps.mac");
    ui->SessionStart();
    delete ui;
  }



  delete visManager;
  delete runManager;
}


