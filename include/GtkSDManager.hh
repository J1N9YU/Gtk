#ifndef GtkSDManager_hh
#define GtkSDManager_hh 1

#include "G4SDManager.hh"
#include "G4VSensitiveDetector.hh"
#include "G4tgbVolumeMgr.hh"
#include <string>

using namespace std;

class GtkSDManager{
    public:

    GtkSDManager();
    ~GtkSDManager();

    void RegisterSD();
    void COnstructSD();
    void AssociateSDtoLogicVolume(G4VSensitiveDetector* sd, string LVname, string SDname );

    static GtkSDManager* GetInstance();

    protected:

    static GtkSDManager* instance;



};


















#endif