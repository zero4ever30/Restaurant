//
// Created by Momme Sherif on 20/05/2021.
//

#ifndef FINAL_PROJECT_ITEM_HPP
#define FINAL_PROJECT_ITEM_HPP

#include <string>

namespace RestLib
{

    class item {
    public:

        explicit item(std::string, double);

        std::string  get_item_name (item);
        double get_item_amount (item);
    private:
        std::string item_name;
        double item_amount;
    };


}


#endif //FINAL_PROJECT_ITEM_HPP
