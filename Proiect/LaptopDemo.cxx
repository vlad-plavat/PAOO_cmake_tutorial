#include <iostream>
#include <string>
#include "Laptop.h"

int main(int argc, char* argv[])
{
  Laptop hp(2019, (char*)"HP", (char*)"Some description for the HP laptop that has to be dynamically allocated.");
  Laptop msi(2020, (char*)"MSI", (char*)"Some description for the MSI laptop that has to be dynamically allocated.");
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
  
  return 0;
}
