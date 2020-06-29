#ifndef GtktgbDetectorBuilder_hh
#define GtktgbDetectorBuilder_hh

#include "G4tgbDetectorBuilder.hh"
#include "G4tgbVolume.hh"
#include "GtktgrLineProcessor.hh"
#include "G4tgrFileReader.hh"
#include "G4tgrVolumeMgr.hh"


//class G4tgbDetectorBuilder  ;

class GtktgbDetectorBuilder :public  G4tgbDetectorBuilder {

public:

    GtktgbDetectorBuilder();
    ~GtktgbDetectorBuilder();
;
protected:

    const G4tgrVolume* ReadDetector();

};


#endif
