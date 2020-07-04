#include "GtktgrLineProcessor.hh"

using namespace  std;

GtktgrLineProcessor::GtktgrLineProcessor():G4tgrLineProcessor(){

}

GtktgrLineProcessor::~GtktgrLineProcessor(){
    
}

G4bool GtktgrLineProcessor::ProcessLine(const std::vector<G4String>& wl){

    G4bool iret = G4tgrLineProcessor::ProcessLine(wl);

    G4String wl0 = wl[0];
    for(size_t ii = 0;ii<wl0.length();ii++){
        wl0[ii] = toupper(wl0[ii]);
    }

    if(!iret){

        if(wl0 == ":PROPERTY"){
            auto iter = wl.begin()+1;
            vector<G4String> wlc;
            for(;iter!=wl.end();iter++){
                wlc.push_back(*iter);
            }

            //checking
            if(wlc.size()!=3){
                cout<<"Invalid parameter number, it should be 3 parameters"<<endl;
                return 0;
            }

            //Call functions in Gtkmaterial
            GtkMaterials::GetInstance()->RegisterProperty(wlc[0],wlc[1],wlc[2]);
            
            iret = 1;
        }
    }

    return iret;

}