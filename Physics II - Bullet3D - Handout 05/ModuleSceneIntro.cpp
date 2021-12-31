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
	CreateCubeMap({ 0,0,10 }, { 10,1,20 }, Blue);

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

	return UPDATE_CONTINUE;
}

//Create Cube for the Map
void ModuleSceneIntro::CreateCubeMap(const vec3 pos, const vec3 dim, Color color) {
	Cube* a;
	a = new Cube(dim.x, dim.y, dim.z);
	a->color = color;
	a->SetPos(pos.x, pos.y, pos.z);
	cubo.PushBack(a);
	cubo3d.PushBack(App->physics->AddBody(*a, 0.0f));
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

