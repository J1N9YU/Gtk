#ifndef gtkPhysicsList
#define gtkPhysicsList

#include "G4VModularPhysicsList.hh"

class G4ModularPhysicsList;
class G4OpticalPhysics;
class G4DecayPhysics;
class G4EmStandardPhysics;
class G4HadronElasticPhysics;
class G4IonPhysics;
class G4StepLimiterPhysics;

class GtkPhysicsList : public G4VModularPhysicsList{
    public:

    GtkPhysicsList();
    virtual ~GtkPhysicsList();

    void SetCuts();






};




#endif