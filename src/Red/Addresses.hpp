#pragma once

// Generated by cp77ida.py on 2023-04-14 for Cyberpunk 2077 v.1.62
// DO NOT MODIFY. USE tools\ida\scan.py TO GENERATE THIS FILE.

#include <cstdint>

namespace Red::Addresses
{
constexpr uintptr_t ImageBase = 0x140000000;

constexpr uintptr_t Main = 0x1401A0330 - ImageBase; // 40 53 48 81 EC ? ? ? ? FF 15 ? ? ? ? E8 ? ? ? ? E8 ? ? ? ?, expected: 1, index: 0
constexpr uintptr_t GetScriptGameInstance = 0x141407A30 - ImageBase; // 40 53 48 83 EC 40 48 FF 02 33 C9 48 8B 42 28 49 8B D8 48 85 C0 74, expected: 1, index: 0

constexpr uintptr_t CBaseEngine_InitEngine = 0x140A88DC0 - ImageBase; // 48 89 5C 24 10 55 56 41 56 48 8D 6C 24 B9 48 81 EC F0 00 00 00 4C 8B F2 48 8B F1 E8, expected: 1, index: 0

constexpr uintptr_t CGameFramework_InitializeGameInstance = 0x142A5EBF0 - ImageBase; // 48 89 5C 24 10 57 48 83 EC 20 48 8B F9 48 8B DA 0F B6 4A 32 E8 ? ? ? ? 0F B6 47 08 48 8D 54 24 30, expected: 1, index: 0

constexpr uintptr_t Entity_Attach = 0x141058B80 - ImageBase; // 48 89 5C 24 08 48 89 74 24 10 48 89 7C 24 18 4C 89 64 24 20 55 41 56 41 57 48 8B EC 48 81 EC 80 00 00 00 C6 81 56 01 00 00 03 4C 8B FA 80 7A 18 00, expected: 1, index: 0
constexpr uintptr_t Entity_Detach = 0x14105C180 - ImageBase; // 48 89 5C 24 10 48 89 74 24 18 57 48 83 EC 40 48 8B 81 B8 00 00 00 48 8B F1 C6 81 56 01 00 00 05, expected: 1, index: 0
constexpr uintptr_t Entity_Dispose = 0x14105C2F0 - ImageBase; // 40 56 48 83 EC 60 0F B6 81 56 01 00 00 48 8B F1 2C 02 3C 03 0F 87 ? ? ? ? 48 8B 89 B8 00 00 00, expected: 1, index: 0
constexpr uintptr_t Entity_GetComponents = 0x14105CAC0 - ImageBase; // 48 83 C1 70 E9, expected: 7, index: 1
constexpr uintptr_t Entity_Initialize = 0x14105DEC0 - ImageBase; // 48 89 54 24 10 55 53 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 B8 FB FF FF 48 81 EC 48 05 00 00, expected: 1, index: 0
constexpr uintptr_t Entity_OnAssemble = 0x141058440 - ImageBase; // 48 89 5C 24 08 57 48 81 EC 00 01 00 00 48 8B 02 48 8B FA 48 89 41 60 48 8B D9 48 8B 42 08 48 89 41 50, expected: 1, index: 0
constexpr uintptr_t Entity_Reassemble = 0x141058560 - ImageBase; // 40 55 53 56 57 41 54 41 55 41 56 41 57 48 8D 6C 24 88 48 81 EC 78 01 00 00 4C 8B EA 49 8B D9 48 8D 55 88, expected: 1, index: 0
constexpr uintptr_t Entity_Uninitialize = 0x141062F20 - ImageBase; // 48 89 5C 24 18 55 56 57 48 83 EC 50 48 8B F1 C6 81 56 01 00 00 06 48 81 C1 D8 00 00 00 E8, expected: 1, index: 0

constexpr uintptr_t InkLayer_RegisterListener = 0x14086B070 - ImageBase; // 48 89 5C 24 10 48 89 74 24 18 57 48 83 EC 40 48 8B F1 48 8B FA 48 81 C1 30 01 00 00 E8, expected: 2, index: 0
constexpr uintptr_t InkLayer_AttachWidgetTree = 0x14086BA90 - ImageBase; // 48 89 5C 24 10 48 89 74 24 20 55 57 41 56 48 8B EC 48 83 EC 70 4C 8B F1 49 8B D8 48 8D 4D 30, expected: 2, index: 1

constexpr uintptr_t InkLogicController_OnInitialize = 0x140988550 - ImageBase; // 48 89 5C 24 10 57 48 83 EC 40 48 83 79 70 00 48 8B D9 0F 84 ? ? ? ? 48 8B 41 48 0F 57 C0, expected: 1, index: 0
constexpr uintptr_t InkLogicController_OnUninitialize = 0x140988650 - ImageBase; // 48 89 5C 24 08 57 48 83 EC 30 80 3D ? ? ? ? ? 48 8B D9 48 BF A9 69 90 5E 8F CE E7 D3 75, expected: 1, index: 0
constexpr uintptr_t InkLogicController_OnArrangeChildrenComplete = 0x1409886C0 - ImageBase; // 40 53 48 83 EC 30 48 8B D9 E8 ? ? ? ? 48 8B C8 E8 ? ? ? ? 84 C0 75 ? 38 ? ? ? ? ? 48 89 7C 24 40 48 BF 34 F1 16 6B BE 7B 6A 4B, expected: 1, index: 0

constexpr uintptr_t InkSpawner_FinishAsyncSpawn = 0x1408E20A0 - ImageBase; // 48 89 5C 24 10 57 48 83 EC 30 48 8B 42 08 48 8B DA 4C 8B 0A 48 8B F9 4C 8B 41 18 4C 89 4C 24 20, expected: 1, index: 0

constexpr uintptr_t InkSystem_Instance = 0x1443145E8 - ImageBase; // BA ? ? 00 00 41 87 87 ? ? 00 00 4C 89 ? ? ? ? ? E8, expected: 1, index: 0, offset: 15
constexpr uintptr_t InkSystem_ProcessCharacterEvent = 0x1409C9AD0 - ImageBase; // 48 89 5C 24 20 55 56 41 57 48 8B EC 48 83 EC 70 48 8B 81 B8 02 00 00 0F 57 C0 45 8B F8 8B DA 4C 8B C9, expected: 1, index: 0

constexpr uintptr_t InkWidget_GetLayer = 0x140964670 - ImageBase; // 48 8B C4 55 41 57 48 8D 68 A1 48 81 EC A8 00 00 00 48 83 B9 48 01 00 00 00 4C 8B FA 4C 89 70 D8, expected: 1, index: 0
constexpr uintptr_t InkWidget_SetLayer = 0x14096E040 - ImageBase; // 48 89 5C 24 08 57 48 83 EC 30 48 8B F9 48 81 C1 48 01 00 00 E8 ? ? ? ? 48 8D 8F F5 01 00 00 E8, expected: 1, index: 0
constexpr uintptr_t InkWidget_ScriptReparent = 0x140971820 - ImageBase; // 48 89 5C 24 08 48 89 6C 24 18 56 57 41 56 48 83 EC 50 48 8B 02 4C 8D 35 ? ? ? ? FE 42 62 33 ED 0F 57 C0 48 89 6A 30 F3 0F 7F 44 24 38, expected: 1, index: 0
constexpr uintptr_t InkWidget_ScriptAddChild = 0x140809D90 - ImageBase; // 48 89 5C 24 08 57 48 83 EC 40 FE 42 62 4C 8D 15 ? ? ? ? 33 C0 0F 57 C0 48 89 42 30 48 8B F9 48 8B 4A 40 45 33 C9 48 89 42 38 48 8B DA, expected: 17, index: 0
constexpr uintptr_t InkWidget_TriggerEvent = 0x14095C670 - ImageBase; // 48 89 5C 24 08 57 48 83 EC 40 49 8B F8 E8 ? ? ? ? 48 85 C0 0F 84 ? ? ? ? 48 8B 0F 48 89 4C 24 20 48 8B 4F 08 48 89 4C 24 28 48 85 C9, expected: 2, index: 1

constexpr uintptr_t InkWidgetLibrary_AsyncSpawnFromExternal = 0x14099C070 - ImageBase; // 48 89 5C 24 08 57 48 83 EC 40 48 8B FA 49 8B D9 48 8D 54 24 28 E8 ? ? ? ? 48 8B 4C 24 28 48 85 C9 74 ? 48 8B D3 E8, expected: 2, index: 0
constexpr uintptr_t InkWidgetLibrary_AsyncSpawnFromLocal = 0x14099C150 - ImageBase; // 48 89 5C 24 08 57 48 83 EC 20 48 8B FA 41 0F B6 D9 49 8B D0 E8 ? ? ? ? 48 85 C0 74, expected: 1, index: 0
constexpr uintptr_t InkWidgetLibrary_SpawnFromExternal = 0x14099D080 - ImageBase; // 48 89 5C 24 08 57 48 83 EC 40 48 8B FA 49 8B D9 48 8D 54 24 28 E8 ? ? ? ? 48 8B 4C 24 28 48 85 C9 74 ? 48 8B D3 E8, expected: 2, index: 1
constexpr uintptr_t InkWidgetLibrary_SpawnFromLocal = 0x14099D170 - ImageBase; // 40 53 48 83 EC 20 48 8B DA 49 8B D0 E8 ? ? ? ? 48 85 C0 74 ? 48 8B  D3 48 8B C8 E8, expected: 2, index: 1

constexpr uintptr_t IScriptable_InitializeScriptData = 0x1401EE4B0 - ImageBase; // 48 89 51 30 4C 89 41 38 C3, expected: 1, index: 0

constexpr uintptr_t NodeRef_Create = 0x140B69380 - ImageBase; // 48 89 5C 24 08 48 89 74 24 10 48 89 7C 24 18 4C 89 64 24 20 55 41 56 41 57 48 8B EC 48 83 EC 70 8B 7A 08 33 DB 45 0F B6 E0 4C 8B F1 85 FF, expected: 1, index: 0

constexpr uintptr_t PersistentObject_InitializeState = 0x14146FA50 - ImageBase; // 40 55 53 56 41 56 41 57 48 8D 6C 24 C9 48 81 EC ? ? ? ? 4C 8B F2 33 DB 48 8B 52 10 48 8B F1, expected: 1, index: 0

constexpr uintptr_t PlayerSystem_OnPlayerSpawned = 0x142730170 - ImageBase; // 48 8B C4 4C 89 48 20 55 56 57 48 8B EC 48 81 EC 80 00 00 00, expected: 1, index: 0

constexpr uintptr_t ScriptBundle_dtor = 0x14027E1B0 - ImageBase; // 48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 20 48 8B D9 E8 ? ? ? ? 48 8D 8B 38 01 00 00, expected: 1, index: 0

constexpr uintptr_t ScriptValidator_CompareTypeName = 0x140281340 - ImageBase; // 48 89 5C 24 10 57 48 83 EC 20 48 8B DA 48 8B F9 48 3B CA 74 ? E8 ? ? ? ? 4C 8B C7, expected: 1, index: 0

constexpr uintptr_t VehicleSystem_ToggleGarageVehicle = 0x141D00530 - ImageBase; // 48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 48 83 EC 20 48 8B F9 41 0F B6 F0 48 81 C1 ? ? ? ? 48 8B EA E8, expected: 1, index: 0
}
