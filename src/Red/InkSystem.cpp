#include "InkSystem.hpp"

Red::InkSystem* Red::InkSystem::Get()
{
    return Raw::inkSystem::Instance;
}

Red::InkLayerManager* Red::InkSystem::GetLayerManager()
{
    return layerManagers[0].instance;
}

Red::DynArray<Red::Handle<Red::inkLayer>>& Red::InkSystem::GetLayers()
{
    return layerManagers[0]->layers;
}