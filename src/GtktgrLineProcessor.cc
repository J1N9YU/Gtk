#include "GtktgrLineProcessor.hh"

using namespace  std;

GtktgrLineProcessor::GtktgrLineProcessor():G4tgrLineProcessor(){

}

GtktgrLineProcessor::~GtktgrLineProcessor(){
    
}

G4bool GtktgrLineProcessor::ProcessLine(const std::vector<G4String> wl){
    cout<<"process line starts"<<endl;
    G4bool iret = G4tgrLineProcessor::ProcessLine(wl);
    cout<<"default processing finish"<<endl;

    G4String wl0 = wl[0];
    for(size_t ii = 0;ii<wl0.length();ii++){
        wl0[ii] = toupper(wl0[ii]);
    }

    if(!iret){

        if(wl0 == ":PROPERTY"){
            cout<<"??"<<wl0<<endl;
            auto iter = wl.begin()+1;
            vector<G4String> wlc;
            for(;iter!=wl.end();iter++){
                wlc.push_back(*iter);
            }
            wlc.erase(wlc.begin());
            //Call functions in Gtkmaterial

            iret = 1;
            cout<<"LineProcessor: ";
            for(auto w:wlc)cout<<"\t"<<w;
            cout<<endl;
        }
    }

}