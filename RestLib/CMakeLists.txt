# Alle Quelldateien sammeln
file(GLOB SourceFiles *.*pp)

# Und zur Bibliothek hinzufügen
add_library(RestLib ${SourceFiles})
