#ifndef GtkSDt_hh
#define GtkSDt_hh 1

#include <string>

using namespace std;

class GtkSDt{
    public:

    GtkSDt();
    ~GtkSDt();

    inline void SetNameOfSD(string n){nameOfSD=n;}
    inline void SetNnameOfLogicVol(string n){nameOfLoigcVol=n;}
    inline void SetTypeOfSD(string n){typeOfSD=n;}

    inline string GetNameOfSD(){return nameOfSD;}
    inline string GetNameOfLogicVol(){return nameOfLoigcVol;}
    inline string GetTypeOfSD(){return typeOfSD;}

 
    protected:

    string nameOfSD;
    string nameOfLoigcVol;
    string typeOfSD;


};

#endif