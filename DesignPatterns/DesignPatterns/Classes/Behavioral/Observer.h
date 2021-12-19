#pragma once
#include <vector>
#include <string>
#include <memory>

class YoutubeChannel;

class IObserver : public std::enable_shared_from_this<IObserver>
{
public:
    virtual ~IObserver() = default;
    virtual void update() = 0;
    virtual std::shared_ptr<IObserver> getSharedPtr() final;
};

class YoutubeSubscriber : public IObserver
{
public:
    void update() override;
    void subscribe(std::shared_ptr<YoutubeChannel> youtubeChannel);

private:
    std::shared_ptr<YoutubeChannel> youtubeChannel_ = nullptr;
};

class YoutubeChannel
{
public:
    explicit YoutubeChannel(const std::string&& name) noexcept;
    void addSubscriber(std::shared_ptr<IObserver> subscriber);
    void removeSubscriber(const std::shared_ptr<IObserver> subscriber);
    void addVideo(const std::string& videoName);
    const std::string& getLastVideoAddedName() const;
    const std::string& getChannelName() const;

private:
    void notify();
    std::string channelName_;
    std::string lastVideoAdded_;

    std::vector<std::shared_ptr<IObserver>> subscribers_;
};

/*  Observer example:
    const std::shared_ptr<YoutubeChannel> channel{ std::make_shared<YoutubeChannel>("Se Regalan Dudas")};
    const std::shared_ptr<YoutubeSubscriber> subscriber1{ std::make_shared<YoutubeSubscriber>() };
    const std::shared_ptr<YoutubeSubscriber> subscriber2{ std::make_shared<YoutubeSubscriber>() };

    subscriber1->subscribe(channel);
    subscriber2->subscribe(channel);

    channel->addVideo("Love");
 */
