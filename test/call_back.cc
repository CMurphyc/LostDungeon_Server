//
// Created by jackyan on 2019/5/21.
//

#include <bits/stdc++.h>

using namespace std;

class BaseMessage{  // something like Message* in Proto.
public:
    int x;
    virtual ~BaseMessage() = default;  /*source type is not polymorphic if we don't have the line*/
};

class DeriveMessage1 : public BaseMessage{
public:
    int d1;
};

class DeriveMessage2 : public BaseMessage{
public:
    int d2;
};

void hh(const std::shared_ptr<DeriveMessage1>& sp_d1){
    printf("D1\n");
}
void gg(const std::shared_ptr<DeriveMessage2>& sp_d1){
    printf("D2");
}


template<typename T>
inline T* get_pointer(const std::shared_ptr<T>& ptr)
{
    return ptr.get();
}

template<typename T>
inline T* get_pointer(const std::unique_ptr<T>& ptr)
{
    return ptr.get();
}

template<typename To, typename From>
inline ::std::shared_ptr<To> down_pointer_cast(const ::std::shared_ptr<From>& f) {
//    if (false) {
//        implicit_cast<From *, To *>(0);
//    }
#ifndef NDEBUG
    assert(f == NULL || dynamic_cast<To*>(get_pointer(f)) != NULL);
#endif
    return ::std::static_pointer_cast<To>(f);
}



/**
 * callback class for each callback function(class/normal function)
 * */
class Callback
{
public:
    virtual ~Callback() = default;
    virtual void onMessage(const std::shared_ptr<BaseMessage>& message) const = 0;
};

template <typename T>
class CallbackT : public Callback
{
    static_assert(std::is_base_of<BaseMessage, T>::value,
                  "T must be derived from Base");
public:
    typedef std::function<void (const std::shared_ptr<T>& message)> MessageTCallback;

    CallbackT(const MessageTCallback& callback)
            : callback_(callback) {}

    void onMessage(const std::shared_ptr<BaseMessage>& baseMessage) const override
    {
        /// const char* message, int32_t len.
        /// ParseFromArray to T.

        std::shared_ptr<T> concrete = down_pointer_cast<T>(baseMessage);
        assert(concrete != NULL);
        callback_(concrete);
    }

private:
    MessageTCallback callback_;
};


/**
 * msgId->callback (CallBack) controller
 *                  CallBackT inherit CallBack, and CallBackT<T> store callback related with T.
 * dispatcher
 * */

class MessageDispatcher
{
public:
    typedef std::function<void (const std::shared_ptr<BaseMessage>& message)> MessageCallback;

    void onMessage(int32_t msgId, const std::shared_ptr<BaseMessage>& message) const
    {
        CallbackMap::const_iterator it = callbacks_.find(msgId);
        if (it != callbacks_.end())
            it->second->onMessage(message);
        else
            printf("No such MsgHandler");
    }

    template<typename T>
    void registerMessageCallback(int32_t msgId, const typename CallbackT<T>::MessageTCallback& callback)
    {
        std::shared_ptr<CallbackT<T> > pd(new CallbackT<T>(callback));
        callbacks_[msgId] = pd;
    }

private:
    typedef std::map<int32_t, std::shared_ptr<Callback> > CallbackMap;

    CallbackMap callbacks_;
};



MessageDispatcher dispatcher;

int main(){
    // usage of template, Polymorphism
    // Polymorphism:
    //      CallBack, but Derived class is depend on user. may product many CallBack(as many as function) by user using template

    dispatcher.registerMessageCallback<DeriveMessage1>(1,hh);
    dispatcher.registerMessageCallback<DeriveMessage2>(2,gg);

    std::shared_ptr<DeriveMessage1> g1(new DeriveMessage1());
    std::shared_ptr<DeriveMessage2> g2(new DeriveMessage2());

    dispatcher.onMessage(1, g1);
    dispatcher.onMessage(2, g2);

    return 0;
}