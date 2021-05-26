# Alle Quelldateien sammeln
file(GLOB SourceFiles *.*pp)

# Und zur Bibliothek hinzufügen
add_library(RestLib ${SourceFiles} DrinksBar.cpp DrinksBar.hpp AbstractDish.cpp AbstractDish.hpp Customer.cpp Customer.hpp Kitchen.cpp Kitchen.hpp Dishes.cpp Dishes.hpp Restaurant.cpp Restaurant.hpp item.cpp item.hpp order.cpp order.hpp GUI.cpp GUI.hpp)



# Disable building tests and examples in libfort project
set(FORT_ENABLE_TESTING OFF CACHE INTERNAL "")

add_subdirectory(third-party/libfort)
target_link_libraries(RestLib PRIVATE fort)