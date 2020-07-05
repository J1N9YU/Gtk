#ifndef GtkSDtFactory_hh
#define GtkSDtFactory_hh 1


#include "GtkSDt.hh"
#include "G4SDManager.hh"
#include <vector>

class GtkSDt;
class G4SDManager;

using namespace std;



class GtkSDtFactory{
    public:

    GtkSDtFactory();
    ~GtkSDtFactory();

    void BuildG4SD();
    void AddSDt();

    protected:
    
    vector<GtkSDt> theSDt;

    
};


#endif