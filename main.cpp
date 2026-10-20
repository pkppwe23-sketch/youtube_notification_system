#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Observer interface: every subscriber must implement update().
class ISubscriber {
public:
    virtual void update() = 0;
    virtual ~ISubscriber() = default;
};

// Subject interface: defines subscription and notification operations.
class IChannel {
public:
    virtual void subscribe(ISubscriber* subscriber) = 0;
    virtual void unsubscribe(ISubscriber* subscriber) = 0;
    virtual void notifySubscribers() = 0;
    virtual ~IChannel() = default;
};

// Concrete subject: a YouTube channel.
class Channel : public IChannel {
private:
    vector<ISubscriber*> subscribers;
    string name;
    string latestVideo;

public:
    explicit Channel(const string& name) : name(name) {}

    void subscribe(ISubscriber* subscriber) override {
        if (subscriber != nullptr &&
            find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end()) {
            subscribers.push_back(subscriber);
        }
    }

    void unsubscribe(ISubscriber* subscriber) override {
        auto it = find(subscribers.begin(), subscribers.end(), subscriber);
        if (it != subscribers.end()) {
            subscribers.erase(it);
        }
    }

    void notifySubscribers() override {
        for (ISubscriber* subscriber : subscribers) {
            if (subscriber != nullptr) {
                subscriber->update();
            }
        }
    }

    void uploadVideo(const string& title) {
        latestVideo = title;
        cout << "\n[" << name << " uploaded: \"" << latestVideo << "\"]\n";
        notifySubscribers();
    }

    string getVideoData() const {
        return "Check out our new video: " + latestVideo + "\n";
    }
};

// Concrete observer: a channel subscriber.
class Subscriber : public ISubscriber {
private:
    string name;
    Channel* channel;

public:
    Subscriber(const string& name, Channel* channel)
        : name(name), channel(channel) {}

    void update() override {
        if (channel != nullptr) {
            cout << "Hey " << name << ", " << channel->getVideoData();
        }
    }
};

int main() {
    Channel channel("JaiHo");

    Subscriber ram("Ram", &channel);
    Subscriber sita("Sita", &channel);

    // Ram and Sita subscribe to the channel.
    channel.subscribe(&ram);
    channel.subscribe(&sita);

    // Both subscribers are notified.
    channel.uploadVideo("Ramayan");

    // Ram unsubscribes, so only Sita is notified next time.
    channel.unsubscribe(&ram);
    channel.uploadVideo("Mithila");

    return 0;
}
