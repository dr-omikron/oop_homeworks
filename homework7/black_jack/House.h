
#include "GenericPlayer.h"

class House : public GenericPlayer
{
public:
    House(const std::string& name = "# ������");
    bool isHitting() const override;
    void flipFirstCard();
};
