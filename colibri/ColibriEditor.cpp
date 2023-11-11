//
// Created by cabo_ on 11/7/2023.
//
#include "Corbeau.h"

class ColibriEditor : public corbeau::Application {
public:
    ColibriEditor() = default;
    ~ColibriEditor() override = default;



private:

};

corbeau::Application* corbeau::createApplication()
{
    return new ColibriEditor();
}
