//
// Created by Tobia on 19.05.2021.
//

#ifndef MAIN_CPP_ABSTRACTDISH_HPP
#define MAIN_CPP_ABSTRACTDISH_HPP


#include <string>
#include <vector>
#include <memory>

namespace RestLib {

    class AbstractDish {
    public:
        //AbstractDish() = default;

        explicit AbstractDish(const std::string &&_dishName);

        virtual ~AbstractDish();

    public:
        virtual void Prepare() = 0;

        std::string GetDishName() const;

        std::vector<std::string> GetIngredients() const;

        int GetNumberIngredients() const;

    protected:
        void AddIngredients(const std::string& _ingredient);

    private:
        std::vector<std::string> vIngredients;
        std::string dishName;

    };
    using  DishType = std::unique_ptr<AbstractDish>;
}

#endif //MAIN_CPP_ABSTRACTDISH_HPP
