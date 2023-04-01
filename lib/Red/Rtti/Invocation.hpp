#pragma once

#include "Resolving.hpp"

namespace Red
{
namespace Detail
{
inline CBaseFunction* GetFunction(CClass* aType, CName aName)
{
    for (auto func : aType->funcs)
    {
        if (func->shortName == aName || func->fullName == aName)
        {
            return func;
        }
    }

    if (aType->parent)
    {
        return GetFunction(aType->parent, aName);
    }

    return nullptr;
}

inline CBaseFunction* GetStaticFunction(CClass* aType, CName aName)
{
    for (auto func : aType->staticFuncs)
    {
        if (func->shortName == aName || func->fullName == aName)
        {
            return func;
        }
    }

    if (aType->parent)
    {
        return GetStaticFunction(aType->parent, aName);
    }

    return nullptr;
}

template<typename... Args>
inline bool CallFunction(CBaseFunction* aFunc, IScriptable* aContext, Args&&... aArgs)
{
    if (!aFunc)
        return false;

    const auto combinedArgCount = aFunc->params.size + (aFunc->returnType ? 1 : 0);

    if (combinedArgCount != sizeof...(Args))
        return false;

    if (!aFunc->flags.isStatic)
    {
        const auto& func = reinterpret_cast<Red::CClassFunction*>(aFunc);

        if (!aContext || !aContext->GetType()->IsA(func->parent))
            return false;
    }

    CStack stack(aContext);
    StackArgs_t args;

    if (combinedArgCount > 0)
    {
        ((args.emplace_back(Red::ResolveType<Args>(), &aArgs)), ...);

        if (aFunc->returnType)
        {
            stack.result = args.data();

            if (stack.result->type != aFunc->returnType->type)
                return false;

            if (aFunc->params.size)
            {
                stack.args = args.data() + 1;
            }
        }
        else
        {
            stack.args = args.data();
        }

        if (aFunc->params.size)
        {
            stack.argsCount = aFunc->params.size;

            for (uint32_t i = 0; i < aFunc->params.size; ++i)
            {
                if (stack.args[i].type != aFunc->params[i]->type)
                    return false;
            }
        }
    }

    return aFunc->Execute(&stack);
}
}

template<typename... Args>
inline bool CallVirtual(IScriptable* aContext, CClass* aType, CName aFunc, Args&&... aArgs)
{
    return Detail::CallFunction(Detail::GetFunction(aType, aFunc), aContext, std::forward<Args>(aArgs)...);
}

template<typename... Args>
inline bool CallVirtual(IScriptable* aContext, CName aFunc, Args&&... aArgs)
{
    return CallVirtual(aContext, aContext->GetType(), aFunc, std::forward<Args>(aArgs)...);
}

template<typename... Args>
inline bool CallStatic(CClass* aType, CName aFunc, Args&&... aArgs)
{
    return Detail::CallFunction(Detail::GetStaticFunction(aType, aFunc), nullptr, std::forward<Args>(aArgs)...);
}

template<typename... Args>
inline bool CallGlobal(CName aFunc, Args&&... aArgs)
{
    return Detail::CallFunction(Red::CRTTISystem::Get()->GetFunction(aFunc), nullptr, std::forward<Args>(aArgs)...);
}
}
