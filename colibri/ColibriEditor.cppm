// Created by cabo_ on 12/28/2023.
//

export module ColibriEditor;

import Corbeau;

class ColibriEditor final : public corbeau::Application {
public:
    ColibriEditor() = default;
    ~ColibriEditor() override = default;



private:

};

auto createApplication()->corbeau::Application*
{
    return new ColibriEditor();
}