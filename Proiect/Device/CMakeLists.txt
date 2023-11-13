add_library(Laptop STATIC lib/Laptop.cxx lib/GamingLaptop.cxx lib/WaffleMaker.cxx)

target_include_directories(Laptop PUBLIC "include/")
