public native struct gameActionEquipItemState {
  native let replicationId: Uint32;
  native let type: Uint16;
  native let startTimeStamp: netTime;
  native let stopTimeStamp: netTime;
  native let updateBucket: Uint8;
  native let slotId: TweakDBID;
  native let itemId: ItemID;
  native let animFeatureNameRight: CName;
  native let animFeatureNameLeft: CName;
  native let duration: Float;
  native let spawnDelay: Float;
}
