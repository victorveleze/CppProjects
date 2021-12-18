#include "Builder.h"
#include <algorithm>
#include <iostream>

Character::Character(const SkeletonType skeletonType) noexcept
    : skeletonType_(skeletonType)
{}

void Character::addArmour(const part& armour)
{
    parts_.push_back(armour);
}

void Character::addHelmet(const part& helmet)
{
    parts_.push_back(helmet);
}

void Character::addWeapon(const part& weapon)
{
    parts_.push_back(weapon);
}

void Character::addSpecialPower(const part& power)
{
    parts_.push_back(power);
}

void Character::printParts() const
{
    std::for_each(parts_.begin(), parts_.end(), [](const part& part){
        std::cout << part << "\t";
    });
    std::cout << "\n";
}

std::shared_ptr<Character> CharacterBuilder::getCharacter() const
{
    return character_;
}

ZombieBuilder::ZombieBuilder() noexcept
{
    character_ = std::make_shared<Character>(Character::SkeletonType::ZOMBIE);
}

void ZombieBuilder::produceArmour(const CharacterBuilder::part& armour) const
{
    character_->addArmour(armour);
}

void ZombieBuilder::produceHelmet(const CharacterBuilder::part& helmet) const
{
    character_->addHelmet(helmet);
}

void ZombieBuilder::produceWeapon(const CharacterBuilder::part& weapon) const
{
    character_->addWeapon(weapon);
}

MummyBuilder::MummyBuilder() noexcept
{
    character_ = std::make_shared<Character>(Character::SkeletonType::MUMMY);
}

void MummyBuilder::produceArmour(const CharacterBuilder::part& armour) const
{
    character_->addArmour(armour);
}

void MummyBuilder::produceHelmet(const CharacterBuilder::part& helmet) const
{
    character_->addArmour(helmet);
}

void MummyBuilder::produceWeapon(const CharacterBuilder::part& weapon) const 
{
    character_->addWeapon(weapon);
}

void MummyBuilder::produceSpecialPower(const CharacterBuilder::part& power) const
{
    character_->addSpecialPower(power);
}

BuildDirector::BuildDirector(std::shared_ptr<CharacterBuilder>&& builder) noexcept
    : builder_(std::forward<std::shared_ptr<CharacterBuilder>>(builder))
{}

void BuildDirector::setBuilder(std::shared_ptr<CharacterBuilder>&& builder)
{
    builder_ = builder;
}

void BuildDirector::buildZombie() const
{
    const CharacterBuilder::part armour{ "Zombie bandage" };
    const CharacterBuilder::part helmet{ "Zombie helmet" };
    const CharacterBuilder::part weapon{ "Zombie axe" };

    builder_->produceArmour(armour);
    builder_->produceHelmet(helmet);
    builder_->produceWeapon(weapon);
}

void BuildDirector::buildMummy() const
{
    const CharacterBuilder::part armour{ "Mummy bandage" };
    const CharacterBuilder::part helmet{ "Mummy helmet" };
    const CharacterBuilder::part weapon{ "Mummy torch" };
    const CharacterBuilder::part power{ "Mummy multiplication" };

    builder_->produceArmour(armour);
    builder_->produceHelmet(helmet);
    builder_->produceWeapon(weapon);
    builder_->produceSpecialPower(power);
}

std::shared_ptr<Character> BuildDirector::getCharacter() const
{
    return builder_->getCharacter();
}
