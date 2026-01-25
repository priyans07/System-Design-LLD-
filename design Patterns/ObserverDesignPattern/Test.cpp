// ...existing code...
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Channel; // forward declaration

class ISubscriber {
public:
    virtual void update(Channel* channel) = 0;
    virtual ~ISubscriber() {}
};

class IChannel {
public:
    virtual void subscribe(ISubscriber* sub) = 0;
    virtual void unsubscribe(ISubscriber* sub) = 0;
    virtual void notifySubscribers() = 0;
    virtual ~IChannel() {}
};

class Channel : public IChannel {
private:
    vector<ISubscriber*> subscribers;
    string name;
    string latestVideo;
public:
    Channel(const string& name) : name(name) {}

    void subscribe(ISubscriber* sub) override {
        if (find(subscribers.begin(), subscribers.end(), sub) == subscribers.end()) {
            subscribers.push_back(sub);
        }
    }

    void unsubscribe(ISubscriber* sub) override {
        subscribers.erase(remove(subscribers.begin(), subscribers.end(), sub), subscribers.end());
    }

    void notifySubscribers() override {
        for (auto sub : subscribers) {
            sub->update(this);
        }
    }

    void uploadVideo(const string& videoTitle) {
        latestVideo = videoTitle;
        cout << "New video uploaded: " << latestVideo << endl;
        notifySubscribers();
    }

    string getName() const { return name; }
    string getLatestVideo() const { return latestVideo; }
};

class Subscriber : public ISubscriber {
private:
    string name;
    Channel* channel;
public:
    Subscriber(const string& name, Channel* channel) : name(name), channel(channel) {
        if (channel) channel->subscribe(this);
    }

    void update(Channel* ch) override {
        cout << "Hey " << name << ", new video '" << ch->getLatestVideo()
             << "' uploaded on channel " << ch->getName() << endl;
    }

    void unsubscribe() {
        if (channel) {
            channel->unsubscribe(this);
            channel = nullptr;
        }
    }
};

int main() {
    cout << "Observer Design Pattern Test\n" << endl;

    Channel* tech = new Channel("TechChannel");
    Subscriber* alice = new Subscriber("Alice", tech);
    Subscriber* bob = new Subscriber("Bob", tech);

    tech->uploadVideo("Observer Pattern in C++");
    cout << endl;

    bob->unsubscribe();
    tech->uploadVideo("Factory Pattern Explained");

    delete alice;
    delete bob;
    delete tech;
    return 0;
}
// ...existing code...