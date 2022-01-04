#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"
#include "Timer.h"

struct PhysVehicle3D;

#define MAX_ACCELERATION 1000.0f
#define TURN_DEGREES 15.0f * DEGTORAD
#define BRAKE_POWER 1000.0f
#define BACKING -700.0f

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void Respow();

public:

	PhysVehicle3D* vehicle;
	Timer clock;
	int state;
	float turn;
	float acceleration;
	float brake;

	float carx = 0, cary = 12, carz = 10;

//	VehicleInfo info;

};