public native struct worldAdvertisementLightData {
  native let transform: Transform;
  native let isEnabled: Bool;
  native let lightName: CName;
  native let useAutoHideDistance: Bool;
  native let autoHideDistance: Float;
  native let type: ELightType;
  native let color: Color;
  native let radius: Float;
  native let unit: ELightUnit;
  native let intensity: Float;
  native let EV: Float;
  native let temperature: Float;
  native let sceneDiffuse: Bool;
  native let sceneSpecularScale: Uint8;
  native let directional: Bool;
  native let roughnessBias: Int8;
  native let scaleGI: Uint8;
  native let scaleEnvProbes: Uint8;
  native let useInTransparents: Bool;
  native let scaleVolFog: Uint8;
  native let useInParticles: Bool;
  native let attenuation: rendLightAttenuation;
  native let clampAttenuation: Bool;
  native let group: rendLightGroup;
  native let areaShape: EAreaLightShape;
  native let areaTwoSided: Bool;
  native let spotCapsule: Bool;
  native let sourceRadius: Float;
  native let capsuleLength: Float;
  native let areaRectSideA: Float;
  native let areaRectSideB: Float;
  native let innerAngle: Float;
  native let outerAngle: Float;
  native let softness: Float;
  native let enableLocalShadows: Bool;
  native let enableLocalShadowsForceStaticsOnly: Bool;
  native let contactShadows: rendContactShadowReciever;
  native let shadowAngle: Float;
  native let shadowRadius: Float;
  native let shadowFadeDistance: Float;
  native let shadowFadeRange: Float;
  native let shadowSoftnessMode: ELightShadowSoftnessMode;
  native let rayTracedShadowsPlatform: rendRayTracedShadowsPlatform;
  native let rayTracingLightSourceRadius: Float;
  native let rayTracingContactShadowRange: Float;
  native let iesProfile: ResourceAsyncRef; // raRef<CIESDataResource>
  native let flicker: rendSLightFlickering;
  native let envColorGroup: EEnvColorGroup;
  native let colorGroupSaturation: Uint8;
  native let portalAngleCutoff: Uint8;
  native let allowDistantLight: Bool;
  native let rayTracingIntensityScale: Float;
  native let pathTracingLightUsage: rendEPathTracingLightUsage;
  native let pathTracingOverrideScaleGI: Bool;
  native let rtxdiShadowStartingDistance: Float;
}
