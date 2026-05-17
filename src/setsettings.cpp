#include "../header/setsettings.hpp"

SetSettings::SetSettings()
{
    rations = RationSetting::Filling;
    pace = PaceSetting::Steady;
}

void SetSettings::setRations(RationSetting newRations)
{
    rations = newRations;
}
void SetSettings::setPace(PaceSetting newPace)
{
    pace = newPace;
}

RationSetting SetSettings::getRations() const
{
    return rations;
}
PaceSetting SetSettings::getPace() const
{
    return pace;
}
// Food Used Per Person
int SetSettings::getRationFoodUse() const
{
    if (rations == RationSetting::Filling)
    {
        return 6;
    }
    else if (rations == RationSetting::Meager)
    {
        return 4;
    }
    else //(rations == RationSetting::BareBones)
    {
        return 2;
    }
}
int SetSettings::getRationDamage() const
{
    if (rations == RationSetting::Filling)
    {
        return 0;
    }
    else if (rations == RationSetting::Meager)
    {
        return 6;
    }
    else
    { // BareBones
        return 9;
    }
}

int SetSettings::getPaceDistance() const
{
    if (pace == PaceSetting::Steady)
    {
        return 20;
    }
    else if (pace == PaceSetting::Strenuous)
    {
        return 30;
    }
    else
    {
        return 40;
    }
}
int SetSettings::getPaceDamage() const
{
    if (pace == PaceSetting::Steady)
    {
        return 2;
    }
    else if (pace == PaceSetting::Strenuous)
    {
        return 4;
    }
    else
    {
        return 6;
    }
}

std::string SetSettings::getRationName() const
{
    if (rations == RationSetting::Filling)
    {
        return "Filling";
    }
    else if (rations == RationSetting::Meager)
    {
        return "Meager";
    }
    else
    {
        return "Bare Bones";
    }
}
std::string SetSettings::getPaceName() const {

    if (pace == PaceSetting::Steady)
    {
        return "Steady";
    }
    else if (pace == PaceSetting::Strenuous)
    {
        return "Strenuous";
    }
    else
    {
        return "Grueling";
    }
}
