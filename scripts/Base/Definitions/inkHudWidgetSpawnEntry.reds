public native struct inkHudWidgetSpawnEntry {
  native let hudEntryName: CName;
  native let enabled: Bool;
  native let spawnMode: inkSpawnMode;
  native let widgetResource: ResourceRef; // rRef<inkWidgetLibraryResource>
  native let anchorPlace: inkEAnchor;
  native let anchorPoint: Vector2;
  native let margins: inkMargin;
  native let attachToSlot: Bool;
  native let slotParams: inkWidgetSlotAttachmentParams;
  native let useSeparateWindow: Bool;
  native let ignoreHudSafezones: Bool;
  native let affectedByGlitchEffect: Bool;
  native let affectedByBlackwallEffect: Bool;
  native let spawnBeforeSlots: Bool;
  native let ignoreHudScaleOverride: Bool;
  native let hudScalingInterpolationValue: Float;
  native let hudScalingMarginCorrection: inkMargin;
}
