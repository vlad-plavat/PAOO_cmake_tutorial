#include <iostream>
#include <string>
#include "Laptop.h"

int main(int argc, char* argv[])
{
  Laptop hp(2019, "HP", "Some description for the HP laptop that has to be dynamically allocated.");
  Laptop msi(2020, "MSI", "Some description for the MSI laptop that has to be dynamically allocated.");
  Laptop sony(2021, "SONY", "Some description for the SONY laptop that has to be dynamically allocated.");
  
  hp.addService("23/10/2023", "Change cooling fans.");
  hp.addService("23/07/2022", "Change USB ports.");
  
  hp.show();
  sony.show();
  msi.show();
  
  Laptop hp2 = hp;
  hp2.changeYear(2010);
  hp2.addService("24/10/2023", "Change trackpad.");
  hp2.solveService();
  hp2.show();
  hp.show();
  
  Laptop msi_moved(std::move(msi));
  msi_moved.show();
  msi.show();
  
  Laptop msi_moved2(Laptop(2001, "HP", "Some description for the HP laptop that has to BLAH BLAH BLAH."));
  //why is the copy constructor not called?
  
  return 0;
}
