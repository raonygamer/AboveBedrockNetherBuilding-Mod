#pragma once
#include <string>

class SavedData {};
class BlockSourceListener : public SavedData {};
class LevelListener : public BlockSourceListener {};

class Level;
template<typename C, typename N>
class AutomaticID {};
class Scheduler;

class Dimension : public LevelListener {
public:
	Dimension(Level&, AutomaticID<Dimension, int>, short, Scheduler&, const std::string&);
};