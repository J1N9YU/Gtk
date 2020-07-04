#ifndef GtktgrLineProcessor_hh
#define GtktgrLineProcessor_hh 1

#include "GtkMaterials.hh"
#include "G4tgrLineProcessor.hh"

class G4tgrLineProcessor;

class GtktgrLineProcessor:public G4tgrLineProcessor{
public:

    GtktgrLineProcessor();
    ~GtktgrLineProcessor();

    G4bool ProcessLine(const std::vector<G4String>& wl);

};

#endif