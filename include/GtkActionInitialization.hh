
#ifndef GtkActionInitialization_h
#define GtkActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

/// Action initialization class.

class GtkActionInitialization : public G4VUserActionInitialization
{
  public:
    GtkActionInitialization();
    virtual ~GtkActionInitialization();

    virtual void BuildForMaster() const;
    virtual void Build() const;
};


#endif

    
