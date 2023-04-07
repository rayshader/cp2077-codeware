#pragma once

#include "App/Scripting/ScriptableEnv.hpp"
#include "Core/Foundation/Feature.hpp"
#include "Core/Hooking/HookingAgent.hpp"
#include "Red/GameFramework.hpp"
#include "Red/GameInstance.hpp"
#include "Red/Scripting.hpp"

namespace App
{
class ScriptingService
    : public Core::Feature
    , public Core::HookingAgent
{
protected:
    void OnBootstrap() override;

    static void OnInitializeScripts();
    static void OnInitializeGameInstance();
    static void OnInitializeInstance(Red::IScriptable* aInstance, Red::CClass* aClass, void* aValueHolder);
    static void OnValidateTypeName(bool& aValid, Red::CName aScriptTypeName, Red::CName aNativeTypeName);

    static void GetScriptGameInstance(Red::IScriptable* aContext, Red::CStackFrame* aFrame,
                                      Red::ScriptGameInstance* aRet, Red::CBaseRTTIType* aType);

    inline static Core::Map<Red::CClass*, Red::Handle<ScriptableEnv>> s_environments;
};
}
