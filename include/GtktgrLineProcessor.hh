#include "G4tgrLineProcessor.hh"


class GtktgrLineProcessor:public G4tgrLineProcessor{
public:

    GtktgrLineProcessor();
    ~GtktgrLineProcessor();

    G4bool ProcessLine(const std::vector<G4String>& wl);

};