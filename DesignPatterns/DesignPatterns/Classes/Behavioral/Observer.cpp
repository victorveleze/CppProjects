#include "Observer.h"
#include <iostream>
#include <algorithm>


std::shared_ptr<IObserver> IObserver::getSharedPtr()
{
    return shared_from_this();
}

void YoutubeSubscriber::update()
{
    std::cout << "Last video added in: " << youtubeChannel_->getChannelName() << "\n";
    std::cout << "Video name: " << youtubeChannel_->getLastVideoAddedName() << "\n";
}

void YoutubeSubscriber::subscribe(std::shared_ptr<YoutubeChannel> youtubeChannel)
{
    youtubeChannel_ = youtubeChannel;
    youtubeChannel_->addSubscriber(getSharedPtr());
}

YoutubeChannel::YoutubeChannel(const std::string&& name) noexcept
    : channelName_{ name }
{}

void YoutubeChannel::addSubscriber(std::shared_ptr<IObserver> subscriber)
{
    subscribers_.push_back(subscriber);
}

void YoutubeChannel::removeSubscriber(const std::shared_ptr<IObserver> subscriber)
{
    const auto subscriberIterator = std::find(subscribers_.begin(), subscribers_.end(), subscriber);
    if(subscriberIterator != subscribers_.end())
    {
        subscribers_.erase(subscriberIterator);
    }
}

void YoutubeChannel::addVideo(const std::string& videoName)
{
    lastVideoAdded_ = videoName;
    std::cout << "Video added: \t" << videoName << "\n";
    notify();
}

const std::string& YoutubeChannel::getLastVideoAddedName() const
{
    return lastVideoAdded_;
}

const std::string& YoutubeChannel::getChannelName() const
{
    return channelName_;
}

void YoutubeChannel::notify()
{
    std::for_each(subscribers_.begin(), subscribers_.end(), [](std::shared_ptr<IObserver> subscriber){
        subscriber->update();
    });
}
