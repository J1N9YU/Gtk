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

    //void RegisterSD();
    //void ConstructSD();
    void AssignSDtoLogicVolume(G4VSensitiveDetector* sd, string LVname, string SDname );

    static GtkSDManager* GetInstance();

    protected:


    private:
    static GtkSDManager* instance;



};


















#endif