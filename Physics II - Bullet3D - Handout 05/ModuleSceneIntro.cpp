#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));
	CreateRamp({ 0,0,0 }, { 10,1,20 }, 20, {0,0,1}, Blue);
	CreateCubeMap({ 0,0,0 }, { 10,1,20 }, Blue);

	CreateCubeMap({ 130,0,-70 }, { 30,1,10 }, Red);
	CreateCubeMap({ 130,0,-60 }, { 30,1,10 }, White);
	CreateCubeMap({ 130,0,-50 }, { 30,1,10 }, Green);
	CreateCubeMap({ 130,0,-40 }, { 30,1,10 }, Blue);
	CreateCubeMap({ 130,0,-30 }, { 30,1,10 }, Red);
	CreateCubeMap({ 130,0,-20 }, { 30,1,10 }, White);
	CreateCubeMap({ 130,0,-10 }, { 30,1,10 }, Green);

	CreateCubeMap({ 130,0,0 }, { 30,1,10 }, Blue);
	CreateCubeMap({ 130,0,10 }, { 30,1,10 }, Red);
	CreateCubeMap({ 130,0,20 }, { 30,1,10 }, White);
	CreateCubeMap({ 130,0,30 }, { 30,1,10 }, Green);
	CreateCubeMap({ 130,0,40 }, { 30,1,10 }, Blue);
	CreateCubeMap({ 130,0,50 }, { 30,1,10 }, Red);
	CreateCubeMap({ 130,0,60 }, { 30,1,10 }, White);
	CreateCubeMap({ 130,0,70 }, { 30,1,10 }, Green);
	CreateCubeMap({ 130,0,80 }, { 30,1,10 }, Blue);
	CreateCubeMap({ 130,0,90 }, { 30,1,10 }, Red);
	CreateCubeMap({ 130,0,100 }, { 30,1,10 }, White);
	CreateCubeMap({ 130,0,110 }, { 30,1,10 }, Green);
	CreateCubeMap({ 130,0,120 }, { 30,1,10 }, Blue);
	CreateCubeMap({ 130,0,130 }, { 30,1,10 }, Red);
	CreateCubeMap({ 130,0,140 }, { 30,1,10 }, White);
	CreateCubeMap({ 130,0,155 }, { 30,1,30 }, Green);

	CreateCubeMap({ 110,0,155 }, { 10,1,30 }, Blue);
	CreateCubeMap({ 100,0,155 }, { 10,1,30 }, Red);
	CreateCubeMap({ 90,0,155 }, { 10,1,30 }, White);
	CreateCubeMap({ 80,0,155 }, { 10,1,30 }, Blue);
	CreateCubeMap({ 70,0,155 }, { 10,1,30 }, Red);
	CreateCubeMap({ 60,0,155 }, { 10,1,30 }, White);
	CreateCubeMap({ 50,0,155 }, { 10,1,30 }, Green);
	CreateCubeMap({ 40,0,155 }, { 10,1,30 }, Blue);
	CreateCubeMap({ 30,0,155 }, { 10,1,30 }, Red);
	CreateCubeMap({ 20,0,155 }, { 10,1,30 }, White);
	CreateCubeMap({ 10,0,155 }, { 10,1,30 }, Green);
	CreateCubeMap({ 0,0,155 }, { 10,1,30 }, Blue);
	CreateCubeMap({ -10,0,155 }, { 10,1,30 }, Red);
	CreateCubeMap({ -20,0,155 }, { 10,1,30 }, White);
	CreateCubeMap({ -30,0,155 }, { 10,1,30 }, Green);
	CreateCubeMap({ -40,0,155 }, { 10,1,30 }, Blue);
	CreateCubeMap({ -50,0,155 }, { 10,1,30 }, Red);
	CreateCubeMap({ -60,0,155 }, { 10,1,30 }, White);
	CreateCubeMap({ -70,0,155 }, { 10,1,30 }, Green);
	CreateCubeMap({ -80,0,155 }, { 10,1,30 }, Blue);
	CreateCubeMap({ -90,0,155 }, { 10,1,30 }, Red);
	CreateCubeMap({ -100,0,155 }, { 10,1,30 }, White);
	CreateCubeMap({ -120,0,155 }, { 30,1,30 }, Green);

	CreateCubeMap({ -120,0,135 }, { 30,1,10 }, Blue);
	CreateCubeMap({ -120,0,125 }, { 30,1,10 }, Red);
	CreateCubeMap({ -120,0,115 }, { 30,1,10 }, White);
	CreateCubeMap({ -120,0,105 }, { 30,1,10 }, Green);
	CreateRamp({ -120,4,80 }, { 30,1,50 }, 10, { 1,0,0 }, Blue);
	CreateCubeMap({ -120,8.3,40.5 }, { 30,1,30 }, Red);

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	for (int i = 0; i < map.cubo.Count(); i++) {
		map.cubo[i].Render();
	}

	return UPDATE_CONTINUE;
}

//Create Cube for the Map
void ModuleSceneIntro::CreateCubeMap(const vec3 pos, const vec3 dim, Color color) {
	Cube* a;
	a = new Cube(dim.x, dim.y, dim.z);
	a->color = color;
	a->SetPos(pos.x, pos.y, pos.z);
	map.cubo.PushBack(*a);
	map.cubo3d.PushBack(App->physics->AddBody(*a, 0.0f));
}

void ModuleSceneIntro::CreateRamp(const vec3 pos, const vec3 dim, float angle,const vec3& orient, Color color) {
	Cube* a;
	a = new Cube(dim.x, dim.y, dim.z);
	a->color = color;
	a->SetPos(pos.x, pos.y, pos.z);
	a->SetRotation(angle, orient);
	map.cubo.PushBack(*a);
	map.cubo3d.PushBack(App->physics->AddBody(*a, 0.0f));
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

