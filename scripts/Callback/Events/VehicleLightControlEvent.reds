public native class VehicleLightControlEvent extends EntityLifecycleEvent {
    public native func IsEnabled() -> Bool
    public native func GetLightType() -> vehicleELightType
    public native func IsLightType(lightType: vehicleELightType) -> Bool
}