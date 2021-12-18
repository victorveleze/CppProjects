#pragma once
#include <memory>
#include <vector>
#include <string>

class Character//Final product 
{
    using part = std::string;
public:
    enum class SkeletonType
    {
        ZOMBIE,
        MUMMY
    };

    explicit Character(const SkeletonType skeletonType) noexcept;
    void addArmour(const part& armour);
    void addHelmet(const part& helmet);
    void addWeapon(const part& weapon);
    void addSpecialPower(const part& power);
    void printParts() const;

private:
    std::vector<part> parts_;
    SkeletonType skeletonType_;
};

class CharacterBuilder
{
public:
    using part = std::string;
    virtual ~CharacterBuilder() = default;
    std::shared_ptr<Character> getCharacter() const;
    virtual void produceArmour(const part& armour) const = 0;
    virtual void produceHelmet(const part& helmet) const = 0;
    virtual void produceWeapon(const part& weapon) const = 0;
    virtual void produceSpecialPower(const part& power) const {}

protected:
    std::shared_ptr<Character> character_;
};

class ZombieBuilder : public CharacterBuilder
{
public:
    ZombieBuilder() noexcept;
    void produceArmour(const CharacterBuilder::part& armour) const override;
    void produceHelmet(const CharacterBuilder::part& helmet) const override;
    void produceWeapon(const CharacterBuilder::part& weapon) const override;
};

class MummyBuilder : public CharacterBuilder
{
public:
    MummyBuilder() noexcept;
    void produceArmour(const CharacterBuilder::part& armour) const override;
    void produceHelmet(const CharacterBuilder::part& helmet) const override;
    void produceWeapon(const CharacterBuilder::part& weapon) const override;
    void produceSpecialPower(const CharacterBuilder::part& power) const override;
};

class BuildDirector
{
public:
    explicit BuildDirector(std::shared_ptr<CharacterBuilder>&& builder) noexcept;
    void setBuilder(std::shared_ptr<CharacterBuilder>&& builder);
    void buildZombie() const;
    void buildMummy() const;
    std::shared_ptr<Character> getCharacter() const;

private:
    std::shared_ptr<CharacterBuilder> builder_;
};


/*  Builder example:
    const auto builder = std::make_shared<ZombieBuilder>();
    BuildDirector director(builder);
    director.buildZombie();
    const std::shared_ptr<Character> zombie = director.getCharacter();

    director.setBuilder(std::make_shared<MummyBuilder>());
    director.buildMummy();
    const std::shared_ptr<Character> mummy = director.getCharacter();

    zombie->printParts();
    mummy->printParts();
 */