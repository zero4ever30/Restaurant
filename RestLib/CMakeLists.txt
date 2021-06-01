# Alle Quelldateien sammeln
file(GLOB SourceFiles *.*pp)

# Und zur Bibliothek hinzufügen
add_library(RestLib ${SourceFiles} DrinksBar.cpp DrinksBar.hpp AbstractDish.cpp AbstractDish.hpp Customer.cpp Customer.hpp Kitchen.cpp Kitchen.hpp Dishes.cpp Dishes.hpp Restaurant.cpp Restaurant.hpp item.cpp item.hpp order.cpp order.hpp Ingredient.cpp Ingredient.hpp Ingredients.cpp Ingredients.hpp Finance.cpp Finance.hpp)
