#include "Zenova.h"

#include "generated/initcpp.h"
#include "Dimension.h"

void (*boing_DimensionConstructor)(Dimension*, Level&, AutomaticID<Dimension, int>, short, Scheduler&, const std::string&);
void hook_DimensionConstructor(Dimension* self, Level& level, AutomaticID<Dimension, int> id, short height, Scheduler& scheduler, const std::string& name) {
	Zenova_Info("Loaded {} dimension with {} height", name, height);
	short modHeight = height;
	if (name == "Nether")
		modHeight += 128;
	boing_DimensionConstructor(self, level, id, modHeight, scheduler, name);
}

class AboveBedrockNetherBuilding : public Zenova::Mod {
	virtual void Start() {
		{
			Zenova_Info("Creating hook in the Dimension Constructor: {}", Zenova::Platform::CreateHook((void*)(Zenova::Hook::SlideAddress(0x17B1430)), &hook_DimensionConstructor, &boing_DimensionConstructor));
		}
	}
	virtual void Update() {}
	virtual void Tick() {}
	virtual void Stop() {}
	virtual ~AboveBedrockNetherBuilding() {}
};

MOD_FUNCTION Zenova::Mod* CreateMod() {
	return new AboveBedrockNetherBuilding;
}