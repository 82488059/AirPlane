#pragma once
/////////////////////////////////////////////////////////////////////
// 工程: 
// 作者: zt
// 描述: 单例
// 主要函数：
// 日期: 2013.03.20
// 版本: 1.0
// 修改:
/////////////////////////////////////////////////////////////////////
template<class T>
class SingletonT
{
public:
    ~SingletonT(){}

    static T* GetInstance()
    {
        static T t;
        return &t;
    }

private:
    SingletonT(){}

};

template<class T>
class SingletonManager
{
public:
    ~SingletonManager(){}

    static T* GetInstance()
    {
        if (NULL == __instance)
        {
            __instance = new T;
        }
        return __instance;
    }
    static bool Init()
    {
        return __instance && __instance->Init();
    }
    static bool Release()
    {
        bool R =  __instance && __instance->Release();
        delete __instance;
        __instance = NULL;
        return R;
    }
private:
    SingletonManager(){}
    static T* __instance;
};

template<class T>
T* SingletonManager<T>::__instance = NULL;