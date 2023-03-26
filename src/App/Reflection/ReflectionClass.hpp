#pragma once

#include "ReflectionType.hpp"
#include "ReflectionFunc.hpp"
#include "ReflectionProp.hpp"

namespace App
{
struct ReflectionClass : ReflectionType
{
    ReflectionClass() = default;

    explicit ReflectionClass(Red::CClass* aType)
        : ReflectionType(aType)
        , m_class(aType)
    {
    }

    [[nodiscard]] Red::Handle<ReflectionClass> GetParent() const
    {
        if (!m_class->parent)
            return {};

        return Red::MakeHandle<ReflectionClass>(m_class->parent);
    }

    [[nodiscard]] Red::Handle<ReflectionProp> GetProperty(Red::CName aName) const
    {
        auto prop = m_class->propsByName.Get(aName);

        if (!prop)
            return {};

        return Red::MakeHandle<ReflectionProp>(*prop);
    }

    [[nodiscard]] Red::Handle<ReflectionMemberFunc> GetFunction(Red::CName aName) const
    {
        auto func = m_class->funcsByName.Get(aName);

        if (!func)
            return {};

        return Red::MakeHandle<ReflectionMemberFunc>(*func);
    }

    [[nodiscard]] Red::Handle<ReflectionStaticFunc> GetStaticFunction(Red::CName aName) const
    {
        for (const auto& func : m_class->staticFuncs)
        {
            if (func->fullName == aName)
            {
                return Red::MakeHandle<ReflectionStaticFunc>(func);
            }
        }

        return {};
    }

    [[nodiscard]] Red::DynArray<Red::Handle<ReflectionProp>> GetProperties() const
    {
        Red::DynArray<Red::Handle<ReflectionProp>> wrappers;
        // Red::DynArray<Red::CProperty*> props;
        // m_class->GetProperties(props);

        for (const auto& prop : m_class->props)
        {
            wrappers.PushBack(Red::MakeHandle<ReflectionProp>(prop));
        }

        return wrappers;
    }

    [[nodiscard]] Red::DynArray<Red::Handle<ReflectionMemberFunc>> GetFunctions() const
    {
        Red::DynArray<Red::Handle<ReflectionMemberFunc>> wrappers;

        for (const auto& func : m_class->funcs)
        {
            wrappers.PushBack(Red::MakeHandle<ReflectionMemberFunc>(func));
        }

        return wrappers;
    }

    [[nodiscard]] Red::DynArray<Red::Handle<ReflectionStaticFunc>> GetStaticFunctions() const
    {
        Red::DynArray<Red::Handle<ReflectionStaticFunc>> wrappers;

        for (const auto& func : m_class->staticFuncs)
        {
            wrappers.PushBack(Red::MakeHandle<ReflectionStaticFunc>(func));
        }

        return wrappers;
    }

    [[nodiscard]] bool IsNative() const
    {
        return m_class->flags.isNative;
    }

    [[nodiscard]] bool IsAbstract() const
    {
        return m_class->flags.isAbstract;
    }
    
    Red::CClass* m_class;

    RTTI_IMPL_TYPEINFO(App::ReflectionClass);
    RTTI_IMPL_ALLOCATOR(Red::Memory::RTTIAllocator);
};
}

RTTI_DEFINE_CLASS(App::ReflectionClass, {
    RTTI_PARENT(App::ReflectionType);
    RTTI_METHOD(GetParent);
    RTTI_METHOD(GetProperty);
    RTTI_METHOD(GetFunction);
    RTTI_METHOD(GetStaticFunction);
    RTTI_METHOD(GetProperties);
    RTTI_METHOD(GetFunctions);
    RTTI_METHOD(GetStaticFunctions);
    RTTI_METHOD(IsNative);
    RTTI_METHOD(IsAbstract);
});