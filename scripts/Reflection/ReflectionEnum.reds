
public native class ReflectionEnum extends ReflectionType {
    public native func GetConstants() -> array<ref<ReflectionConst>>
    public native func IsNative() -> Bool
}

public native class ReflectionConst {
    public native func GetName() -> CName
    public native func GetValue() -> Int64
}
