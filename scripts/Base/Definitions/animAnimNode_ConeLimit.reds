public native class animAnimNode_ConeLimit extends animAnimNode_OnePoseInput {
  native let coneTransform: animTransformIndex;
  native let constrainedTransform: animTransformIndex;
  native let coneAxisLs: Vector3;
  native let coneAxisNormalizedLs: Vector3;
  native let coneOffsetMs: Vector3;
  native let coneOffsetMsLink: animVectorLink;
  native let limit1: Float;
  native let limit1Link: animFloatLink;
  native let limit1FloatTrack: animNamedTrackIndex;
  native let paraboloidRadius1: Float;
  native let limit2: Float;
  native let limit2Link: animFloatLink;
  native let limit2FloatTrack: animNamedTrackIndex;
  native let paraboloidRadius2: Float;
  native let limit3: Float;
  native let limit3Link: animFloatLink;
  native let limit3FloatTrack: animNamedTrackIndex;
  native let paraboloidRadius3: Float;
  native let limit4: Float;
  native let limit4Link: animFloatLink;
  native let limit4FloatTrack: animNamedTrackIndex;
  native let paraboloidRadius4: Float;
  native let coneLimitReached: animNamedTrackIndex;
  native let debug: Bool;
  native let colorfulCone: Bool;
  native let applyDebugConeScalling: Bool;
}
