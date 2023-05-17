#include "TrainedNinja.hpp"

TrainedNinja::TrainedNinja(string name,Point location)
    :Ninja(name,location,120,12)
{
    
}

 TrainedNinja* TrainedNinja::clone(const TrainedNinja* copyFigure) 
 {
    return new TrainedNinja(*this);
 }