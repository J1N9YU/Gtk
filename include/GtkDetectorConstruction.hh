//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// \file GtkDetectorConstruction.hh
/// \brief Definition of the GtkDetectorConstruction class

#ifndef GtkDetectorConstruction_h
#define GtkDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include "GtkMaterials.hh"
#include "GtkPhotonDetHit.hh"
#include "G4Cache.hh"
#include "GtkPhotonDetSD.hh"
#include "G4VisAttributes.hh"
#include <map>
#include "GtkDetectorConstructionMessnger.hh"

using namespace std;

class G4VPhysicalVolume;
class G4LogicalVolume;
class GtkMaterials;
class G4VisAttributes;




/// Detector construction class to define materials and geometry.

class GtkDetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    GtkDetectorConstruction();
    virtual ~GtkDetectorConstruction();

    virtual G4VPhysicalVolume* Construct();
    virtual void ConstructSDandField();

    G4Material* FindMaterial(G4String);


    //building geometry 
    void ConstructSiPD();
    void ConstructFromFile(string fileName);
  
    

  protected:
    GtkMaterials* fMaterials;
    G4Cache<GtkPhotonDetSD*> fmppcSD;

    //Parameters
    G4double photodiodeEdge;
    
    //Vloumes
    G4LogicalVolume* logicWorld;
    G4VPhysicalVolume* SiPD_pv;

    //Messenager
    GtkDetectorConstructionMessenger* fDCM;



};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

