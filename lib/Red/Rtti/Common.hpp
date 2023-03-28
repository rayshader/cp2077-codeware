#pragma once

namespace Red
{
struct Scope
{
    constexpr Scope(const std::source_location& aLocation = std::source_location::current()) noexcept
        : hash(FNV1a64(aLocation.file_name(), aLocation.line()))
    {
    }

    constexpr Scope(const char* aName) noexcept
        : hash(FNV1a64(aName))
    {
    }

    constexpr Scope(uint64_t aHash) noexcept
        : hash(aHash)
    {
    }

    // template<template<typename> class B, typename T>
    // constexpr Scope(const B<T>&) noexcept
    //     : hash(FNV1a64(nameof::nameof_type<T>().data()))
    // {
    // }
    //
    // template<template<typename, auto> class E, typename T, auto S>
    // constexpr Scope(const E<T, S>&) noexcept
    //     : hash(S)
    // {
    // }
    //
    // template<template<auto, typename...> class E, auto S, typename... P>
    // constexpr Scope(const E<S, P...>&) noexcept
    //     : hash(S)
    // {
    // }

    constexpr operator uint64_t() const noexcept
    {
        return hash;
    }

    constexpr static Scope Unique(const std::source_location& aLocation = std::source_location::current()) noexcept
    {
        return {aLocation};
    }

    template<typename T>
    constexpr static Scope From()
    {
        return FNV1a64(nameof::nameof_type<T>().data());
    }

    template<typename T, auto S>
    constexpr static Scope From()
    {
        return S;
    }

    uint64_t hash;
};

template<typename T, auto V = 0>
struct Optional;

namespace Detail
{
template<typename T>
concept IsScriptable = std::is_base_of_v<IScriptable, T>;

template<typename T>
concept IsType = std::is_base_of_v<CBaseRTTIType, T>;

template<typename T>
concept IsTypeOrVoid = IsType<T> or std::is_void_v<T>;

template<typename F>
struct PropertyPtr : public std::false_type {};

template<typename C, typename P>
struct PropertyPtr<P C::*> : public std::true_type
{
    using context_type = C;
    using value_type = P;
};

template<typename T>
concept IsPropertyPtr = PropertyPtr<T>::value;

template<typename F>
struct FunctionPtr : public std::false_type {};

template<typename R, typename... Args>
struct FunctionPtr<R (*)(Args...)> : public std::true_type
{
    using context_type = void;
    using return_type = R;

    using arguments_type = std::tuple<std::remove_const_t<std::remove_reference_t<Args>>...>;
    using qualified_arguments_type = std::tuple<Args...>;
    using extended_arguments_type = arguments_type;

    template<size_t I>
    using argument_type = typename std::tuple_element<I, arguments_type>::type;

    template<size_t I>
    using qualified_argument_type = typename std::tuple_element<I, qualified_arguments_type>::type;

    template<size_t I>
    using extended_argument_type = typename std::tuple_element<I, extended_arguments_type>::type;

    static constexpr size_t arity = sizeof...(Args);
};

template<typename C, typename R, typename... Args>
struct FunctionPtr<R (C::*)(Args...)> : FunctionPtr<R (*)(Args...)>
{
    using context_type = C;
    using extended_arguments_type = std::tuple<C*, std::remove_const_t<std::remove_reference_t<Args>>...>;
};

template<typename C, typename R, typename... Args>
struct FunctionPtr<R (C::*)(Args...) const> : FunctionPtr<R (C::*)(Args...)> {};

template<typename R, typename... Args>
struct FunctionPtr<R (Args...)> : FunctionPtr<R (*)(Args...)> {};

template<typename T>
concept IsFunctionPtr = FunctionPtr<T>::value;

template<typename T>
concept IsStaticFunctionPtr = FunctionPtr<T>::value && std::is_void_v<typename FunctionPtr<T>::context_type>;

template<typename T>
concept IsMemberFunctionPtr = FunctionPtr<T>::value && !std::is_void_v<typename FunctionPtr<T>::context_type>;

template<typename T>
struct Specialization : public std::false_type {};

template<template<typename> class G, typename A>
struct Specialization<G<A>> : public std::true_type
{
    using argument_type = A;
};

template<template<typename, typename...> class G, typename A, typename... Args>
struct Specialization<G<A, Args...>> : public std::true_type
{
    using argument_type = A;
};

template<template<typename, auto> class G, typename A, auto V>
struct Specialization<G<A, V>> : public std::true_type
{
    using argument_type = A;
    static constexpr auto argument_value = V;
};

template<typename T>
concept IsSpecialization = Specialization<T>::value;

template<typename T, typename U = std::remove_cvref_t<T>>
concept IsOptional = Specialization<U>::value
    && std::is_same_v<U, Red::Optional<typename Specialization<U>::argument_type, Specialization<U>::argument_value>>;
}

template<typename T, auto ADefault>
requires (!std::is_void_v<T>)
struct Optional<T, ADefault>
{
    inline operator const T&() const
    {
        return value;
    }

    [[nodiscard]] inline const T* operator->() const
    {
        return &value;
    }

    [[nodiscard]] bool IsEmpty() const
    {
        return !value;
    }

    [[nodiscard]] bool IsDefault() const
    {
        return value == ADefault;
    }

    T value{ADefault};
};

template<typename T>
struct Optional<T, 0>
{
    inline operator const T&() const
    {
        return value;
    }

    [[nodiscard]] inline const T* operator->() const
    {
        return &value;
    }

    [[nodiscard]] bool IsEmpty() const
    {
        return !value;
    }

    T value{};
};
}
