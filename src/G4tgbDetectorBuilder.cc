#include "GtktgbDetectorBuilder.hh"
#include "G4tgbDetectorBuilder.hh"

using namespace std;

GtktgbDetectorBuilder::GtktgbDetectorBuilder():G4tgbDetectorBuilder(){

}

GtktgbDetectorBuilder::~GtktgbDetectorBuilder(){

}


const G4tgrVolume* GtktgbDetectorBuilder::ReadDetector(){
    GtktgrLineProcessor* theProcessor = new GtktgrLineProcessor;
    G4tgrFileReader* fileReader = G4tgrFileReader::GetInstance();
    cout<<"setting custom line processor"<<endl;
    fileReader->SetLineProcessor(theProcessor);
    fileReader->ReadFiles();

    G4tgrVolumeMgr* tgrVolMgr = G4tgrVolumeMgr::GetInstance();
    const G4tgrVolume* tgrVolTop = tgrVolMgr->GetTopVolume();
    
    return tgrVolTop;

}


G4VPhysicalVolume* GtktgbDetectorBuilder::ConstructDetector(const G4tgrVolume* tgrVolTop){
    cout<<"ConscturctDetector"<<endl;
    G4VPhysicalVolume* topPV = G4tgbDetectorBuilder::ConstructDetector( tgrVolTop );
    return topPV;
}



