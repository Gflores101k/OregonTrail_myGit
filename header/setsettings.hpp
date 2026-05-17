#pragma once
#ifndef SETSETTINGS_HPP
#define SETSETTINGS_HPP
#include <string>

enum class RationSetting{
    Filling,
    Meager,
    BareBones,
};

enum class PaceSetting{
    Steady,
    Strenuous,
    Grueling,
};

class SetSettings{
    private:
    RationSetting rations;
    PaceSetting pace;
    public:
    SetSettings();

    void setRations(RationSetting newRations);
    void setPace(PaceSetting newPace);

    RationSetting getRations() const;
    PaceSetting getPace() const;

    int getRationFoodUse() const;
    int getRationDamage() const;

    int getPaceDistance() const;
    int getPaceDamage() const;

    std::string getRationName() const;
    std::string getPaceName() const;
     
};



//
#endif 