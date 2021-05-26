//
// Created by Momme Sherif on 26/05/2021.
//

#include "GUI.hpp"
namespace RestLib
{

    void MainMenu (){
        std::system("cls");
        fort::char_table MainMenu;
        MainMenu.set_border_style(FT_DOUBLE2_STYLE);
        MainMenu << fort::header
        << "Welcome in the Restaurant " << fort::endr;
        MainMenu.column(1).set_cell_text_align(fort::text_align::center);

        std::cout << MainMenu.to_string() << std::endl;
    }

}