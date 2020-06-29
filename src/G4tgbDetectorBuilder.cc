#include "GtktgbDetectorBuilder.hh"
#include "G4tgbDetectorBuilder.hh"

GtktgbDetectorBuilder::GtktgbDetectorBuilder():G4tgbDetectorBuilder(){

}

GtktgbDetectorBuilder::~GtktgbDetectorBuilder(){

}


const G4tgrVolume* GtktgbDetectorBuilder::ReadDetector(){
    GtktgrLineProcessor* theProcessor = new GtktgrLineProcessor;
    G4tgrFileReader* fileReader = G4tgrFileReader::GetInstance();
    fileReader->SetLineProcessor(theProcessor);
    fileReader->ReadFiles();

    G4tgrVolumeMgr* tgrVolMgr = G4tgrVolumeMgr::GetInstance();
    const G4tgrVolume* tgrVolTop = tgrVolMgr->GetTopVolume();
    
    return tgrVolTop;

}

/*
G4VPhysicalVolume* GtktgbDetectorBuilder::ConstructDetector(const G4tgrVolume* tgrVolTop){
    G4VPhysicalVolume* topV = G4tgbDetectorBuilder()

}
*/


