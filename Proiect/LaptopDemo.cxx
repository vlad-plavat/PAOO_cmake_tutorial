#include <iostream>
#include <string>
#include "Device.h"
#include "Laptop.h"
#include "GamingLaptop.h"
#include "WaffleMaker.h"

using namespace WaffleMaker_nmsp;
using namespace Laptop_nmsp;
using namespace GamingLaptop_nmsp;
using namespace Device_nmsp;

int main(int argc, char* argv[])
{
  Laptop hp(2019, (char*)"HP", (char*)"Some description for the HP laptop that has to be dynamically allocated.");
  Laptop msi(2020, (char*)"DELL", (char*)"Some description for the DELL laptop that has to be dynamically allocated.");
  Laptop sony(2021, (char*)"SONY", (char*)"Some description for the SONY laptop that has to be dynamically allocated.");
  
  hp.addService((char*)"23/10/2023", (char*)"Change cooling fans.");
  hp.addService((char*)"23/07/2022", (char*)"Change USB ports.");
  
  hp.show();
  sony.show();
  msi.show();
  
  Laptop hp2 = hp;
  hp2.changeYear(2010);
  hp2.addService((char*)"24/10/2023", (char*)"Change trackpad.");
  hp2.solveService();
  hp2.show();
  hp.show();
  
  Laptop msi_moved(std::move(msi));
  msi_moved.show();
  msi.show();
  
  Laptop msi_moved2(Laptop(2001, (char*)"HP", (char*)"Some description for the HP laptop that has to exist."));
  
  std::cout<<"------- ------- ------- ------- ------- ------- ------- ------- "<<std::endl;
  
  Laptop msi_asg(2019, (char*)"ACER", (char*)"Some description for the ACER laptop that has to be dynamically allocated.");
  msi_asg.show();
  msi_asg = hp;
  msi_asg.show();
  msi_asg = std::move(sony);
  msi_asg.show();
  
  WaffleMaker wfl;
  wfl.setWaffles(4);
  wfl.turnOn();
  std::cout<<"The waffle maker is using "<<wfl.getPowerConsumption()<<" watts."<<std::endl;
  
  std::cout<<"------- ------- ------- ------- ------- ------- ------- ------- "<<std::endl;
  
  Laptop lap_t(2019, (char*)"LENOVO", (char*)"Some description for the LENOVO laptop that has to be dynamically allocated.");
  Device& lap = lap_t;
  lap.show();
  lap_t.show();
  
  GamingLaptop lapg_t(2022, (char*)"LENOVO", (char*)"Some description for the LENOVO laptop that has to be dynamically allocated.", (char*)"GTX1080");
  Device& lapg = lapg_t;
  Laptop& lapg_l = lapg_t;
  
  lapg.show();
  lapg_t.show();
  lapg_t.playGame((char*)"Fallout 4");
  lapg_l.playGame((char*)"Fallout 4");
  
  return 0;
}
