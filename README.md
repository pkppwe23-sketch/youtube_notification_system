# YouTube Notification System

A small C++ project demonstrating the **Observer Design Pattern** using a YouTube-style channel and its subscribers.

## Overview

When a channel uploads a new video, all users subscribed to that channel receive a notification. A user can unsubscribe at any time and will no longer receive notifications for later uploads.

## Design Pattern: Observer

The Observer Pattern defines a one-to-many relationship between a subject and its observers. When the subject changes state, it notifies its registered observers.

### Main classes

- **`ISubscriber`** — abstract observer interface. Every subscriber implements `update()`.
- **`IChannel`** — abstract channel interface that declares `subscribe()`, `unsubscribe()`, and `notifySubscribers()`.
- **`Channel`** — concrete subject. Stores subscribers, tracks the latest uploaded video, and notifies subscribers when a video is uploaded.
- **`Subscriber`** — concrete observer. Receives notifications from its channel and displays the latest video title.

## How it works

1. Create a channel named `JaiHo`.
2. Create two subscribers, Ram and Sita.
3. Both subscribe to the channel.
4. The channel uploads **Ramayan** and notifies both subscribers.
5. Ram unsubscribes.
6. The channel uploads **Mithila** and only Sita receives the notification.

## Example output

```text
[JaiHo uploaded: "Ramayan"]
Hey Ram, Check out our new video: Ramayan
Hey Sita, Check out our new video: Ramayan

[JaiHo uploaded: "Mithila"]
Hey Sita, Check out our new video: Mithila
```

## Build and run

You need a C++ compiler that supports **C++11 or later**.

### Compile

```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o youtube_notification_system
```

### Run

On Linux or macOS:

```bash
./youtube_notification_system
```

On Windows PowerShell:

```powershell
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o youtube_notification_system.exe
.\youtube_notification_system.exe
```

## Concepts demonstrated

- Observer Design Pattern
- Abstract interfaces and pure virtual functions
- Inheritance and runtime polymorphism
- `vector` for storing subscribers
- `subscribe()` and `unsubscribe()` operations
- Notifying multiple observers when a channel's state changes
- Virtual destructors for interface classes

## Notes

- Duplicate subscriptions are ignored.
- Null subscriber pointers are ignored when subscribing.
- This is an educational console example; it does not connect to YouTube or send real notifications.
- The channel keeps non-owning subscriber pointers, so subscribers should remain alive while registered. In this example, local object lifetimes are arranged safely.

## Repository

[youtube_notification_system](https://github.com/pkppwe23-sketch/youtube_notification_system)
